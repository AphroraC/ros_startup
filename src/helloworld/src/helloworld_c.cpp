#include "ros/ros.h"

int main(int argc, char* argv[])
{
	// setlocale(LC_CTYPE, "zh_CN.utf8");
	// setlocale(LC_ALL, "");

	ros::init(argc,argv,"hello_node");
	ROS_INFO("Hello World!");
	
	return 0;
}
