'''
Date: 2022-02-10 10:58:08
LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
LastEditTime: 2022-02-10 16:06:01
FilePath: /Python/setCurrentConfig.py
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
        ahrsImuChs = mscl.MipChannels()
        ahrsImuChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_SENSOR_SCALED_ACCEL_VEC, mscl.SampleRate.Hertz(500)))
        ahrsImuChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_SENSOR_SCALED_GYRO_VEC, mscl.SampleRate.Hertz(100)))

        #apply to the node
        node.setActiveChannelFields(mscl.MipTypes.CLASS_AHRS_IMU, ahrsImuChs)

    #if the node supports Estimation Filter
    if node.features().supportsCategory(mscl.MipTypes.CLASS_ESTFILTER):
        estFilterChs = mscl.MipChannels()
        estFilterChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_ESTFILTER_ESTIMATED_GYRO_BIAS, mscl.SampleRate.Hertz(100)))

        #apply to the node
        node.setActiveChannelFields(mscl.MipTypes.CLASS_ESTFILTER, estFilterChs)

    #if the node supports GNSS
    if node.features().supportsCategory(mscl.MipTypes.CLASS_GNSS):
        gnssChs = mscl.MipChannels()
        gnssChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_GNSS_LLH_POSITION, mscl.SampleRate.Hertz(1)))

        #apply to the node
        node.setActiveChannelFields(mscl.MipTypes.CLASS_GNSS, gnssChs)

    node.setPitchRollAid(True)

    node.setAltitudeAid(False)

    offset = mscl.PositionOffset(0.0, 0.0, 0.0)
    node.setAntennaOffset(offset)

except mscl.Error as e:
    print ("Error:", e)
