import launch
import launch_ros.actions
 	 	  
def generate_launch_description():
    parameter_file_path = "/home/redshift/ros2_ws/misc/apriltag.yaml"
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','-2.62','0','1.57','world','tag1'],
            name='tag1'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','-2.62','0','1.57','world','tag2'],
            name='tag2'),            
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','-1.57','0','1.57','world','tag3'],
            name='tag3'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','-1.57','0','1.57','world','tag4'],
            name='tag4'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','0','0','1.57','world','tag5'],
            name='tag5'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','0','0','1.57','world','tag6'],
            name='tag6'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)            
            arguments=['0','2','0.74','1.57', '0', '1.57','world','tag7'],
            name='tag7'),  
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['0','2','0.74','1.57', '0', '1.57','world','tag8'],
            name='tag8'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','2.618','0','1.57','world','tag9'],
            name='tag9'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','2.618','0','1.57','world','tag10'],
            name='tag10'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','0.5236','0','1.57','world','tag11'],
            name='tag11'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','2.618','0','1.57','world','tag12'],
            name='tag12'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','-1.57','0','1.57','world','tag13'],
            name='tag13'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['0','2','0.74','1.57', '0', '1.57','world','tag14'],
            name='tag14'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','-2.62','0','1.57','world','tag15'],
            name='tag15'),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            #translation x, y, z, rotation z, y, x (numbers are to get from world to tag)
            arguments=['1.0','1','0.74','5.76','0','1.57','world','tag16'],
            name='tag16'),

                
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
            
 #       launch_ros.actions.Node(
 #           package="image_proc",
 #           executable="image_proc"),
 #           
 #       launch_ros.actions.Node(
 #           package="apriltag_ros",
 #           executable="apriltag_node",
 #           remappings=[("/tf", "/tf_camera")],            
 #           parameters=[parameter_file_path]),
  ])
