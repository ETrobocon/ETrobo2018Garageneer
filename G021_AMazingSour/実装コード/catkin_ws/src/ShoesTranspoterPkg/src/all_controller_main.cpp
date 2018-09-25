#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "all_controller/all_controller.hpp"
#define SHOES_NUM 2
static AllController test_all= AllController(SHOES_NUM);

void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg);

int main(int argc, char** argv)
{
        ros::init(argc, argv, "all_controller");
        ROS_INFO("Start All Controller");
        ros::NodeHandle n;
        ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::operation_msg>( "operation_msg", 100 );
        ros::Subscriber operation_sub = n.subscribe ("trans_status", 100, transpoterstatusCallback);
        ros::Rate loop_rate(10);
        while( ros::ok() )
        {
				test_all.mainFunction(status_pub);
				ros::spinOnce();
				loop_rate.sleep();
        }
        return 0;
}

void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg)
{
        ROS_INFO("Get Message");
	test_all.setTranspoterStatus(msg.transpoter_id,msg.transpoter_location,msg.transpoter_shoes);
	if(msg.transpoter_location == 0)
	{
		test_all.changeState();
	}
	else
	{
		ros::NodeHandle n;
		ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::operation_msg>( "operation_msg", 100 );
		test_all.settingEntrance( status_pub,msg.transpoter_shoes );
	}
}
