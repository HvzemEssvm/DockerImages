FROM ros:noetic-ros-core

WORKDIR /catkin_ws

#installing essential packages
RUN sudo apt update
RUN sudo apt install -y ros-noetic-ros-base wget cmake build-essential

#installing catkin
RUN sudo apt install -y ros-noetic-catkin
RUN sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu `lsb_release -sc` main" > /etc/apt/sources.list.d/ros-latest.list'
RUN wget http://packages.ros.org/ros.key -O - | sudo apt-key add -
RUN sudo apt update
RUN sudo apt install -y python3-catkin-tools

#preparing ROS package
RUN mkdir -p /catkin_ws/src
COPY catkin_ws/src /catkin_ws/src/
RUN cd /catkin_ws
RUN /bin/bash -c "source /opt/ros/noetic/setup.bash && catkin_make"
RUN /bin/bash -c "source /catkin_ws/devel/setup.bash"

