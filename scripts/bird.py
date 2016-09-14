#!/usr/bin/python

import rospy
import baxter_interface

rospy.init_node("Baxter_Bird")

limb = baxter_interface.Limb('right')
angles = limb.joint_angles()

angles['right_s0'] = 0.0
angles['right_s1'] = 0.0
angles['right_e0'] = 0.0
angles['right_e1'] = 0.0
angles['right_w0'] = 0.0
angles['right_w1'] = 0.0
angles['right_w2'] = 0.0

