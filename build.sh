#!/bin/sh

mkdir -p contents
rm -rf contents/*

mkdir -p contents/ros2_ws
mkdir -p contents/ros2_ws/log
mkdir -p contents/ros2_ws/build
cp -r misc contents/ros2_ws
cp -r src contents/ros2_ws
cp -r install contents/ros2_ws
cp redshift_entrypoint.sh contents
cp start-*.sh contents
chmod +x contents/redshift_entrypoint.sh
chmod +x contents/start-*.sh
git clone https://github.com/clydemcqueen/opencv_cam contents/ros2_ws/src/opencv_cam/
git clone https://github.com/ptrmu/ros2_shared.git contents/ros2_ws/src/ros2_shared/

docker build --platform linux/arm64 -t frc4048-ros2 .

docker save frc4048-ros2 -o frc4048-ros2.tar
