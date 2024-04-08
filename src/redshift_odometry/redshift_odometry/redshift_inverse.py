import rclpy
from rclpy.node import Node
from tf2_msgs.msg import TFMessage
from geometry_msgs.msg import TransformStamped
import numpy as np
import math
import tf_transformations as tft

# This node takes a transform published by apriltag_ros from camera->tag, and transforms
# it to be tag->camera. We have to do that to maintain a tree structure.

class TFInverse(Node):

    def __init__(self):
        super().__init__('subscriber')
        
        # create PUBLISHER
        self.publisher = self.create_publisher(TFMessage, '/tf', 10)
        
        # create SUBSCRIBER
        self.subscription = self.create_subscription(
            TFMessage,
            '/tf_camera',
            self.tf_callback,
            10)
        self.subscription  # prevent unused variable warning

    def tf_callback(self, msg):
        for msg_tf in msg.transforms:
           #self.get_logger().info("time="+str(msg_tf.header.stamp))
           #self.get_logger().info("clock="+str(self.get_clock().now()))
           
           inv_translation, inv_rotation = self.inverse_tf(msg_tf)
           msg_tf.transform.translation.x = inv_translation[0]
           msg_tf.transform.translation.y = inv_translation[1]
           msg_tf.transform.translation.z = inv_translation[2]
           msg_tf.transform.rotation.x = inv_rotation[0]
           msg_tf.transform.rotation.y = inv_rotation[1]
           msg_tf.transform.rotation.z = inv_rotation[2]
           msg_tf.transform.rotation.w = inv_rotation[3]
           msg_tf.header.frame_id = msg_tf.child_frame_id
           msg_tf.child_frame_id = "logitech"
           msg_tf.header.stamp = self.get_clock().now().to_msg()
        self.publisher.publish(msg)

    def inverse_tf(self, t):
        trans = [t.transform.translation.x, t.transform.translation.y, t.transform.translation.z]
        rot = [t.transform.rotation.x, t.transform.rotation.y, t.transform.rotation.z, t.transform.rotation.w]
        transform = tft.concatenate_matrices(tft.translation_matrix(trans), tft.quaternion_matrix(rot))
        inversed_transform = tft.inverse_matrix(transform)
        inversed_translation = tft.translation_from_matrix(inversed_transform)
        inversed_rotation = tft.quaternion_from_matrix(inversed_transform)
        return(inversed_translation, inversed_rotation)
                
def main(args=None):
    rclpy.init(args=args)
    subscriber = TFInverse()
    rclpy.spin(subscriber)

if __name__ == '__main__':
    main()
