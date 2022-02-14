/*
 * @Date: 2022-02-11 22:16:13
 * @LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
 * @LastEditTime: 2022-02-14 10:39:28
 * @FilePath: /example_cpp/cpp_mscl_demo_simple.cpp
 */


/*
 * How to run this demo file successfully after you've installed the c++-mscl package
 * following the steps in https://github.com/LORD-MicroStrain/MSCL/blob/master/HowToUseMSCL.md?
 * 
 * 1) Find the usb device name of the sensor: 
 *    For Linux, it may be "/dev/ttyUSB0" or "/dev/ttyACM0" or similar.
 *    For windows, it may be "COM3" or "COM4" or similar.
 *    You may need help by command:  lsusb and ls /dev/ttyU* or ls /dev/ttyA*
 * 2) Change the access permission of the usb device to accessable for the current user of the system, such as
 *    Terminal #  sudo chmod 666 /dev/ttyACM0 
 * 3) Change the cwd to the folder of this demo source file.
 * 4) Complie the file by gcc on the terminal:
 *    Terminal #  g++ -I/usr/share/c++-mscl/source -I/usr/share/c++-mscl/Boost/include cpp_mscl_demo_simple.cpp -o cpp_demo_1 -L/usr/share/c++-mscl -lmscl -lstdc++ -std=c++11 -lpthread -pthread
 * 5) run the executable file produced:
 *    Terminal #  LD_PRELOAD=/usr/share/c++-mscl/libmscl.so ./cpp_demo_1
 */


#include <iostream>
using namespace std;
#include "mscl/mscl.h"

int main(int argc, char **argv)
{
    const string COM_PORT = "/dev/ttyACM0";
    // create the connection object with port and baud rate
    mscl::Connection connection = mscl::Connection::Serial(COM_PORT);

    // create the InertialNode, passing in the connection
    mscl::InertialNode node(connection);


    // ping the node
    bool SUCCESS = node.ping();
    cout << "Node Information: " << endl;
    cout << "Model Name: " << node.modelName() << endl;
    cout << "Model Number: " << node.modelNumber() << endl;
    cout << "Serial: " << node.serialNumber() << endl;
    cout << "Firmware: " << node.firmwareVersion().str() << endl << endl;
    

    // put the Inertial Node into its Idle state
    
    node.setToIdle();

    // get all of the active channels for the GPS category on the Node
    // mscl::MipChannels activeChs = node.getActiveChannelFields(mscl::MipTypes::CLASS_AHRS_IMU);

    // configurate the data stream for collection or output
    mscl::MipChannels ahrsImuChs;
    ahrsImuChs.push_back(mscl::MipChannel(mscl::MipTypes::CH_FIELD_SENSOR_SCALED_ACCEL_VEC, mscl::SampleRate::Hertz(20)));
    ahrsImuChs.push_back(mscl::MipChannel(mscl::MipTypes::CH_FIELD_SENSOR_EULER_ANGLES, mscl::SampleRate::Hertz(20)));

    // mscl::MipChannels estFilterChs;
    // estFilterChs.push_back(mscl::MipChannel(mscl::MipTypes::CH_FIELD_ESTFILTER_ESTIMATED_GYRO_BIAS, mscl::SampleRate::Hertz(100)));

    //set the active channels for the different data classes on the Node
    node.setActiveChannelFields(mscl::MipTypes::CLASS_AHRS_IMU, ahrsImuChs);
    // node.setActiveChannelFields(mscl::MipTypes::CLASS_ESTFILTER, estFilterChs);

    // start sampling the active channels on the AHRS/IMU class of the Node
    node.enableDataStream(mscl::MipTypes::CLASS_AHRS_IMU);

    // use the resume command to return to the mode before setToIdle
    node.resume();

    // while(SUCCESS)
    // {
        // get all the packets that have been collected, with a timeout of 500 miliseconds

    mscl::MipDataPackets packets = node.getDataPackets(500, 1);

    for(mscl::MipDataPacket packet : packets)
    {
        packet.descriptorSet(); // the descriptor set of the packet

        // get all of the points in the packet
        mscl::MipDataPoints points = packet.data();

        for(mscl::MipDataPoint dataPoint : points)
        {
            cout<<"Data frame:"<<right<<setw(15)<<dataPoint.channelName()<<" |"<<right<<setw(3)<<dataPoint.storedAs()<<" | "<<right<<setw(15)<<dataPoint.as_float()<<endl;
        }
    }

    // }

    return 0;

}

