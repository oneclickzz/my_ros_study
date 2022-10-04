#include "ros/ros.h"
#include "yh_check/YhCheck.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_check_camera");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_check::YhCheck>("check_camera", 20);

    ros::Rate loop_rate(2.5);

    yh_check::YhCheck msg;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); 
        ROS_INFO("receive msg : %d", msg.data2); 
        pub.publish(msg); 
        loop_rate.sleep();
    }

    return 0;
}