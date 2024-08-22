#include "ros/ros.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    geometry_msgs::PointStamped psAtSon1;
    psAtSon1.header.stamp = ros::Time::now();
    psAtSon1.header.frame_id = "son1";
    psAtSon1.point.x = 1.0;
    psAtSon1.point.y = 2.0;
    psAtSon1.point.z = 3.0;



    ros::Rate rate(10);
    while (ros::ok())
    {
        try
        {
            static auto son1_to_son2= buffer.lookupTransform("son2","son1",ros::Time(0.0));
            ROS_INFO("axis son1 -> son2:  %s,%s",
            son1_to_son2.header.frame_id.c_str(),
            son1_to_son2.child_frame_id.c_str());
            auto psAtSon2 = buffer.transform(psAtSon1, "son2");
            ROS_INFO("@axis_son2: %.2f,%.2f,%.2f", psAtSon2.point.x, psAtSon2.point.y, psAtSon2.point.z);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("Error...");
            // std::cerr << e.what() << '\n';
        }
        rate.sleep();
        ros::spinOnce()
        ;
    }

    return 0;
}
