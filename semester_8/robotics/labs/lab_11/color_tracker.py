import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

# pip install opencv-contrib-python -> For BRIEF Features

class ImageSubscriber(Node):
  def __init__(self):
    super().__init__('image_subscriber')
    self.subscription = self.create_subscription(Image,'camera_color_frame/image_raw',self.listener_callback,10)
    self.subscription
    self.br = CvBridge() # Used to convert between ROS and OpenCV images
    
    def empty(a): pass
    cv2.namedWindow("TrackBars")
    cv2.resizeWindow("TrackBars", (640, 240))
    cv2.createTrackbar("Hue Min", "TrackBars", 0, 179, empty)
    cv2.createTrackbar("Hue Max", "TrackBars", 179, 179, empty)
    cv2.createTrackbar("Sat Min", "TrackBars", 0, 255, empty)
    cv2.createTrackbar("Sat Max", "TrackBars", 255, 255, empty)
    cv2.createTrackbar("Val Min", "TrackBars", 0, 255, empty)
    cv2.createTrackbar("Val Max", "TrackBars", 255, 255, empty)

  def listener_callback(self, data):
    self.get_logger().info('Receiving video frame')
    img = self.br.imgmsg_to_cv2(data, 'bgr8') # Convert ROS Image message to OpenCV image
    img = cv2.resize(img, None, 1, 0.5, 0.5, cv2.INTER_CUBIC)
    
    #while True:
    imgHSV = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    hmin = cv2.getTrackbarPos("Hue Min", "TrackBars")
    hmax = cv2.getTrackbarPos("Hue Max", "TrackBars")
    smin = cv2.getTrackbarPos("Sat Min", "TrackBars")
    smax = cv2.getTrackbarPos("Sat Max", "TrackBars")
    vmin = cv2.getTrackbarPos("Val Min", "TrackBars")
    vmax = cv2.getTrackbarPos("Val Max", "TrackBars")
    # making the mask
    low = np.array([hmin, smin, vmin])
    upp = np.array([hmax, smax, vmax])
    mask = cv2.inRange(imgHSV, low, upp)
    result = cv2.bitwise_and(img, img, mask=mask)
    #cv2.imshow("HSV", imgHSV)
    cv2.imshow("Mask", mask)
    cv2.imshow("Result", result)
    #cv2.waitKey(1)
    #if cv2.waitKey(1) & 0xFF==ord('q'):
    #break
    print("========================================")
    print("hmin, smin, vmin :", [hmin, smin, vmin])
    print("hmax, smax, vmax :", [hmax, smax, vmax])
    print("========================================")
    cv2.waitKey(1)
  
def main(args=None):
  rclpy.init(args=args)
  image_subscriber = ImageSubscriber()
  rclpy.spin(image_subscriber)
  image_subscriber.destroy_node()
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()
