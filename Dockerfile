FROM ros:humble-ros-base
SHELL [ "/bin/bash" , "-c" ]

RUN apt update && apt install -y build-essential
RUN apt update && apt install -y ros-humble-usb-cam
RUN apt update && apt install -y ros-humble-image-proc
RUN apt update && apt install -y ros-humble-apriltag-ros
RUN apt update && apt install -y ros-humble-tf-transformations
RUN apt update && apt install -y ros-humble-tf2
RUN apt update && apt install -y ros-humble-v4l2-camera
RUN apt update && apt install -y python3
RUN apt update && apt install -y python3-pip
RUN pip3 install transforms3d
RUN pip3 install pyntcore

# COPY Contents
WORKDIR /redshift
COPY contents .

#BUILD WORKSPACE
WORKDIR ros2_ws
RUN source ./install/setup.bash \
    && colcon build

#COPY MISC FILES
WORKDIR /root/.ros
COPY misc/logitech_cam.yaml .
COPY misc/arducam_cam.yaml .

WORKDIR /redshift
CMD ["./redshift_entrypoint.sh", "ros2", "launch", "redshift_odometry", "arducam_launch.py"]
