/*
 * @Date: 2022-02-13 14:54:30
 * @LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
 * @LastEditTime: 2022-02-14 00:27:00
 * @FilePath: /example_cpp/cpp_mscl_class_demo.cpp
 */


#include <iostream>
#include <string.h>
#include <stdio.h>

// #include <tchar.h>

using namespace std;
#include "mscl/mscl.h"


class AHRS_IMU
{
private:
    mscl::Connection connection;

    // mscl::InertialNode node;
    
    mscl::MipChannels ahrsImuChs;

    bool SUCCESS;

    /* data */

public:

    AHRS_IMU();

    ~AHRS_IMU() {};

    void setToIdle();

    void resumeDataStream();

    void EnableDataStream_AHRS_IMU();

    void setDataChannel_Accel_IMU(int SampleRate);

    void setDataChannel_Euler_Angles(int SampleRate);

    void parseDataStream_AHRS_IMU(int Timeout_ms, int PacketNumber);

    string createCSV();

    void recordDataToCSV();

    void plotDataCSV(string csv_file_name);

};


AHRS_IMU::AHRS_IMU() //(/* args */)
{
    const string COM_PORT = "/dev/ttyACM0";
    
    // create the connection object with port and baud rate
    AHRS_IMU::connection = mscl::Connection::Serial(COM_PORT);

    // create the InertialNode, passing in the connection
    mscl::InertialNode node(AHRS_IMU::connection);

    // create a MipChannel for configurate
    mscl::MipChannel ahrsImuChs;

    // ping the node
    AHRS_IMU::SUCCESS = node.ping();

    if(AHRS_IMU::SUCCESS == true)
    {
        cout << "Node Information: " << endl;
        cout << "Model Name: " << node.modelName() << endl;
        cout << "Model Number: " << node.modelNumber() << endl;
        cout << "Serial: " << node.serialNumber() << endl;
        cout << "Firmware: " << node.firmwareVersion().str() << endl << endl;
    }

}


void AHRS_IMU::setToIdle()
{
    mscl::InertialNode node(AHRS_IMU::connection);
    node.setToIdle();
}


void AHRS_IMU::resumeDataStream()
{
    mscl::InertialNode node(AHRS_IMU::connection);
    node.resume();
}


void AHRS_IMU::EnableDataStream_AHRS_IMU()
{
    cout << "\r\nEnable Data Stream..." << endl;

    mscl::InertialNode node(AHRS_IMU::connection);

    //set the active channels for the different data classes on the Node
    node.setActiveChannelFields(mscl::MipTypes::CLASS_AHRS_IMU, AHRS_IMU::ahrsImuChs);

    // start sampling the active channels on the AHRS/IMU class of the Node
    node.enableDataStream(mscl::MipTypes::CLASS_AHRS_IMU);

    // node.resume();

}


void AHRS_IMU::setDataChannel_Accel_IMU(int SampleRate)
{
    cout << "Set Acceleration Data Channel." << endl;
    AHRS_IMU::ahrsImuChs.push_back(mscl::MipChannel(mscl::MipTypes::CH_FIELD_SENSOR_SCALED_ACCEL_VEC, mscl::SampleRate::Hertz(SampleRate)));
}


void AHRS_IMU::setDataChannel_Euler_Angles(int SampleRate)
{
    cout << "Set Euler Angles Data Channel." << endl;
    AHRS_IMU::ahrsImuChs.push_back(mscl::MipChannel(mscl::MipTypes::CH_FIELD_SENSOR_EULER_ANGLES, mscl::SampleRate::Hertz(SampleRate)));
}


void AHRS_IMU::parseDataStream_AHRS_IMU(int Timeout_ms, int PacketNumber)
{
    cout << "\r\nParse Data Stream ..." << endl;

    mscl::InertialNode node(AHRS_IMU::connection);

    mscl::MipDataPackets packets = node.getDataPackets(Timeout_ms, PacketNumber);

    // while(AHRS_IMU::SUCCESS)
    // {

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

}


// string createCSV()
// {
    
// }


// void recordDataToCSV()
// {

// }


// void plotDataCSV(string csv_file_name)
// {
    
// }


// Testing demo for this Class deployment

int main(int argc, char ** argv)
{

    AHRS_IMU imu;
    imu.setDataChannel_Accel_IMU(100);
    imu.setDataChannel_Euler_Angles(100);
    imu.EnableDataStream_AHRS_IMU();
    imu.parseDataStream_AHRS_IMU(500, 100);

    return 0;

}

// Testing demo end.
