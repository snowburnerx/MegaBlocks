#!/usr/bin/python

from __future__ import print_function

import roslib
roslib.load_manifest('assembler')
import sys
import rospy
import cv2
import numpy as np
from std_msgs.msg import Float64, Int32
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from baxter_interface import camera


class image_converter:

    def __init__(self):

        self.p1 = 12
        self.p2 = 15
        self.xD = 3
        self.yD = 3
        self.xE = 3
        self.yE = 3
        self.xE2 = 3
        self.yE2 = 3
        self.maxRadius = 50
        self.minRadius = 8

        self.image_pub = rospy.Publisher("image_converted", Image, queue_size=10)

        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber("/cameras/right_hand_camera/image", Image, self.callback)

        self.p1_sub = rospy.Subscriber("/set_p1", Float64, self.param1Callback)
        self.p2_sub = rospy.Subscriber("/set_p2", Float64, self.param2Callback)
        self.xD_sub = rospy.Subscriber("/set_xD", Int32, self.setxD)
        self.yD_sub = rospy.Subscriber("/set_yD", Int32, self.setyD)
        self.xE_sub = rospy.Subscriber("/set_xE", Int32, self.setxE)
        self.yE_sub = rospy.Subscriber("/set_yE", Int32, self.setyE)
        self.xE2_sub = rospy.Subscriber("/set_xE2", Int32, self.setxE2)
        self.yE2_sub = rospy.Subscriber("/set_yE2", Int32, self.setyE2)
        self.min_sub = rospy.Subscriber("/set_minRadius", Int32, self.minCallback)
        self.max_sub = rospy.Subscriber("/set_maxRadius", Int32, self.maxCallback)

        camCon = camera.CameraController("right_hand_camera")
        camCon.resolution = (960, 600)
        # camCon.exposure = 40.0
        camCon.gain = 25.0

    def adjust_gama(self, image, gamma=1.0):
        invGamma = 1.0 / gamma
        table = np.array([((i / 255.0) ** invGamma) * 255
                          for i in np.arange(0, 256)]).astype("uint8")

        return cv2.LUT(image, table)

    def callback(self, data):

        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            print("ERROR")
            print(e)

        cv_image = self.adjust_gama(cv_image, gamma=1.80)
        # lab_image = cv2.cvtColor(cv_image, cv2.COLOR_BGR2LAB)
        # lab_planes = cv2.split(lab_image)
        # clahe = cv2.createCLAHE(clipLimit=4.0, tileGridSize=(8, 8))
        # dst = clahe.apply(lab_planes[0])
        # lab_planes[0] = dst
        # lab_image = cv2.merge(lab_planes)
        # cv_image = cv2.cvtColor(lab_image, cv2.COLOR_LAB2BGR)

        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        cv2.GaussianBlur(gray, dst=gray, ksize=(9,9), sigmaX=2, sigmaY=2)
        cv2.Canny(gray, threshold1=self.p1, threshold2=self.p2, edges=gray, apertureSize=3, L2gradient=True)

        elementE = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (self.xE, self.yE))
        cv2.morphologyEx(src=gray, op=cv2.MORPH_CLOSE, kernel=elementE, dst=gray)

        # elementE = cv2.getStructuringElement(cv2.MORPH_ERODE, (self.xE, self.yE))
        # cv2.erode(gray, elementE, dst=gray)
        #
        # elementD = cv2.getStructuringElement(cv2.MORPH_DILATE, (self.xD, self.yD))
        # cv2.dilate(gray, elementD, dst=gray)
        #
        # elementE2 = cv2.getStructuringElement(cv2.MORPH_CROSS, (self.xE2, self.yE2))
        # cv2.erode(gray, elementE2, dst=gray)


        circles = cv2.HoughCircles(gray, method=cv2.cv.CV_HOUGH_GRADIENT, dp=1, minDist=len(gray)/7, param1=self.p1, param2=self.p2, minRadius=self.minRadius, maxRadius=self.maxRadius)

        if len(circles) > 0:
            circles = np.uint16(np.around(circles))

        for i in circles[0, :]:
            cv2.circle(cv_image, (i[0], i[1]), i[2], (0, 255,0), 2)
            cv2.circle(cv_image, (i[0], i[1]), 2, (0, 0, 255), 3)

        try:
            self.image_pub.publish(self.bridge.cv2_to_imgmsg(cv_image, "bgr8"))
        except CvBridgeError as e:
            print("ERROR")
            print(e)

    def param1Callback(self, msg):
        self.p1 = msg.data

    def param2Callback(self, msg):
        self.p2 = msg.data

    def maxCallback(self, msg):
        self.maxRadius = msg.data

    def minCallback(self, msg):
        self.minRadius = msg.data

    def setxD(self, msg):
        self.xD = msg.data

    def setyD(self, msg):
        self.yD = msg.data

    def setxE(self, msg):
        self.xE = msg.data

    def setyE(self, msg):
        self.yE = msg.data\

    def setxE2(self, msg):
        self.xE2 = msg.data

    def setyE2(self, msg):
        self.yE2 = msg.data

def main(args):
    rospy.init_node('image_converter', anonymous=True)
    ic = image_converter()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting Down.")

if __name__ == '__main__':
    main(sys.argv)
