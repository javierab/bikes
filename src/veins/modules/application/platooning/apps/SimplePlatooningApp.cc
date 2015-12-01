//
// Copright (c) 2012-2015 Michele Segata <segata@ccs-labs.org>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "veins/modules/application/platooning/apps/SimplePlatooningApp.h"

#include "crng.h"
#include "veins/modules/messages/WaveShortMessage_m.h"
#include "veins/base/messages/MacPkt_m.h"
#include "veins/modules/mac/ieee80211p/Mac1609_4.h"

#include "veins/modules/application/platooning/protocols/BaseProtocol.h"

Define_Module(SimplePlatooningApp);

void SimplePlatooningApp::initialize(int stage) {

	BaseApp::initialize(stage);

	if (stage == 1) {

		//get the oscillation frequency of the leader as parameter
		leaderOscillationFrequency = par("leaderOscillationFrequency").doubleValue();

		//should the follower use ACC or CACC?
		const char *strController = par("controller").stringValue();
		//for now we have only two possibilities
		if (strcmp(strController, "ACC") == 0) {
			controller = Plexe::ACC;
		}
		else if (strcmp(strController, "CACC") == 0) {
			controller = Plexe::CACC;
		}
		else {
			controller = Plexe::PLOEG;
		}
		//headway time for ACC
		accHeadway = par("accHeadway").doubleValue();
		//leader speed
		leaderSpeed = par("leaderSpeed").doubleValue();

		if (myId == 0) {
			//ACC speed is 100 km/h
			traciVehicle->setCruiseControlDesiredSpeed(leaderSpeed / 3.6);
			//leader uses the ACC
			traciVehicle->setActiveController(Plexe::ACC);
			//leader speed must oscillate
			changeSpeed = new cMessage();
			scheduleAt(simTime() + SimTime(0.1), changeSpeed);
		}
		else {
			//followers speed is higher
			traciVehicle->setCruiseControlDesiredSpeed((leaderSpeed + 30) / 3.6);
			//followers use controller specified by the user
			traciVehicle->setActiveController(controller);
			//use headway time specified by the user (if ACC is employed)
			traciVehicle->setACCHeadwayTime(accHeadway);

			changeSpeed = 0;
		}
		//every car must run on first lane
		traciVehicle->setFixedLane(0);

	}

}

void SimplePlatooningApp::finish() {
	BaseApp::finish();
	if (changeSpeed) {
		cancelAndDelete(changeSpeed);
		changeSpeed = 0;
	}
}

void SimplePlatooningApp::onData(WaveShortMessage *wsm) {
}

void SimplePlatooningApp::handleSelfMsg(cMessage *msg) {
	//this takes car of feeding data into CACC and reschedule the self message
	BaseApp::handleSelfMsg(msg);

	if (msg == changeSpeed && myId == 0) {
		//make leader speed oscillate
		traciVehicle->setCruiseControlDesiredSpeed((leaderSpeed + 10 * sin(2 * M_PI * simTime().dbl() * leaderOscillationFrequency)) / 3.6);
		scheduleAt(simTime() + SimTime(0.1), changeSpeed);
	}

}

void SimplePlatooningApp::onBeacon(WaveShortMessage* wsm) {
}
