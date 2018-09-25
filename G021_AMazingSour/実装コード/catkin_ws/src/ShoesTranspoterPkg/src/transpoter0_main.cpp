#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "shoes_transpoter/shoes_transpoter.hpp"
#define SHOES_TRANSPOTER_ID 0
#define SHOES_TRANSPOTER_NODE_NAME "shoes_transpoter_0"

static ShoesTranspoter test_move = ShoesTranspoter(SHOES_TRANSPOTER_ID);

void operationCallback(const ShoesTranspoterPkg::operation_msg& msg);

int main(int argc, char** argv)
{
        ros::init(argc, argv, SHOES_TRANSPOTER_NODE_NAME);
        ROS_INFO("Transpoter Start");
        ros::NodeHandle n;
        ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::transpoter_status>( "/trans_status", 100 );
        ros::Subscriber operation_sub = n.subscribe ("/operation_msg", 100, operationCallback);

        ros::Rate loop_rate(100);
        while( ros::ok() )
        {
	test_move.mainFunction(status_pub);
	ros::spinOnce();
	//loop_rate.sleep();
        }
        return 0;
}

void operationCallback(const ShoesTranspoterPkg::operation_msg& msg)
{
	if ( msg.trans_id == test_move.getID() )
	{
		if(test_move.getLocation() == en_trans_shoebox && test_move.getShoes() == true)
		{
			test_move.setShoes(false);
			test_move.setLocation(msg.trans_location);
			test_move.changeState(3);
			ROS_INFO("Get Message of Change to Turn180");
		}
		else
		{
			if ( msg.trans_shoes == 1){ test_move.setShoes(true); }
			else { test_move.setShoes(false); }
			test_move.setLocation(msg.trans_location);
               		test_move.changeState(0);
			test_move.setInitialTragetColor();
                        ROS_INFO("Get Message of Change to Trace");
		}
	}
}
