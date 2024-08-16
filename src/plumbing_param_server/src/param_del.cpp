#include "ros/ros.h"
#include <sstream>
// #include 

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"param_del_c");
    ros::NodeHandle nh;
    bool flag1 = nh.deleteParam("radius");
    if(flag1)
        ROS_INFO("delete successful");
    else
        ROS_INFO("delete failed");

    bool flag2 = ros::param::del("radius_param");
    if(flag2)
        ROS_INFO("delete successful");
    else
        ROS_INFO("delete failed");
    return 0;
}
