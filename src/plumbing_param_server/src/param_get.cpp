#include "ros/ros.h"
#include <sstream>
#include <vector>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);
    double radius2 = 0.0;
    bool result = nh.getParam("radius",radius2);
    if(result)
        ROS_INFO("result-> radius received: %.2f",radius2);
    else
        ROS_INFO("no matching result");
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name: names)
        ROS_INFO("iterator element:%s",name.c_str());

    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("horus");
    ROS_INFO("radius exist? %d",flag1);
    ROS_INFO("horus exist? %d",flag2);

    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("search result: %s",key.c_str());

    double radius_param = ros::param::param("radius",100.5);
    ROS_INFO("radius_param = %.2f",radius_param);

    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);

    for (auto &&name : names)
        ROS_INFO("key: %s",name.c_str());

        

    return 0;
}
