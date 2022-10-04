#include "ros/ros.h"
#include "yh_dual/YhDual.h"

void msgCallback(const yh_dual::YhDual::ConstPtr& msg)
{
    ROS_INFO("recevi msg : %d", msg->data);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_dual_int");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("dog", 20 , msgCallback);

    ros::spin();

    return 0;
}