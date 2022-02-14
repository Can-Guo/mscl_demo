'''
Date: 2022-02-11 22:10:31
LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
LastEditTime: 2022-02-13 12:57:04
FilePath: /example_python/python_mscl_demo/python_mscl_demo_simple.py
'''


#  How to run this demo file successfully after you've installed the python3-mscl package.
#  following the steps in https://github.com/LORD-MicroStrain/MSCL/blob/master/HowToUseMSCL.md?
#
#  1)Find the usb device name of the sensor: 
#     For Linux, it may be "/dev/ttyUSB0" or "/dev/ttyACM0" or similar.
#     For windows, it may be "COM3" or "COM4" or similar.
#     You may need help by command:  lsusb and ls /dev/ttyU* or ls /dev/ttyA*
#  2)Change the access permission of the usb device to accessable for the current user of the system, such as
#     Terminal #  sudo chmod 666 /dev/ttyACM0 
#  3)Run the source file directly, such as:
#     Terminal # python3 ./python_mscl_demo_simple.py


###### Here begins!  ######

# import the mscl library
import sys
sys.path.append("/usr/share/python3-mscl/")
import mscl

#TODO: change these constants to match your setup
# COM_PORT = "COM4"
# Before your run this file, please change the access permission of the device, such as 
# sudo chmod 666 /dev/ttyACM0

COM_PORT = '/dev/ttyACM0'

connection = mscl.Connection.Serial(COM_PORT, 921600)

node = mscl.InertialNode(connection)

# ping the Node
SUCCESS = node.ping()
print("Ping Success?:", SUCCESS)

# put the Inertial Node into its idle state
# node.setToIdle()

# create object for MipChannels
ahrsImuChs = mscl.MipChannels()
# configurate the data stream for collection or output
ahrsImuChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_SENSOR_SCALED_ACCEL_VEC, mscl.SampleRate.Hertz(20)))
ahrsImuChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_SENSOR_EULER_ANGLES, mscl.SampleRate.Hertz(20)))

# set the active channesl for the AHRS/IMU class on the Node
node.setActiveChannelFields(mscl.MipTypes.CLASS_AHRS_IMU, ahrsImuChs)

# start sampling on the AHRS/IMU class of the Node
node.enableDataStream(mscl.MipTypes.CLASS_AHRS_IMU)

# use the resume command to return to the mode before setToIdle
# node.resume()

while SUCCESS:
    # get all the packets that have been collected, with a timeout of 500 miliseconds
    packets = node.getDataPackets(500)

    for packet in packets:
        packet.descriptorSet()  # the descriptor set of the packet

        # get all of the points in the packet
        points = packet.data()

        for dataPoint in points:
            # print("Channel Name:", dataPoint.channelName())      # the name of the channel for this point
            # print("Data Type:", dataPoint.storedAs())            # the valueType that the data is stored as
            # print("Data to float:", dataPoint.as_float())        # get the value as a float
            print("Data Frame: %-15s" % dataPoint.channelName() + " |  %10f"  % dataPoint.as_float())

