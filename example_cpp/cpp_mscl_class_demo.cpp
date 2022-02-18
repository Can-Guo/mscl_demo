/*
 * @Date: 2022-02-13 14:54:30
 * @LastEditors: Guo Yuqin,12032421@mail.sustech.edu.cn
 * @LastEditTime: 2022-02-18 09:40:30
 * @FilePath: /example_cpp/cpp_mscl_class_demo.cpp
 */


#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <chrono>
using namespace std;

#include "rapidcsv.h"
#include <cmath>
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

private: 
    /* data */
    ACCELERATION_EULER_ANGLE acceleration_euler_angle;
    /* data */

public:

    /* data */
    
    ACCELERATION_EULER_ANGLE accele_euler;
    vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> acceleration_euler_list;
    vector <string> DataLabelName;

    //TODO:if you add other data stream, please modified this DataSelecter.
    enum DataSelecter {Null=0x00, Accel=0x01, Euler=0x10, Accel_and_Euler=0x11};
    enum DataSelecter dataSelecter = Null; 

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

    //Method or feature for multi-packets Data access
    vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> parseDataStream_AHRS_IMU(int Timeout_ms, int PacketNumber);

    //Method or feature for data recording
    string createCSV();
    string recordDataToCSV(vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> acceleration_euler_angle);

    //TODO: Method to plot the data stream from CSV file generated before
    string plotDataCSV(string csv_file_name,float executation_time);

};


AHRS_IMU::AHRS_IMU() //(/* args */)
{
    // initialize the acceleration and euler angle data structure
    acceleration_euler_angle = {{0.0, 0.0, 0.0},{0.0, 0.0, 0.0}}; 

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
    if(AHRS_IMU::dataSelecter == 0x00)
    {
        AHRS_IMU::DataLabelName = {"Acceleration_x", "Acceleration_y", "Acceleration_z"};
        dataSelecter = Accel;
    }
    else if (AHRS_IMU::dataSelecter == 0x10)
    {
        AHRS_IMU::DataLabelName.push_back("Acceleration_x");
        AHRS_IMU::DataLabelName.push_back("Acceleration_y");
        AHRS_IMU::DataLabelName.push_back("Acceleration_z");
        dataSelecter = Accel_and_Euler;
    }
    AHRS_IMU::ahrsImuChs.push_back(mscl::MipChannel(mscl::MipTypes::CH_FIELD_SENSOR_SCALED_ACCEL_VEC, mscl::SampleRate::Hertz(SampleRate)));
}


void AHRS_IMU::setDataChannel_Euler_Angles(int SampleRate)
{
    cout << "Set Euler Angles Data Channel." << endl;
    if(AHRS_IMU::dataSelecter == 0x00)
    {
        AHRS_IMU::DataLabelName = {"roll", "pitch", "yaw"};
        dataSelecter = Euler;
    }
    else if (AHRS_IMU::dataSelecter == 0x01)
    {
        AHRS_IMU::DataLabelName.push_back("roll");
        AHRS_IMU::DataLabelName.push_back("pitch");
        AHRS_IMU::DataLabelName.push_back("yaw");
        dataSelecter = Accel_and_Euler;
    }
    AHRS_IMU::ahrsImuChs.push_back(mscl::MipChannel(mscl::MipTypes::CH_FIELD_SENSOR_EULER_ANGLES, mscl::SampleRate::Hertz(SampleRate)));
}


AHRS_IMU::ACCELERATION_EULER_ANGLE AHRS_IMU::parseDataPacket_AHRS_IMU(int Timeout_ms)
{
    cout << "\r\nParse One Data Packet ..." << endl;

    struct AHRS_IMU::EULER_ANGLE euler_angle = {0.0, 0.0, 0.0};
    struct AHRS_IMU::ACCELERATION acceleration ={0.0, 0.0, 0.0};

    mscl::InertialNode node(AHRS_IMU::connection);
    mscl::MipDataPackets packets = node.getDataPackets(Timeout_ms);

    for(mscl::MipDataPacket packet : packets)
    {
        packet.descriptorSet(); // the descriptor set of the packet

        // get all of the data points in the packet
        mscl::MipDataPoints points = packet.data();

        for(mscl::MipDataPoint dataPoint : points)
        {
            // Print out data to check or debug.
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

    struct AHRS_IMU::ACCELERATION_EULER_ANGLE accel_euler_buffer;

    mscl::InertialNode node(AHRS_IMU::connection);
    

    for(int i=0; i<PacketNumber; i++)
    {
        mscl::MipDataPackets packets = node.getDataPackets(Timeout_ms, 1);

        for(mscl::MipDataPacket packet : packets)
        {
            // packet.descriptorSet(); // the descriptor set of the packet

            // get all of the points in the packet
            mscl::MipDataPoints data = packet.data();
            mscl::MipDataPoint dataPoint;

            for(unsigned int itr = 0; itr < data.size(); itr++)
            {
                dataPoint = data[itr];

                // Print out data to check or debug.
                // cout    << "Data frame:" << right<<setw(15) << dataPoint.channelName() << " |"<<right<<setw(3) 
                //         << dataPoint.storedAs()<<" | "<<right<<setw(15)<<dataPoint.as_float()<<endl;
                
                if (dataPoint.channelName() == string("roll"))
                    accel_euler_buffer.Euler_Angle.roll = dataPoint.as_float();
                if (dataPoint.channelName() == string("pitch"))
                    accel_euler_buffer.Euler_Angle.pitch = dataPoint.as_float();
                if (dataPoint.channelName() == string("yaw"))
                    accel_euler_buffer.Euler_Angle.yaw = dataPoint.as_float();
                if (dataPoint.channelName() == string("scaledAccelX"))
                    accel_euler_buffer.Acceleration.accel_x = dataPoint.as_float();
                if (dataPoint.channelName() == string("scaledAccelY"))
                    accel_euler_buffer.Acceleration.accel_y = dataPoint.as_float();
                if (dataPoint.channelName() == string("scaledAccelZ"))
                    accel_euler_buffer.Acceleration.accel_z = dataPoint.as_float();
            }

            // Print out the data stream to check or debugging.
            // cout    << "Data Before push_back : " 
            //         << accel_euler_buffer.Euler_Angle.roll << " | " << accel_euler_buffer.Euler_Angle.pitch << " | "
            //         << accel_euler_buffer.Euler_Angle.yaw << " | " << accel_euler_buffer.Acceleration.accel_x << " | "
            //         << accel_euler_buffer.Acceleration.accel_y << " | " << accel_euler_buffer.Acceleration.accel_z << endl;
                    
            acceleration_euler_list.push_back(accel_euler_buffer);

        }
    }
        
    return acceleration_euler_list;
}


// TODO: create a CSV file for data recording
string AHRS_IMU::createCSV()
{
    auto now = chrono::system_clock::now();
    time_t tt;
    tt = chrono::system_clock::to_time_t (now);
    ostringstream oss;
    oss << ctime(&tt);
    string time = oss.str(); 
    // TODO: Change to meet your personal system path.
    string filename = "/home/guoyucan/Downloads/mscl_demo/example_cpp/csv/" + string(time) + ".csv";

    ofstream fout(filename.c_str());
    fout.close();
    return string(filename);
}


// TODO: record data stream into CSV file
string AHRS_IMU::recordDataToCSV(vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> acceleration_euler_list)
{
    // Step 0: open a CSV file
    string csv_file_name = AHRS_IMU::createCSV();
    ofstream fout(csv_file_name.c_str());

    // step 1: write column name of the data into the first row of the CSV file
    for(int i=0; i<(AHRS_IMU::DataLabelName.size()-1); i++)
    {
        fout << DataLabelName[i] << ',';
    }
    fout << DataLabelName[AHRS_IMU::DataLabelName.size()-1] << endl;
    
    // step 2: write all the data packets into CSV file, row by row
    for(int i=0; i< (AHRS_IMU::acceleration_euler_list.size()); i++)
    {
        if(AHRS_IMU::dataSelecter == 0x00 or AHRS_IMU::acceleration_euler_list.size() == 0)
        {
            cout << "No Data Packet Found! Please check!" << endl;
        }
        // Only enable the Acceleration Data Streaming
        else if (AHRS_IMU::dataSelecter == 0x01)
        {
            fout    << acceleration_euler_list[i].Acceleration.accel_x << "," 
                    << acceleration_euler_list[i].Acceleration.accel_y << ","
                    << acceleration_euler_list[i].Acceleration.accel_z << endl;
        }

        // Only enable the Euler Angle Data Streaming
        else if (AHRS_IMU::dataSelecter == 0x10)
        {
            fout    << acceleration_euler_list[i].Euler_Angle.roll << ","
                    << acceleration_euler_list[i].Euler_Angle.pitch << ","
                    << acceleration_euler_list[i].Euler_Angle.yaw << endl;
        }

        // Enable Both the Acceleration and Euler Angle 
        else if (AHRS_IMU::dataSelecter == 0x11)
        {

            // Print out the data to checking or debugging.
            // cout    <<left<<setw(15) << "Acceleration after push_back" <<":" <<right<<setw(15)
            //         << acceleration_euler_list[i].Acceleration.accel_x << " | " 
            //         <<right<<setw(15)<< acceleration_euler_list[i].Acceleration.accel_y << " | " 
            //         <<right<<setw(15)<< acceleration_euler_list[i].Acceleration.accel_z << endl;

            // cout    <<left<<setw(15) << "Euler Angle after push_back" <<":" <<right<<setw(15)
            //         << acceleration_euler_list[i].Euler_Angle.roll << " | " 
            //         <<right<<setw(15)<< acceleration_euler_list[i].Euler_Angle.pitch << " | " 
            //         <<right<<setw(15)<< acceleration_euler_list[i].Euler_Angle.yaw << endl;


            // Acceleration Data Stream is before the Euler Angle Data Stream

            if(AHRS_IMU::DataLabelName[0] == "Acceleration_x")
            {
                
                fout    << acceleration_euler_list[i].Acceleration.accel_x << "," 
                        << acceleration_euler_list[i].Acceleration.accel_y << ","
                        << acceleration_euler_list[i].Acceleration.accel_z << ","
                        << acceleration_euler_list[i].Euler_Angle.roll << ","
                        << acceleration_euler_list[i].Euler_Angle.pitch << ","
                        << acceleration_euler_list[i].Euler_Angle.yaw << endl;
            }

            // Acceleration Data Stream is after the Euler Angle Data Stream

            else if (AHRS_IMU::DataLabelName[0] == "roll")
            {
                fout    << acceleration_euler_list[i].Euler_Angle.roll << ","
                        << acceleration_euler_list[i].Euler_Angle.pitch << ","
                        << acceleration_euler_list[i].Euler_Angle.yaw << ","
                        << acceleration_euler_list[i].Acceleration.accel_x << "," 
                        << acceleration_euler_list[i].Acceleration.accel_y << ","
                        << acceleration_euler_list[i].Acceleration.accel_z << endl;
            }
        }

    }

    cout << "Data Stream Recording is successful! Please check csv file at " << csv_file_name << endl;

    fout.close();

    return csv_file_name;
}

// TODO: plot data stream from CSV file
string AHRS_IMU::plotDataCSV(string csv_file_name,float executation_time)
{
    rapidcsv::Document doc(csv_file_name, rapidcsv::LabelParams(0,-1));

    vector <vector <float> > Data_Columns;

    for(int i=0; i<AHRS_IMU::DataLabelName.size(); i++)
    {
        vector <float> column = doc.GetColumn<float>(AHRS_IMU::DataLabelName[i]);
        Data_Columns.push_back(column);
    }
    int frame_number = Data_Columns.at(0).size();


    // plot data with matplotplusplus libraries.
    
    return "True";

}


// Testing demo for this Class deployment

int main(int argc, char ** argv)
{

    AHRS_IMU imu;

    imu.setDataChannel_Accel_IMU(500);
    imu.setDataChannel_Euler_Angles(500);
    imu.EnableDataStream_AHRS_IMU();


    // Feature 1 : Parse one packet of data stream
    imu.accele_euler = imu.parseDataPacket_AHRS_IMU(500);
    cout <<std::left<<setw(15) << "Acceleration " <<":" <<std::right<<setw(15)<< imu.accele_euler.Acceleration.accel_x << " | " <<std::right<<setw(15)<< imu.accele_euler.Acceleration.accel_y << " | " <<std::right<<setw(15)<<  imu.accele_euler.Acceleration.accel_z << endl;
    cout <<std::left<<setw(15) << "Euler Angle " <<":" <<std::right<<setw(15)<< imu.accele_euler.Euler_Angle.roll << " | " <<std::right<<setw(15)<< imu.accele_euler.Euler_Angle.pitch << " | " <<std::right<<setw(15)<< imu.accele_euler.Euler_Angle.yaw << endl;
    
    // Start time of the executation
    auto start = chrono::high_resolution_clock::now();

    // Feature 2 : Parse PacketNumber packets of data stream, you may change the PacketNumber to meet your needs.
    int PacketNumber = 500;
    vector <AHRS_IMU::ACCELERATION_EULER_ANGLE> accel_euler_list = imu.parseDataStream_AHRS_IMU(500, PacketNumber);


    // Feature 3 : Parse PacketNumber packets and record data stream into CSV file
    string file_name = imu.recordDataToCSV(accel_euler_list);

    // Elapsed time of the executation
    auto elapsed = chrono::high_resolution_clock::now() - start;

    cout << "\r\nParse and record data Executation time is about " << chrono::duration_cast<chrono::microseconds> (elapsed).count()/1000.0 << " milliseconds." << endl;
    
    
    // Feature 4:
    // TODO: Plot the data stream recorded inside CSV file generated above
    string state = imu.plotDataCSV(file_name, 1.0);

}

// Testing demo end.
