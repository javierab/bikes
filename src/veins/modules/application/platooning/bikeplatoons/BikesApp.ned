package org.car2x.veins.modules.application.platooning.bikeplatoons;

import org.car2x.veins.modules.application.platooning.apps.BaseApp;

simple BikesApp like BaseApp
{
    parameters:
        int headerLength @unit("bit") = default(0 bit);
        //number of lanes in the higway
        int nLanes = default(1);
        //send actual or controller-computed acceleration
        bool useControllerAcceleration = default(true);
        //cacc and engine related parameters
        double caccXi;
        double caccOmegaN @unit("Hz");
        double caccC1;
        double engineTau @unit("s");
        double ploegH @unit("s") = default(0.5 s);
        double ploegKp = default(0.2);
        double ploegKd = default(0.7);

        @display("i=block/app2");
        @class(BikesApp);
    gates:
        input lowerLayerIn;
        output lowerLayerOut;
        input lowerControlIn;
        output lowerControlOut;
}
