#include "ros/ros.h"
#include "yh_check/YhCheck.h"

void msgCallback(const yh_check::YhCheck::ConstPtr& msg)
{
    if (msg->data1==0 && msg->data2==0)
    {
        ROS_INFO("receive msg : %d", msg->stamp.sec); 
        ROS_INFO("receive msg : %d", msg->stamp.nsec); 
        ROS_INFO("receive msg : OK"); 
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_check_sub"); 
    ros::NodeHandle nh;
    
    ros::Subscriber sub = nh.subscribe("yyy", 20, msgCallback); 

    ros::spin(); 

    return 0;
}