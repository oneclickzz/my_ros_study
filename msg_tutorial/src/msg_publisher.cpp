#include "ros/ros.h"
//#include "std_msgs/Int64.h"
#include "msg_tutorial/Mymsg.h" //Mymsg 헤더 파일
                                //빌드시 자동 생성

int main(int argc, char** argv)
{
    ros::init(argc, argv, "msg_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<msg_tutorial::Mymsg>("burger", 20);

    ros::Rate loop_rate(2);

    msg_tutorial::Mymsg msg;
    int cnt = 0;

    while (ros::ok())
    {
        /*msg{
            time stamp
            int32 data
        }*/
        // 1614646161(sec).999999999(nsec)
        msg.stamp = ros::Time::now(); //현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt; //cnt 변수의 값을 msg의 data에 담는다.
        ROS_INFO("send msg : %d", msg.stamp.sec); // stamp.sec를 출력한다.
        ROS_INFO("send msg : %d", msg.stamp.nsec); //stamp.nsec를  출력한다.
        ROS_INFO("send msg : %d", msg.data); //data를 출력한다.
        pub.publish(msg); //pub이 msg를 퍼블리시한다.
        cnt++; //cnt 변수의 값을 하나씩 더한다
        loop_rate.sleep(); //위에서 정한 주기에 따라 sleep 한다.
    }

    return 0;
}