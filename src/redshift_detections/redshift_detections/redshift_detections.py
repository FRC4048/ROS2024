import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from apriltag_msgs.msg import AprilTagDetectionArray

from roborio_msgs.msg import RoborioTags

class RedshiftDetections(Node):

    def __init__(self):
        super().__init__('subscriber')
        self.publisher = self.create_publisher(RoborioTags, "/test_topic", 10)
        timer_period = 0.02
        self.timer = self.create_timer(timer_period, self.publish_callback)
        self.subscription = self.create_subscription(
            AprilTagDetectionArray,
            '/detections',
            self.detection,
            10)
        self.subscription  # prevent unused variable warning
        
        self.tag = [7, 8, 9, 10]
        self.tag_dict = {}
        for i in self.tag:
            self.tag_dict[i] = RoborioTags()
            self.tag_dict[i].x = -1.0
            self.tag_dict[i].y = -1.0
            self.tag_dict[i].tag = i


    def detection(self, dets):
        for i in self.tag:
            self.tag_dict[i].x = -1.0
            self.tag_dict[i].y = -1.0
        for det in dets.detections:
            self.tag_dict[det.id].x = det.centre.x
            self.tag_dict[det.id].y = det.centre.y
            self.get_logger().info('%s' % self.tag_dict[det.id].x)

    def publish_callback(self):
        for i in self.tag:
       	   self.publisher.publish(self.tag_dict[i])

        
def main(args=None):
    rclpy.init(args=args)

    subscriber = RedshiftDetections()

    rclpy.spin(subscriber)

if __name__ == '__main__':
    main()
