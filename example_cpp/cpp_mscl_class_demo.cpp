/*
 * @Date: 2022-02-13 14:54:30
 * @LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
 * @LastEditTime: 2022-02-16 15:58:24
 * @FilePath: /Downloads/mscl_demo/example_cpp/cpp_mscl_class_demo.cpp
 */


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>


using namespace std;
#include "mscl/mscl.h"




class AHRS_IMU
{

private:

    mscl::Connection connection;
    mscl::MipChannels ahrsImuChs;

    bool SUCCESS;

    // data type for integration of data stream

    struct EULER_ANGLE{
        float roll;
        float pitch;
        float yaw;
    };

    struct ACCELERATION{
        float accel_x;
        float accel_y;
        float accel_z;
    };

public:

    struct ACCELERATION_EULER_ANGLE{
        ACCELERATION Acceleration;
        EULER_ANGLE Euler_Angle;

        // constructor of structure
        ACCELERATION_EULER_ANGLE()
        {
            Acceleration = {0.0, 0.0, 0.0};
            Euler_Angle = {0.0, 0.0, 0.0};
        }

        ACCELERATION_EULER_ANGLE(ACCELERATION Acceleration, EULER_ANGLE Euler_Angle)
        {
            Acceleration = Acceleration;
            Euler_Angle = Euler_Angle;
        }
    };

    ACCELERATION_EULER_ANGLE acceleration_euler_angle;


public:
    /* data */

    ACCELERATION_EULER_ANGLE accele_euler;
    vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> acceleration_euler_list;

    /* data */


public:

    AHRS_IMU();

    ~AHRS_IMU() {};

    void setToIdle();

    void resumeDataStream();

    void EnableDataStream_AHRS_IMU();

    void setDataChannel_Accel_IMU(int SampleRate);

    void setDataChannel_Euler_Angles(int SampleRate);

    AHRS_IMU::ACCELERATION_EULER_ANGLE parseDataPacket_AHRS_IMU(int Timeout_ms);

    //TODO: not finish Method or feature for multi-packets Data access
    vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> parseDataStream_AHRS_IMU(int Timeout_ms, int PacketNumber);

    //TODO: not finish Method or feature for data recording and plotting
    string createCSV();
    string recordDataToCSV();
    void plotDataCSV(string csv_file_name);

};


AHRS_IMU::AHRS_IMU() //(/* args */)
{
    // initialize the acceleration and euler angle data structure
    acceleration_euler_angle = {{0.0, 0.0, 0.0},{0.0, 0.0, 0.0}};

    // AHRS_IMU::ACCELERATION_EULER_ANGLE acceleration_euler_list[1000000] = {};

    // define the USB port of the device
    const string USB_PORT = "/dev/ttyACM0";
    
    // create the connection object with port and baud rate
    AHRS_IMU::connection = mscl::Connection::Serial(USB_PORT);

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


AHRS_IMU::ACCELERATION_EULER_ANGLE AHRS_IMU::parseDataPacket_AHRS_IMU(int Timeout_ms)
{
    cout << "\r\nParse One Data Packet ..." << endl;

    struct AHRS_IMU::EULER_ANGLE euler_angle = {0.0, 0.0, 0.0};
    struct AHRS_IMU::ACCELERATION acceleration = {0.0, 0.0, 0.0};

    mscl::InertialNode node(AHRS_IMU::connection);
    mscl::MipDataPackets packets = node.getDataPackets(Timeout_ms);

    for(mscl::MipDataPacket packet : packets)
    {
        packet.descriptorSet(); // the descriptor set of the packet

        // get all of the points in the packet
        mscl::MipDataPoints points = packet.data();

        for(mscl::MipDataPoint dataPoint : points)
        {
            // cout << "Data frame:" << right<<setw(15) << dataPoint.channelName() << " |"<<right<<setw(3) << dataPoint.storedAs()<<" | "<<right<<setw(15)<<dataPoint.as_float()<<endl;
            
            if (dataPoint.channelName() == string("roll"))
                euler_angle.roll  = dataPoint.as_float();
            if (dataPoint.channelName() == string("pitch"))
                euler_angle.pitch = dataPoint.as_float();
            if (dataPoint.channelName() == string("yaw"))
                euler_angle.yaw   = dataPoint.as_float();
            if (dataPoint.channelName() == string("scaledAccelX"))
                acceleration.accel_x = dataPoint.as_float();
            if (dataPoint.channelName() == string("scaledAccelY"))
                acceleration.accel_y = dataPoint.as_float();
            if (dataPoint.channelName() == string("scaledAccelZ"))
                acceleration.accel_z = dataPoint.as_float();
        }
    }

    acceleration_euler_angle.Acceleration = acceleration;
    acceleration_euler_angle.Euler_Angle = euler_angle;
    
    return acceleration_euler_angle;

}


// multi packets for Acceleration and Euler Angle

vector <AHRS_IMU::ACCELERATION_EULER_ANGLE>  AHRS_IMU::parseDataStream_AHRS_IMU(int Timeout_ms, int PacketNumber)
{
    cout << "\r\nParse Data Stream ..." << endl;

    struct AHRS_IMU::EULER_ANGLE euler_angle = {0.0, 0.0, 0.0};
    struct AHRS_IMU::ACCELERATION acceleration = {0.0, 0.0, 0.0};

    // vector<AHRS_IMU::ACCELERATION_EULER_ANGLE>  acceleration_euler_list;
    // acceleration_euler_list.push_back(ACCELERATION_EULER_ANGLE());

    mscl::InertialNode node(AHRS_IMU::connection);
    mscl::MipDataPackets packets = node.getDataPackets(Timeout_ms, PacketNumber);

    for(int i=0; i<PacketNumber; i++)
    {
        for(mscl::MipDataPacket packet : packets)
        {
            packet.descriptorSet(); // the descriptor set of the packet

            // get all of the points in the packet
            mscl::MipDataPoints points = packet.data();

            for(mscl::MipDataPoint dataPoint : points)
            {
                // cout << "Data frame:" << right<<setw(15) << dataPoint.channelName() << " |"<<right<<setw(3) << dataPoint.storedAs()<<" | "<<right<<setw(15)<<dataPoint.as_float()<<endl;
                
                if (dataPoint.channelName() == string("roll"))
                    euler_angle.roll  = dataPoint.as_float();
                if (dataPoint.channelName() == string("pitch"))
                    euler_angle.pitch = dataPoint.as_float();
                if (dataPoint.channelName() == string("yaw"))
                    euler_angle.yaw   = dataPoint.as_float();
                if (dataPoint.channelName() == string("scaledAccelX"))
                    acceleration.accel_x = dataPoint.as_float();
                if (dataPoint.channelName() == string("scaledAccelY"))
                    acceleration.accel_y = dataPoint.as_float();
                if (dataPoint.channelName() == string("scaledAccelZ"))
                    acceleration.accel_z = dataPoint.as_float();

            }

            acceleration_euler_list.push_back({{acceleration},{euler_angle}});


        }
        
        if (i==PacketNumber-1)
        {
            break;
        }
    }
    return acceleration_euler_list;
}

// TODO: create a CSV file for data recording
// string createCSV()
// {
    
// }

// TODO: record data stream into CSV file
// string recordDataToCSV()
// {

// }

// TODO: plot data stream from CSV file
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

    // Parse one packet of data stream
    imu.accele_euler = imu.parseDataPacket_AHRS_IMU(500);
    cout <<left<<setw(15) << "Acceleration " <<":" <<right<<setw(15)<< imu.accele_euler.Acceleration.accel_x << " | " <<right<<setw(15)<< imu.accele_euler.Acceleration.accel_y << " | " <<right<<setw(15)<<  imu.accele_euler.Acceleration.accel_z << endl;
    cout <<left<<setw(15) << "Euler Angle " <<":" <<right<<setw(15)<< imu.accele_euler.Euler_Angle.roll << " | " <<right<<setw(15)<< imu.accele_euler.Euler_Angle.pitch << " | " <<right<<setw(15)<< imu.accele_euler.Euler_Angle.yaw << endl;
    

    // Parse PacketNumber packets of data stream
    int PacketNumber = 10;
    vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> accel_euler_list = imu.parseDataStream_AHRS_IMU(500, PacketNumber);
    for(int i=0; i<PacketNumber; i++)
    {
        cout <<left<<setw(15) << "Acceleration " <<":" <<right<<setw(15)<< accel_euler_list[i].Acceleration.accel_x << " | " << endl;
        cout <<left<<setw(15) << "Euler Angle " <<":" <<right<<setw(15)<< accel_euler_list[i].Euler_Angle.roll << " | " << endl;
    }    


    // TODO: Parse PacketNumber packets and record data stream into CSV file

}

// Testing demo end.
