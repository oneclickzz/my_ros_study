# ros_study
my first ros study

### 2022년 9월 27일 시작
- topic_tutorial
    - topic_tutorial 패키지 생성
    - my_publisher, my_subscriber 노드 생성
    - 빌드
    - 실행

### 2022년 9월 28일
- topic_tutorial
    - topic_tutorial 패키지에 python scripts 추가
    - py_publisher.py, py_subscriber.py 노드 생성
    - 빌드
    - 실행

- topic_second
    - topic_second 패키지 생성
    - second_pub, second_sub, py_second_pub.py, py_second_sub.py 노드 생성
    - 빌드
    - 실행

- [과제 1](./topic_test)

### 2022년 9월 29일
- [msg_tutorial](./msg_tutorial)
    - msg_tutorial 패키지 생성
    - msg 디렉토리에 Mymsg.msg 생성
    - msg_publisher, msg_subscsriber, py_msg_pub.py, py_msg_sub.py 노드 생성
    - 빌드
    - 실행

- [service_tutorial](./service_tutorial)
    - service_tutorial 패키지 생성
    - srv 디렉토리에 AddTwoInts.srv 생성
    - my_server, my_client, py_server.py, py_client.py 노드 생성
    - 빌드
    - 실행

### 2022년 9월 30일
- [과제 2 yh_star](./yh_star)
- for문 활용해서 별 찍기
    - yh_star 패키지 생성
    - yh_star_pub, yh_star_sub, yh_star_pub.py, yh_star_sub.py 노드생성
    - 빌드
    - 실행

- [과제 3 yh_service](.yh_service)
    - yh_service 패키지 생성
    - yh_server, yh_client, yh_server.py, yh_client.py 노드 생성
    - 빌드
    - 실행
    - 같음 이름의 서버는 하나밖에 못킴

## 2022년 10월 4일
### [param_tutorial](./param_tutorial)
- param_tutorial 패키지 생성
- calculate_server, calculate_client, calculate_server.py calculate_client.py 노드 생성
- 빌드
- 실행
- [파라미터 서버 활용](#parameter-server)

### [과제4 yh_dual](./yh_dual)
- [과제4.pdf](./yh_dual/과제4.pdf)

### [과제5 yh_difference](./yh_difference)
- [과제5.pdf](./yh_difference/과제5.pdf)

## 2022년 10월 5일

### [과제6 yh_check](./yh_check)
- [과제6.pdf](./yh_check/과제6.pdf)
    - yh_chech 패키지 생성
    - yh_check_distance, yh_check_camera, yh_check_sub,
      yh_check_distance.py, yh_check_camera.py, yh_check_sub.py 노드 생성
    - 빌드
    - 실행
    - Python 클래스로 작성

### [과제7 yh_connect](./yh_connect)
- [과제7.pdf](./yh_connect/과제7.pdf)
    - yh_connect 패키지 생성
    - yh_connect_pub, yh_connect_sub, yh_connect_sub_pub,
      yh_connect_pub.py, yh_connect_sub.py, yh_connect_sub_pub.py 노드 생성
    - 빌드
    - 실행
    - Python 클래스로 작성
    
## ROS 명령어
### roscore
- ROS Master를 실행한다.
- 노드를 켜기 전에 가장 먼저 실행
```bash
lhk15477@gmail.com:~$ roscore
```

### rosrun
- 노드를 실행한다.
- rosrun 패키지이름 노드이름
```bash
lhk15477@gmail.com:~$ rosrun <패키지이름> <노드이름>
```

### catkin_create_pkg
- 현재 위치한 작업 공간에 패키지를 생성한다.
- catkin_create_pkg 패키지이름 의존성
```bash
lhk15477@gmail.com:~$ catkin_create_pkg <패키지이름> [의존성1] [의존성2] .... 
```
ex)
```bash
lhk15477@gmail.com:~$ catkin_create_pkg topic_tutorial roscpp rospy std_msgs
메시지시 message_generation
```


### python 권한 주기
ex) chmod +x src/ros_study/service_tutorial/scripts/*
파이썬 빌드할때.py 꼭

### param_tutorial 계산방법 변경
rosparam set /calculation_method ()
 
### Parameter Server
- ROS Master에서 실행되고, 변수들을 담고 있는 서버
- ros::setParam(), ros::getParam(), rospy.set_param(), rospy.get_param() 등의 함수로 사용
- command line에서 rosparam으로 사용 가능
- rosparam list
    - 파라미터 서버의 모든 파라미터를 출력
    - rosparam get /<파라미터 이름>
        - 파라미터의 값을 출력함
    - rosparam seㅅ /<파라미터 이름> [파라미터 값]
        - 파라미터의 값을 지정함
        - rosparam set /calculation_method 2