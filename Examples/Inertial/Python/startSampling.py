'''
Date: 2022-02-10 10:58:08
LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
LastEditTime: 2022-02-10 16:03:00
FilePath: /Python/startSampling.py
'''
#import the mscl library
import sys
sys.path.append("/usr/share/python3-mscl/")
import mscl

#TODO: change these constants to match your setup
COM_PORT = "/dev/ttyACM0"

try:
    #create a Serial Connection with the specified COM Port, default baud rate of 921600
    connection = mscl.Connection.Serial(COM_PORT)

    #create an InertialNode with the connection
    node = mscl.InertialNode(connection)

    #many other settings are available than shown below
    #reference the documentation for the full list of commands

    #if the node supports AHRS/IMU
    if node.features().supportsCategory(mscl.MipTypes.CLASS_AHRS_IMU):
        node.enableDataStream(mscl.MipTypes.CLASS_AHRS_IMU)

    #if the node supports Estimation Filter
    if node.features().supportsCategory(mscl.MipTypes.CLASS_ESTFILTER):
        node.enableDataStream(mscl.MipTypes.CLASS_ESTFILTER)

    #if the node supports GNSS
    if node.features().supportsCategory(mscl.MipTypes.CLASS_GNSS):
        node.enableDataStream(mscl.MipTypes.CLASS_GNSS)

except mscl.Error as e:
    print ("Error:", e)
