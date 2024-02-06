FROM ros:humble-ros-base
RUN apt update && apt install -y build-essential
RUN apt update && apt install -y ros-humble-usb-cam
RUN apt update && apt install -y ros-humble-image-proc
RUN apt update && apt install -y ros-humble-apriltag-ros
RUN apt update && apt install -y ros-humble-tf-transformations
RUN apt update && apt install -y ros-humble-tf2
RUN apt update && apt install -y ros-humble-v4l2-camera
RUN apt update && apt install -y python-pip
RUN pip3 install transforms3d

SHELL [ "/bin/bash" , "-c" ]
#COPY SCRIPTS
RUN mkdir -p ~/scripts
COPY start-apriltab-ros.sh ~/scripts/
COPY start-image-proc.sh ~/scripts/
COPY start-redshift-detection.sh ~/scripts/
COPY start-usb-cam.sh ~/scripts/

#CREATE WORKSPACE
RUN mkdir -p ~/ros2_ws \
COPY build/* ~/ros2_ws/
COPY install/* ~/ros2_ws/
COPY log/* ~/ros2_ws/
COPY misc/* ~/ros2_ws/
COPY src/* ~/ros2_ws/

#BUILD WORKSPACE
RUN source /opt/ros/humble/setup.bash \
    && cd ~/ros2_ws \
    && colcon build
COPY *.sh .

#COPY MISC FILES
COPY misc/logitech_cam.yaml ~/.ros/camera_info/
COPY misc/arducam_cam.yaml ~/.ros/camera_info/

