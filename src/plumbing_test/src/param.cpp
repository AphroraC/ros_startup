#include "ros/ros.h"
#include "std_msgs/String.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"change_color");
    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r",0);
    nh.setParam("background_g",0);
    nh.setParam("background_b",0);
    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",0);
    // ros::param::set("/turtlesim/background_b",0);
    return 0;
}
