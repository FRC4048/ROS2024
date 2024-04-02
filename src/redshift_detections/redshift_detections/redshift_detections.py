import rclpy
import os
import ntcore
from rclpy.node import Node
from apriltag_msgs.msg import AprilTagDetectionArray
from apriltag_msgs.msg import AprilTagDetection
from roborio_msgs.msg import RoborioTags

class RedshiftDetections(Node):

    def __init__(self):
        super().__init__('subscriber')
        
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
            #self.inst.setServer("192.168.1.160")
            while not self.inst.isConnected():
                pass
            self.get_logger().info("Connected to NETWORK TABLES")
            self.table = self.inst.getTable("ROS")
            self.inst.startDSClient()
            self.detection_pub = self.table.getIntegerArrayTopic("apriltag_id").publish()
        
        
        self.publisher = self.create_publisher(RoborioTags, "/redshift/apriltag_id", 10)
        timer_period = 0.02
        self.timer = self.create_timer(timer_period, self.publish_callback)
        self.subscription = self.create_subscription(
            AprilTagDetectionArray,
            '/detections',
            self.detection,
            10)
        self.subscription  # prevent unused variable warning
        
        self.tag = [1,2,3,4,5,6,7,8,9,10,11, 12, 13, 14, 15, 16]
        self.roborio_msg = RoborioTags()
        self.seen = 0
        self.seen_stamp = self.get_clock().now()
        self.curr_stamp = self.seen_stamp
            
        
    def detection(self, dets):
        self.curr_stamp = rclpy.time.Time.from_msg(dets.header.stamp)
        if (len(dets.detections) > 0):
           self.seen = dets.detections[0].id
           self.seen_stamp = rclpy.time.Time.from_msg(dets.header.stamp)
              
    	    
    
    def publish_callback(self):
        diff = self.curr_stamp - self.seen_stamp
        latency = round(diff.nanoseconds/1e6)
        if (self.ros_publish):
            self.roborio_msg.tag = self.seen
            self.roborio_msg.latency = latency
            self.publisher.publish(self.roborio_msg)
        if (self.nt_publish):
           self.detection_pub.set([self.seen, latency])
        
def main(args=None):
    rclpy.init(args=args)

    subscriber = RedshiftDetections()

    rclpy.spin(subscriber)

if __name__ == '__main__':
    main()
