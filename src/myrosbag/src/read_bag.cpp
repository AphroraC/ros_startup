#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include "std_msgs/String.h"
#include <string>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "bag_read");
    ros::NodeHandle nh;
    rosbag::Bag bag;
    bag.open("hello.bag",rosbag::BagMode::Read);
    // rosbag::View(bag);
    for (auto &&ele : rosbag::View(bag))
    {
        auto topic = ele.getTopic();
        auto time = ele.getTime();
        auto p=ele.instantiate<std_msgs::String>();
        ROS_INFO("topic :%s, time_stamp :%.2f, value :%s",topic.c_str(),time.toSec(),p->data.c_str());


    }

    bag.close();

    return 0;
}
