import org.car2x.veins.base.modules.IBaseApplLayer;
import org.car2x.veins.modules.application.platooning.protocols.BaseProtocol;
import org.car2x.veins.modules.application.platooning.UnicastProtocol;
import org.car2x.veins.modules.mobility.traci.TraCIMobility;
import org.car2x.veins.modules.nic.Nic80211p;


module Vehicle
{
    parameters:
        string appl_type;
        string protocol_type;

    gates:
        input radioIn; // gate for sendDirect
    submodules:

        appl: <appl_type> like IBaseApplLayer {
            parameters:
                @display("p=60,100");
        }

        prot: <protocol_type> like BaseProtocol {
            parameters:
                @display("p=60,200");
        }

        unicast: UnicastProtocol {
            parameters:
                @display("p=60,300");
        }

        nic: Nic80211p {
            parameters:
                @display("p=60,400");
        }

        mobility: TraCIMobility {
            parameters:
                @display("p=130,172;i=block/cogwheel");
        }
    connections allowunconnected:
        prot.upperLayerIn <-- appl.lowerLayerOut;
        prot.upperLayerOut --> appl.lowerLayerIn;
        appl.lowerControlOut --> prot.upperControlIn;
        appl.lowerControlIn <-- prot.upperControlOut;
        unicast.upperControlIn <-- prot.lowerControlOut;
        unicast.upperControlOut --> prot.lowerControlIn;
        unicast.upperLayerIn <-- prot.lowerLayerOut;
        unicast.upperLayerOut --> prot.lowerLayerIn;
        nic.upperLayerIn <-- unicast.lowerLayerOut;
        nic.upperLayerOut --> unicast.lowerLayerIn;

        radioIn --> nic.radioIn;

}
