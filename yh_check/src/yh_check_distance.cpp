#include "ros/ros.h"
#include "yh_check/YhCheck.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_check_distance");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_check::YhCheck>("check_distance", 20);

    ros::Rate loop_rate(2);

    yh_check::YhCheck msg;

    int cnt = 0;
    cnt = 1 - cnt;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); 
        int cnt = 0;
        msg.data1 = cnt;
        if(msg.data1 == 0)
        {
            ROS_INFO("false");
        }
        else
        {
            ROS_INFO("true");
        }
        cnt = 1 - cnt;
        pub.publish(msg); 

        
        loop_rate.sleep();
    }

    return 0;
}