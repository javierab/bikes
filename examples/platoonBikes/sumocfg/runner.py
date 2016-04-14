#!/usr/bin/env python
# -*- coding: utf8 -*-
"""
Prueba de ruteo y detencion
"""
import os
import sys
import subprocess


if 'SUMO_HOME' in os.environ:
    tools = os.path.join(os.environ['SUMO_HOME'], 'tools')
    sys.path.append(tools)
else:
    sys.exit("please declare environment variable 'SUMO_HOME'")

import time
import math
import traci
import traci.constants as tc
from signal import signal, SIGPIPE, SIG_DFL

####################################################
# Levanta SUMO
####################################################
base = os.path.dirname(sys.argv[0])

guisimBinary = "sumo-gui"
if os.name != "posix":
    guisimBinary += ".exe"
if os.path.exists(os.path.join(base, guisimBinary)):
    guisimPath = os.path.join(base, guisimBinary)
else:
    guisimPath = os.environ.get("GUISIM_BINARY", os.path.join(
        base, '..', '..', 'bin', guisimBinary))
if not os.path.exists(guisimPath):
    guisimPath = guisimBinary

PORT = 7890

ret = subprocess.Popen(
    [guisimPath, "-c", "cross.sumocfg", "--remote-port", str(PORT)])
time.sleep(2)
####################################################
# Inicia Control
####################################################


traci.init(PORT)
print("started!")


traci.simulation.subscribe(
    (traci.constants.VAR_LOADED_VEHICLES_IDS, traci.constants.VAR_DEPARTED_VEHICLES_IDS))
signal(SIGPIPE, SIG_DFL)

# valores fijos para el escenario!
maxstep = 100000
junction_id = "cluster_0__0_0__2_0__4_0__6"
desacel_dist = 30.0


# buscamos a los vehiculos que doblan (turn_*)
# cuando la distancia a la intersección (junction) es menor a 40 (arbitrario) guardamos su aceleración normal y seteamos desaceleración.
# cuando la distancia es menor a 1 (practicamente doblando!) volvemos a su
# aceleración normal.

step = 0
junc_x = 0.0
junc_y = 0.0
last_dist = dict()
orig_speed = dict()

if junction_id in traci.junction.getIDList():
    junc_x, junc_y = traci.junction.getPosition(junction_id)
else:
    print "ERROR: junction no encontrada!"
    step = maxstep

while step < maxstep:
    step += 1
    #print('step %d' % step)
    traci.simulationStep()
    moveNodes = []
    for veh, subs in traci.vehicle.getSubscriptionResults().iteritems():
        moveNodes.append(
            (veh, subs[tc.VAR_ROAD_ID], subs[tc.VAR_LANEPOSITION]))

    departed = traci.simulation.getSubscriptionResults()[
        tc.VAR_DEPARTED_VEHICLES_IDS]
    for v in departed:
        traci.vehicle.subscribe(v)
        subs = traci.vehicle.getSubscriptionResults(v)
        moveNodes.append((v, subs[tc.VAR_ROAD_ID], subs[tc.VAR_LANEPOSITION]))

    for vehicleID, edge, pos in moveNodes:

        # vemos si es primera vez que lo veo y registro su info
        if vehicleID not in last_dist:
            orig_speed[vehicleID] = traci.vehicle.getSpeed(vehicleID)
            last_dist[vehicleID] = 1000000  # big enough

        # calculo distancia
        veh_x, veh_y = traci.vehicle.getPosition(vehicleID)
        dist = math.sqrt((veh_x - junc_x)**2 + (veh_y - junc_y)**2)
        current = traci.vehicle.getSpeed(vehicleID)
        if vehicleID.startswith("turn"):

            mode = ""
            # print "turn: ", vehicleID

            # vemos si me estoy acercando o alejando
            if last_dist[vehicleID] < dist:
                mode = "acc"
            else:
                mode = "desacc"
            # print "mode: ", mode

            # si me acerco freno, si me alejo acelero
            if dist < desacel_dist and current > 2.5 and mode == "desacc":
                traci.vehicle.setSpeed(vehicleID, current - 1)
            elif dist < desacel_dist and current < orig_speed and mode == "acc":
                traci.vehicle.setSpeed(vehicleID, current + 1.5)
            # actualizo distancia
            last_dist[vehicleID] = dist


traci.close()
