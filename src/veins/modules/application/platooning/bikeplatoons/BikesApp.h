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

#ifndef BIKESAPP_H_
#define BIKESAPP_H_

#include "veins/modules/application/platooning/apps/BaseApp.h"

#include "veins/modules/application/platooning/messages/BikesMessage_m.h"

//define types
#define _CAR 0
#define _BIKE 1

class BikesApp : public BaseApp
{

	protected:
		//define the roles
		enum ROLES {LEADER, FOLLOWER, LEAVER, BIKE};
		//data that each car needs to keep
		struct VEHICLE_DATA {
			int					platoonId;	//id of the platoon
			int					leaderId;	//leader of the platoon
			int					frontId;	//id of the vehicle in front
			double				speed;		//speed of the platoon
			int					lane;		//index of the lane the platoon is travelling in
            int                 leaverId;   //the id of the vehicle leaving the platoon
            int                 isBlinking; //see if i'm turning -> will become a leaver!
			std::vector<int>	formation;	//list of vehicles in the platoon
		};

		//define the states for each role
		typedef enum _LEADER_STATES {
			LS_INIT = 0,
			LS_LEADING = FSM_Steady(1) //being a good leader
		} LEADER_STATES;

        typedef enum _FOLLOWER_STATES {
            FS_INIT = 0,
            FS_FOLLOW = FSM_Steady(1), //normal following
            FS_FRONT_LEAVING = FSM_Steady(2) //the front car is now a leaver: notify bikes and get new front car
        } FOLLOWER_STATES;

        typedef enum _LEAVER_STATES {
            LVS_INIT = 0,
            LVS_IDLE = FSM_Steady(1), //still in platoon
            LVS_LEAVE_PLATOON = FSM_Steady(3) //not in the platoon anymore!
        } LEAVER_STATES;

        typedef enum _BIKE_STATES {
            BS_INIT = 0,
            BS_IDLE = FMS_Steady(1),//normal riding
            BS_STOP = FSM_Steady(2) //received a signal to stop from a follower vehicle
        } BIKE_STATES;


		//define the messages that can be sent by each role
		enum LEADER_MSGS {
			LM_BECOME_LEAVER = 1,
		};
		enum FOLLOWER_MSGS {
			FM_BECOME_LEAVER = 2,
			FM_BECOME_LEADER = 3,
			FM_NOTIFY_BIKE = 4,
			FM_FIX_FORMATION = 5
		};
        enum LEAVER_MSGS {
            LLM_IN_PLATOON = 6,
            LLM_NOTIFY_LEAVE = 7
        };
        enum BIKE_MSGS {
            //nothing yet!
        };

        //my vehicle type
        int myType;
		//the state machine handler
		cFSM leaderFsm, followerFsm, leaverFsm, bikeFsm;
		//the role of this vehicle
		JOIN_ROLE role;
		//the position of this vehicle in the platoon
		int position;
		//data known by the vehicle
		struct VEHICLE_DATA vehicleData;
		//message used to start the maneuver
		cMessage *startManeuver;

	public:

		virtual void initialize(int stage);
		virtual void finish();

	protected:
		virtual void onBeacon(WaveShortMessage* wsm);
		virtual void onData(WaveShortMessage* wsm);

	private:

	public:
		BikesApp()	{
			startManeuver = 0;
		}

    protected:

        virtual void handleSelfMsg(cMessage *msg);
        //override this method of BaseApp. we want to handle it ourself
        virtual void handleLowerMsg(cMessage *msg);
        virtual void handleLowerControl(cMessage *msg);

        ManeuverMessage *generateMessage();

        void handleLeaderMsg(cMessage *msg);
        void handleJoinerMsg(cMessage *msg);
        void handleLeaverMsg(cMessage *msg);
        void handleFollowerMsg(cMessage *msg);
        void handleBikeMsg(cMessage *msg);

        void prepareManeuverCars(int platoonLane);
        void receiveMessage(cMessage *msg);

};

#endif /* BIKESAPP_H_ */
