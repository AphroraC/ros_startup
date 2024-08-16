#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "plumbing_pub_sub/person.h"

void doMsg(const std_msgs::String::ConstPtr &msg);
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "cuiHua");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("fang",10,doMsg);
    ros::spin();
    return 0;
}


void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("%s",msg->data.c_str());
}