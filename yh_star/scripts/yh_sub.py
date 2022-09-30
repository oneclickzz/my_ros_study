#!/usr/bin/python3
# -*- coding: utf-8 -*-
import rospy
from yh_star.msg import YhStarMsg

def msgCallback(msg):
    n = msg.data
    # my_star =  ["*"*i+"\n" for i in range(1, n//2+1)+["*"*(n-i+1)+"\n" for i in range(n//2+1,n+1)]
    # print("\n".join(my_star))  아래 for문 대체
    for i in range(1, n//2+1):
        for j in range(i):
            print("*", end='')
        print()
    for i in range(n//2+1, n+1):
        for j in range(n-i+1):
            print("*", end='')
        print()

def star_printer():
    rospy.init_node("yh_star_sub")
    rospy.Subscriber("yh_star_topic", YhStarMsg, msgCallback)
    rospy.spin()


if __name__ == "__main__":
    star_printer()