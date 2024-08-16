#include "ros/ros.h"
#include "std_msgs/String.h"
#include "plumbing_pub_sub/person.h"
#include <sstream>

void doPerson(const plumbing_pub_sub::person::ConstPtr &person);
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("lisener init");
    ros::init(argc,argv,"jiaZhang");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chat",10,doPerson);
    ros::spin();
    return 0;
}

void doPerson(const plumbing_pub_sub::person::ConstPtr &person)
{
    ROS_INFO("%s %d %.2f",person->name.c_str(),person->age,person->height);
}