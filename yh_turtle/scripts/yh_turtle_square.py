#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
import math
from turtlesim.srv import TeleportAbsolute, TeleportAbsoluteRequest
from yh_turtle_circle import YhTurtleCircle

class YhTurtleCircle(YhTurtleCircle):
    def run(self):
        self.call(5.544445 - self.radius / 2, 5.544445 - self.radius / 2, 0)

        while not rospy.is_shutdown():
            self.msg.linear.x = self.radius
            self.msg.angular.z = 0
            self.pub.publish(self.msg)
            self.loop_rate.sleep()

            self.msg.linear.x = 0
            self.msg.angular.z = math.pi / 2 
            self.pub.publish(self.msg)
            self.loop_rate.sleep()

if __name__ == '__main__':
    rospy.init_node("yh_turtle_circle")
    yh_turtle_circle = YhTurtleCircle(float(input("사각형 한 변의 길이를 입력해주세요. : ")))
    yh_turtle_circle.run()