#!/bin/sh
docker build --platform linux/amd64 -t ros2-4048 .

docker save ros2-4048 -o ros2-4048.tar
