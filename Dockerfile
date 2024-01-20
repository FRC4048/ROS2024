FROM ros:humble-ros-base
RUN apt update && apt install -y build-essential
RUN apt update && apt install -y ros-humble-usb-cam
RUN apt update && apt install -y ros-humble-image-proc
RUN apt update && apt install -y ros-humble-apriltag-ros

SHELL [ "/bin/bash" , "-c" ]
#COPY SCRIPTS

#COPY NODE CODE

#BUILD WORKSPACE
RUN source /opt/ros/humble/setup.bash \
    && mkdir -p ~/ros2_ws \
    && cd ~/ros2_ws \
    && colcon build
COPY *.sh .


