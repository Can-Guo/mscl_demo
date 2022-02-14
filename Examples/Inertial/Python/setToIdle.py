'''
Date: 2022-02-10 10:58:08
LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
LastEditTime: 2022-02-10 16:05:49
FilePath: /Python/setToIdle.py
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

    node.setToIdle()

    #Note: you can also disable the datastream for each class/category
    #      seperately if desired, by using the enableDataStream command shown in
    #      the startSampling example, but passing a second parameter of 'false'

except mscl.Error as e:
    print ("Error:", e)
