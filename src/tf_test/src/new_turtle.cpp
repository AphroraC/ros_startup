#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Spawn.h"
#include <sstream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"service_call");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    client.waitForExistence();
    // ros::service::waitForService("/spawn");
    bool flag = client.call(spawn);

    if (flag)
    {
        ROS_INFO("successful spawn");
        ROS_INFO("new turtle named:%s",spawn.response.name.c_str());

    }
    else
        ROS_INFO("spawn failed");

    return 0;
}
