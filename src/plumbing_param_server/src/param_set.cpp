#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_param_c");
    ros::NodeHandle nh;
    nh.setParam("type","xiaoHuang");
    nh.setParam("radius",0.15);
    ros::param::set("type_param","xiaoBai");
    ros::param::set("radius_param",0.15);
    ROS_INFO("param_set init");
    return 0;
}
