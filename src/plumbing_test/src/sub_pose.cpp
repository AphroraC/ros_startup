#include "ros/ros.h"
#include "std_msgs/String.h"
#include "turtlesim/Pose.h"
#include <sstream>

void doPose(const turtlesim::Pose::ConstPtr &pose);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_pose");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    ros::spin();
    return 0;
}

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("turtle state info:");
    ROS_INFO("axis: (%.2f,%.2f)",pose->x,pose->y);
    ROS_INFO("toward: %.2f",pose->theta);
    ROS_INFO("linear: %.2f",pose->linear_velocity);
    ROS_INFO("angular: %.2f",pose->angular_velocity);
}
