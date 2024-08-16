#include "ros/ros.h"
#include "plumbing_service_client/AddInts.h"

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        ROS_INFO("incorrect arguments");
        return 1;
    }
    ros::init(argc,argv,"daBao");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_service_client::AddInts>("addInts");
    plumbing_service_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    //client.waitForExistence();
    ros::service::waitForService("addInts");
    bool flag = client.call(ai);
    if (flag)
        ROS_INFO("respond succeed. sum: %d",ai.response.sum);
    else
        ROS_INFO("respond failed");

    return 0;
}
