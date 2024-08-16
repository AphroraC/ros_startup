#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "hello_time", ros::init_options::AnonymousName);
    ros::NodeHandle nh;

    ros::Time right_now = ros::Time::now();
    ROS_INFO("current time: %.2f",right_now.toSec());
    ROS_INFO("current time: %d",right_now.sec);
    ROS_INFO("--------PAUSE--------");
    ros::Time start = ros::Time::now();
    ROS_INFO("start sleep:%.2f",start.toSec());
    ros::Duration du1(10.0);
    du1.sleep();

    
    ros::Time end = ros::Time::now();
    ROS_INFO("end sleep:%.2f",end.toSec());
    

    ros::Time t1(20.30);
    ROS_INFO("t1: %.2f",t1.toSec());
    return 0;
}


