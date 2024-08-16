#include "ros/ros.h"
#include "std_msgs/String.h"
#include "plumbing_service_client/AddInts.h"
#include <sstream>

bool doNums(plumbing_service_client::AddInts::Request &request,
            plumbing_service_client::AddInts::Response &response);
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"chat");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addInts",doNums);
    ros::spin();
    return 0;
}

bool doNums(plumbing_service_client::AddInts::Request &request,
            plumbing_service_client::AddInts::Response &response)
{
    int num1 = request.num1;
    int num2 = request.num2;
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("received: %d %d", num1, num2);
    ROS_INFO("sum: %d",sum);
    return true;
}
