#include "ros/ros.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);


    ros::Rate rate(10);
    while (ros::ok())
    {
        try
        {
             auto son1_to_son2= buffer.lookupTransform("turtle2","turtle1",ros::Time(0.0));
             auto xx = son1_to_son2.transform.translation.x;
             auto yy = son1_to_son2.transform.translation.y;
            ROS_INFO("axis 1->2:  %lf,%lf",xx,yy);

            geometry_msgs::Twist twist;
            twist.linear.x = 0.5*sqrt( pow(xx,2) + pow(yy,2));
             
            twist.angular.z = 4*atan2(yy,xx);

            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            ROS_INFO("Error...");
            // std::cerr << e.what() << '\n';
        }
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
