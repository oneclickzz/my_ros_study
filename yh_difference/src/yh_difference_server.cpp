#include "ros/ros.h"
#include "yh_difference/YhDifference.h"
#include <cstdlib>

bool dif(yh_difference::YhDifference::Request& req,
        yh_difference::YhDifference::Response& res)

{
    res.result = abs(req.a - req.b);
    ROS_INFO("request: a=%d, b=%d",req.a, req.b);
    ROS_INFO("response: result=%d", res.result);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_difference_server");
    ros::NodeHandle nh;

    ros::ServiceServer yh_difference_server = nh.advertiseService("yh_difference_service",  dif);

    ros::spin();

    return 0;
}