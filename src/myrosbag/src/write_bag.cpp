#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "bag_write");
    ros::NodeHandle nh;
    rosbag::Bag bag;
    bag.open("hello.bag",rosbag::BagMode::Write);

    std_msgs::String msg;
    msg.data = "hello aphrora";
    bag.write("/chatter", ros::Time::now(), msg);

    bag.close();

    return 0;
}
