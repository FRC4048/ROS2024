import launch
import launch_ros.actions
 	 	  
def generate_launch_description():
    parameter_file_path = "/home/redshift/ros2_ws/misc/apriltag.yaml"
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','0','0','1.57','world','tag7'],
            name='tag7'),
            
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments=['0','2','0.74','0', '0', '1.57','world','tag5'],
            name='tag5'),  
                
        launch_ros.actions.Node(
            package="usb_cam",
            executable="usb_cam_node_exe",
            remappings=[("/image_raw", "/image")],
            parameters=[
                {"video_device": "/dev/video0"},
                {"camera_name": "logitech_cam"},
                {"frame_id": "logitech"},
                {"image_height": 480},
                {"image_width": 640},
                {"framerate": 30.0},
            ],
            name='sim'),     
            
        launch_ros.actions.Node(
            package="image_proc",
            executable="image_proc"),
            
        launch_ros.actions.Node(
            package="apriltag_ros",
            executable="apriltag_node",
            remappings=[("/tf", "/tf_camera")],            
            parameters=[parameter_file_path]),
  ])
