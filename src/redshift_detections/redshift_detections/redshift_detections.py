import rclpy
import math
from rclpy.node import Node
from std_msgs.msg import String
from apriltag_msgs.msg import AprilTagDetectionArray
from apriltag_msgs.msg import AprilTagDetection

from roborio_msgs.msg import RoborioTags

class RedshiftDetections(Node):

    def __init__(self):
        super().__init__('subscriber')
        self.publisher = self.create_publisher(RoborioTags, "/redshift/detection", 10)
        timer_period = 0.02
        self.timer = self.create_timer(timer_period, self.publish_callback)
        self.subscription = self.create_subscription(
            AprilTagDetectionArray,
            '/detections',
            self.detection,
            10)
        self.subscription  # prevent unused variable warning
        
        self.VIEW_ANGLE = 41
        
        self.tag = [5, 11]
        self.tag_dict = {}
        
        self.roborio_msg = RoborioTags()
        
        
        for i in self.tag:
            self.tag_dict[i] = AprilTagDetection()
            self.tag_dict[i].centre.x = -1.0
            self.tag_dict[i].centre.y = -1.0
            self.tag_dict[i].corners[0].y = -1.0
            self.tag_dict[i].corners[2].y = -2.0
            self.tag_dict[i].id = i
            
        
    def detection(self, dets):
        for i in self.tag:
            self.tag_dict[i].centre.x = -1.0
            self.tag_dict[i].centre.y = -1.0
            self.tag_dict[i].corners[0].y = -1.0
            self.tag_dict[i].corners[2].y = -2.0
        for det in dets.detections:
            if det.id in self.tag_dict.keys():
                self.tag_dict[det.id].centre.x = det.centre.x
                self.tag_dict[det.id].centre.y = det.centre.y
                self.tag_dict[det.id].corners[0].y = det.corners[0].y
                self.tag_dict[det.id].corners[2].y = det.corners[2].y
                self.get_logger().info('%s' % self.tag_dict[det.id].centre.x)

    def distance_calc(self, det):
        apriltag_height = abs(det.corners[0].y - det.corners[2].y)
        print("distance: " + str(1500.0/(math.tan(math.radians(self.VIEW_ANGLE/2))*apriltag_height)))
        print("angle: " + str(math.tan(math.radians(self.VIEW_ANGLE/2))))
        print("height: " + str(apriltag_height))
        print("corner1: " + str(det.corners[0].y))
        print("corner2: " + str(det.corners[2].y))
        return 1500.0/(math.tan(math.radians(self.VIEW_ANGLE/2))*apriltag_height)
    	    
    
    def publish_callback(self):
        for i in self.tag:
            self.roborio_msg.tag = self.tag_dict[i].id
            self.roborio_msg.x = self.tag_dict[i].centre.x
            self.roborio_msg.y = self.tag_dict[i].centre.y
            self.roborio_msg.distance = self.distance_calc(self.tag_dict[i])
            self.publisher.publish(self.roborio_msg)

        
def main(args=None):
    rclpy.init(args=args)

    subscriber = RedshiftDetections()

    rclpy.spin(subscriber)

if __name__ == '__main__':
    main()
