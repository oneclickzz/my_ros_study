#include "ros/ros.h"
#include "yh_difference/YhDifference.h"
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_difference_client");
    if(argc != 3)
    {
        ROS_INFO("command: rosrun service_tutorial my_client arg1 arg2");
        ROS_INFO("arg1, arg2 : int32 number");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient yh_difference_client = nh.serviceClient<yh_difference::YhDifference>("yh_difference_service");

    yh_difference::YhDifference srv;

    srv.request.a = atoi(argv[1]);
    srv.request.b = atoi(argv[2]);

    if (yh_difference_client.call(srv))
    {
        ROS_INFO("send srv: srv.request.a=%d, srv.request.b=%d",srv.request.a, srv.request.b);
        ROS_INFO("receive srv: srv.reponse.result=%d", srv.response.result);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    return 0;
}