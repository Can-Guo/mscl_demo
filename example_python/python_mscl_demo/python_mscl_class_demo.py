'''
Date: 2022-02-12 13:47:06
LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
LastEditTime: 2022-02-14 10:41:04
FilePath: /example_python/python_mscl_demo/python_mscl_class_demo.py
'''


from cProfile import label
import sys
sys.path.append("/usr/share/python3-mscl/")
import mscl 
import time
from datetime import datetime
import csv
import pandas as pd 
import matplotlib.pyplot as plt 
import numpy as np 

class IMU_class(object):

    def __init__(self):

        # Make sure the USB port of the IMU device, you may need to change!
        self.USB_PORT = '/dev/ttyACM0'

        try:
            # create Connection with specified USB port and Baud
            self.connection = mscl.Connection.Serial(self.USB_PORT, 921600)

            # create Node for the Connection created before
            self.node = mscl.InertialNode(self.connection)

            # ping the Node
            self.SUCCESS = self.node.ping()
            
            if self.SUCCESS == True:
                print("--------------------------------")
                print("Connected! Device Information-->\r")
                print("Model Name: %s \r" % self.node.modelName())
                print("Model Number: %s \r" % self.node.modelNumber())
                print("Serial Number: %s \r" % self.node.serialNumber())
                print("Firmware Version: %s \r" % str(self.node.firmwareVersion()))
                print("Initialization is done! \r")
                print("--------------------------------\r\n")

            # create object for MipChannels
            self.ahrsImuChs = mscl.MipChannels()

        except mscl.Error as e:
            print("MSCL Error Message:", e)


    def setToIdle(self):
        return self.node.setToIdle()


    def resumeDataStream(self):
        self.node.resume()


    def EnableDataStream_AHRS_IMU(self):

        try:
            # set the active channesl for the AHRS/IMU class on the Node
            self.node.setActiveChannelFields(mscl.MipTypes.CLASS_AHRS_IMU, self.ahrsImuChs)

            # start sampling on the AHRS/IMU class of the Node
            self.node.enableDataStream(mscl.MipTypes.CLASS_AHRS_IMU)

            # use the resume command to return to the mode before setToIdle
            # self.resumeDataStream()

        except mscl.Error as e:
            print("MSCL Error Message:", e)


    def setDataChannel_Accel_Vel(self, SampleRate : int):

        self.ahrsImuChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_SENSOR_SCALED_ACCEL_VEC, mscl.SampleRate.Hertz(SampleRate)))

        self.EnableDataStream_AHRS_IMU()


    def setDataChannel_Euler_Angles(self, SampleRate : int):

        self.ahrsImuChs.append(mscl.MipChannel(mscl.MipTypes.CH_FIELD_SENSOR_EULER_ANGLES, mscl.SampleRate.Hertz(SampleRate)))
        
        self.EnableDataStream_AHRS_IMU()


    def setDataChannel_AHRS_IMU(self, CH_Filed : mscl.MipTypes, SampleRate : int):
        '''
        Set the data channel to access other data channel field of the device provided.
        Please refer to http://lord-microstrain.github.io/MSCL/Documentation/MSCL%20Documentation/index.html#CClass:MipTypes:ChannelField
        '''

        self.ahrsImuChs.append(mscl.MipChannel(CH_Filed, mscl.SampleRate.Hertz(SampleRate)))
        
        self.EnableDataStream_AHRS_IMU()


    def parseDataStream_AHRS_IMU(self, Timeout_ms : int, PacketNumber : int):
        
        try:
            # get all the packets that have been collected, with a timeout of Timeout_ms miliseconds
            packets = self.node.getDataPackets(Timeout_ms, PacketNumber)

            for packet in packets:
                packet.descriptorSet()  # the descriptor set of the packet

                # get all of the points in the packet
                points = packet.data()

                for dataPoint in points:
                    print("Data Frame: %-20s" % dataPoint.channelName() + " |  %10s"  % dataPoint.as_string())

        except mscl.Error as e:
            print("MSCL Error Message: ", e)


    def createCSV(self):
        time_mark = datetime.now()
        file_name = './csv/data_' + str(time_mark) + '.csv'

        with open( file_name , 'a') as file:
            writer = csv.writer(file, delimiter = ',', quotechar = '"', quoting = csv.QUOTE_MINIMAL)
            # writer.writerow(['time', 'accel_x', 'accel_y', 'acce_z', 'roll', 'pitch', 'yaw'])
            writer.writerow(['timestamp', 'roll', 'pitch', 'yaw'])

        file.close()

        return file_name
    
    
    def recordDataToCSV(self):

        # Create a CSV file first to record the data
        csv_file = self.createCSV()

        while self.SUCCESS:

            current_time = datetime.now()
            packets = self.node.getDataPackets(500, 1)

            for packet in packets:
                packet.descriptorSet()
                points = packet.data()
            
                for dataPoint in points:
                    if dataPoint.channelName() == 'roll':
                        roll = dataPoint.as_float()
                    if dataPoint.channelName() == 'pitch':
                        pitch = dataPoint.as_float()
                    if dataPoint.channelName() == 'yaw':
                        yaw = dataPoint.as_float()
                
            with open( csv_file, 'a') as file:
                # writer = csv.DictWriter(file, fieldnames=['time','accel_x','accel_y','accel_z','roll','pitch','yaw'])
                writer = csv.DictWriter(file, fieldnames=['timestamp','roll','pitch','yaw'])
                # writer.writerow({'time':current,'accel_x':accel_x,'accel_y':accel_y,'accel_z':accel_z,'roll':roll,'pitch':pitch,'yaw':yaw})            
                writer.writerow({'timestamp':current_time,'roll':roll,'pitch':pitch,'yaw':yaw})

            file.close()

    
    def plotDataCSV(self, csv_file):
        csv_file = './csv/' + csv_file
        data_frame = pd.read_csv(csv_file)

        frame_number = len(data_frame['timestamp'])
        print("frame number:", frame_number)
        time_sequence = np.linspace(0, frame_number/500, frame_number)

        # delete specific column of data in Dataframe, such as timestamp column
        data_frame.drop(['timestamp'], axis = 1, inplace = True)  

        data_list = np.array(data_frame)

        roll_record = data_list[:,0]
        pitch_record = data_list[:,1]
        yaw_record = data_list[:,2]

        plt.figure(figsize=[20,10])

        plt.plot(time_sequence, roll_record, 'r--', label = 'roll angle')
        plt.plot(time_sequence, pitch_record, 'g-.', label = 'pitch angle')
        plt.plot(time_sequence, yaw_record, 'b-', label = 'yaw angle')

        plt.ylim([-np.pi, np.pi])
        plt.xlim(time_sequence[0],time_sequence[frame_number-1])

        plt.xticks(fontsize = 10)
        plt.yticks(fontsize = 10)

        plt.ylabel('angle (radian', fontsize = 15)
        plt.xlabel('timestamp', fontsize = 15)

        plt.legend(fontsize = 15)
        plt.grid()

        current = datetime.now()
        fig_name = './fig/' + str(current) + '.png'
        plt.savefig(fig_name,dpi=600)

        plt.show()

        return 


########### --Test demo begins here-- ############

IMU = IMU_class()
# print current time of the system
print("Current time :", datetime.now())

# set the data channel to access the Euler angles
IMU.setDataChannel_Euler_Angles(100)
# set the data channel to access the 3-axis acclerelation
# IMU.setDataChannel_Accel_Vel(500)
# IMU.setDataChannel_AHRS_IMU(mscl.MipTypes.CH_FIELD_SENSOR_DELTA_VELOCITY_VEC, 100)

# wait for 0.1 second, because we want the latest data from the device
time.sleep(0.1)

# 1) Print the data streaming in the terminal, easy to check
IMU.parseDataStream_AHRS_IMU(500, IMU.node.totalPackets())

# 2) Save the data streaming into a file.csv, easy for plotting of the data
# IMU.recordDataToCSV()

# 3) plot the data streaming in file.csv, easy to demonstration
# IMU.plotDataCSV('data_2022-02-13 12:58:57.227380.csv')

########### --Test demo end-- ###################