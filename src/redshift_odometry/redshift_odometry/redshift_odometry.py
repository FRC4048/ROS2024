import rclpy
import math
import datetime
import os
from rclpy.node import Node
from tf2_ros.buffer import Buffer
from tf2_ros import TransformException
from tf2_ros.transform_listener import TransformListener
from tf2_msgs.msg import TFMessage
from geometry_msgs.msg import TransformStamped
from roborio_msgs.msg import RoborioOdometry
import ntcore

# this node finds the location of the camera on the field, by getting the transform
# from world->camera from the buffer.
# It then publishes it to either NT or ROS or both.

class RedshiftOdomListener(Node):
    def __init__(self):
        super().__init__('subscriber')
        
        self.from_frame = 'world'
        self.to_frame = 'logitech'
        
        # create PUBLISHER
        self.publisher = self.create_publisher(RoborioOdometry, '/redshift/odometry', 2)
                
        # create LISTENER structures
        self.prev_tf = TransformStamped()
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.pose_msg = RoborioOdometry()

        # SET VALUES FOR OPTIONAL PARMS
        publish_frequency = 0.05

        self.ros_publish = True
        tmp = os.environ.get('PUB_ROS')
        if (tmp in ('0', 'false', 'False', 'f', 'F')):
           self.ros_publish = False
        if (self.ros_publish):
           self.get_logger().info('Publishing to ROS')

        self.nt_publish = False
        tmp = os.environ.get('PUB_NT')
        if (tmp in ('1', 'true', 'True', 'TRUE', 't', 'T')):
           self.nt_publish = True
        if (self.nt_publish):
           self.get_logger().info("Publishing to NETWORK TABLES")

        # CREATE NETWORK TABLE CONNECTION AND PUBLISHER
        if (self.nt_publish):
            self.inst = ntcore.NetworkTableInstance.getDefault()
            self.inst.startClient4("ROS Client")
            self.inst.setServerTeam(4048)
            while not self.inst.isConnected():
                pass
            self.get_logger().info("Connected to NETWORK TABLES")
            self.table = self.inst.getTable("ROS")
            self.inst.startDSClient()
            self.odom_pub = self.table.getDoubleArrayTopic("Pos").publish()
        
        #get_pose callback every 1/15 sec (/tf hz)
        self.timer = self.create_timer(publish_frequency, self.get_pose)
        self.get_logger().info("Publishing frequency: {}".format(publish_frequency))

    def get_pose(self):
        try:
           t = self.tf_buffer.lookup_transform(
               self.from_frame,
               self.to_frame,
               rclpy.time.Time())
           # If the transform we got is the same one as we already published, just publish -1
           if ((t.header.stamp.nanosec != self.prev_tf.header.stamp.nanosec) or
              (t.header.stamp.sec != self.prev_tf.header.stamp.sec)):
              self.prev_tf.header = t.header
              self.pose_msg.x = t.transform.translation.x
              self.pose_msg.y = t.transform.translation.y
              (roll, pitch, yaw) = self.euler_from_quaternion(
                                   t.transform.rotation.x, 
                                   t.transform.rotation.y, 
                                   t.transform.rotation.z, 
                                   t.transform.rotation.w)
              self.pose_msg.yaw = math.degrees(yaw)+90
           else:
              self.reset_pose()
                                
        except TransformException as ex:
           self.get_logger().warning('Could not transform')
           self.reset_pose()
        #if (self.pose_msg.yaw != -1):
        #   print(self.pose_msg.yaw, end=" ")

        if (self.nt_publish == True):
           self.odom_pub.set([self.pose_msg.x, self.pose_msg.y, self.pose_msg.yaw]) 
                  
        if (self.ros_publish == True):
           self.publisher.publish(self.pose_msg)
           
    def reset_pose(self):
       self.pose_msg.x = -1.0
       self.pose_msg.y = -1.0
       self.pose_msg.yaw = -1.0       
        
    def euler_from_quaternion(self, x, y, z, w):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        roll is rotation around x in radians (counterclockwise)
        pitch is rotation around y in radians (counterclockwise)
        yaw is rotation around z in radians (counterclockwise)
        """
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = math.atan2(t0, t1)
     
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)
     
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = math.atan2(t3, t4)
     
        return roll_x, pitch_y, yaw_z # in radians       
        
def main(args=None):
    rclpy.init(args=args)
    listener = RedshiftOdomListener()
    rclpy.spin(listener)

if __name__ == '__main__':
    main()
