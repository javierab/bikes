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

#ifndef JOINMANEUVERAPP_H_
#define JOINMANEUVERAPP_H_

#include "veins/modules/application/platooning/apps/BaseApp.h"

#include "veins/modules/application/platooning/messages/ManeuverMessage_m.h"

class JoinManeuverApp : public BaseApp
{

	protected:
		//define the roles
		enum JOIN_ROLE {LEADER, FOLLOWER, JOINER};
		//data that each car needs to keep
		struct VEHICLE_DATA {
			int					platoonId;	//id of the platoon
			int					leaderId;	//leader of the platoon
			int					frontId;	//id of the vehicle in front
			double				speed;		//speed of the platoon
			int					lane;		//index of the lane the platoon is travelling in
			int					joinLane;	//the lane chosen for joining the platoon
			int					joinerId;	//the id of the vehicle joining the platoon
			std::vector<int>	formation;	//list of vehicles in the platoon
		};
		//define the states for each role
		typedef enum _LEADER_STATES {
			LS_INIT = 0,
			LS_LEADING = FSM_Steady(1),
			LS_WAIT_JOINER_IN_POSITION = FSM_Steady(2),
			LS_WAIT_JOINER_TO_JOIN = FSM_Steady(3)
		} LEADER_STATES;
		typedef enum _JOINER_STATES {
			JS_INIT = 0,
			JS_IDLE = FSM_Steady(1),
			JS_WAIT_REPLY = FSM_Steady(2),
			JS_MOVE_IN_POSITION = FSM_Steady(3),
			JS_WAIT_JOIN = FSM_Steady(4),
			JS_JOIN_PLATOON = FSM_Steady(5),
			JS_FOLLOW = FSM_Steady(6)
		} JOINER_STATES;
		typedef enum _FOLLOWER_STATES {
			FS_INIT = 0,
			FS_FOLLOW = FSM_Steady(1)
		} FOLLOWER_STATES;
		//define the messages that can be sent by each role
		enum LEADER_MSGS {
			LM_MOVE_IN_POSITION = 0,
			LM_JOIN_PLATOON = 1,
			LM_UPDATE_FORMATION = 2,
			LM_INCREASE_SPACING = 3
		};
		enum JOINER_MSGS {
			JM_REQUEST_JOIN = 3,
			JM_IN_POSITION = 4,
			JM_IN_PLATOON = 5
		};

		//the state machine handler
		cFSM leaderFsm, joinerFsm, followerFsm;
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
		JoinManeuverApp()	{
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
		void handleFollowerMsg(cMessage *msg);

		void prepareManeuverCars(int platoonLane);
		void receiveMessage(cMessage *msg);

};

#endif /* JOINMANEUVERAPP_H_ */
