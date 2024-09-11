#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "log_demo");
    ros::NodeHandle nh;

    ros::Rate r(0.3);
    
    while (ros::ok())
    {
        ROS_DEBUG("DEBUG DEBUG DEBUG");
        ROS_INFO("INFO INFO INFO");
        ROS_WARN("WARN WARN WARN");
        ROS_ERROR("ERROR ERROR ERROR");
        ROS_FATAL("FATAL FATAL FATAL");
        r.sleep();
    }

    return 0;
}
