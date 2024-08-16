#include "ros/ros.h"
#include "std_msgs/String.h"
#include "plumbing_pub_sub/person.h"
#include <sstream>

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("talker init");
    ros::init(argc, argv, "banZhuRen");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::person>("chat",10);
    plumbing_pub_sub::person person;
    person.name = "Mike";
    person.age = 18;
    person.height = 1.88;
    ros::Rate rate(1);
    while (ros::ok())
    {
        person.age++;
        pub.publish(person);
        ROS_INFO("%s %d %.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
        /* code */
    }
    

    return 0;
}