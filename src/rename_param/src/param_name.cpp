#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "hello");
    ros::NodeHandle nh;

    ros::param::set("/RadiusA",100);
    ros::param::set("RadiusA",100);
    ros::param::set("~RadiusA",100);

    nh.setParam("/radius_nh_A", 1000);
    nh.setParam("radius_nh_B", 1000);
    
    ros::NodeHandle nh_private("~");
    nh_private.setParam("radius_nh_private", 1000);

    return 0;
}
