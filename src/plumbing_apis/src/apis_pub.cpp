#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "erGouZi", ros::init_options::AnonymousName);
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10,true);
    std_msgs::String msg;
    ros::Rate rate(1);
    int count = 0;
    ros::Duration(3).sleep();
    while (ros::ok())
    {
        count++;
        std::stringstream ss;
        ss << "hello--->" << count;
        msg.data = ss.str();

        if (count < 10)
        {
        pub.publish(msg);
        ROS_INFO("released data:%s",ss.str().c_str());
        }
        
        rate.sleep();
        ros::spinOnce();
    }

    // ros::
    return 0;
}
