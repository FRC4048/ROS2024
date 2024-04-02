import rclpy
import os
import ntcore
from rclpy.node import Node
from std_msgs.msg import UInt16
from apriltag_msgs.msg import AprilTagDetectionArray
from apriltag_msgs.msg import AprilTagDetection

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
            self.detection_pub = self.table.getIntegerTopic("apriltag_id").publish()
        
        
        self.publisher = self.create_publisher(UInt16, "/redshift/apriltag_id", 10)
        timer_period = 0.02
        self.timer = self.create_timer(timer_period, self.publish_callback)
        self.subscription = self.create_subscription(
            AprilTagDetectionArray,
            '/detections',
            self.detection,
            10)
        self.subscription  # prevent unused variable warning
        
        self.tag = [1,2,3,4,5,6,7,8,9,10,11, 12, 13, 14, 15, 16]
        self.roborio_msg = UInt16()
        self.seen = 0
            
        
    def detection(self, dets):
        seen = 0 
        for det in dets.detections:
            if det.id in self.tag:
                seen = det.id
        self.seen = seen       

    	    
    
    def publish_callback(self):
        if (self.ros_publish):
            self.roborio_msg.data = self.seen
            self.publisher.publish(self.roborio_msg)
        if (self.nt_publish):
           self.detection_pub.set(self.seen) 
        
def main(args=None):
    rclpy.init(args=args)

    subscriber = RedshiftDetections()

    rclpy.spin(subscriber)

if __name__ == '__main__':
    main()
