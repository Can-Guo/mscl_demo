
# mscl_demo

This is an example demo based on [mscl](https://github.com/LORD-MicroStrain/MSCL "mscl home") for AHRS/IMU 3DX-GX3-25 and 3DX-CV5-AHRS sensor developed by [Microstrain](https://www.microstrain.com/), which example codes we modified for easy integration or deployment. More examples for this kind of sensor could be found in [LORD-Microstrain/MSCL/MSCL_Examples/Inertial](https://github.com/LORD-MicroStrain/MSCL/tree/master/MSCL_Examples/Inertial). For more information on how to master the MSCL libraries, please refer to [mscl documentation](http://lord-microstrain.github.io/MSCL/Documentation/MSCL%20Documentation/index.html#).


## Project Overview
```bash
mscl_demo
├── example_cpp
│   ├── bin
│   │   ├── example_class
│   │   └── example_demo
│   ├── build     
│   ├── CMakeLists.txt
│   ├── cpp_mscl_class_demo.cpp
│   ├── cpp_mscl_demo.cpp
│   └── cpp_mscl_demo_simple.cpp
├── example_python
│   ├── csv
│   │   ├── data_2022-02-13 12:58:57.227380.csv
│   │   ├── data_2022-02-13 13:44:25.828601.csv
│   │   └── data_2022-02-13 13:47:43.859994.csv
│   ├── fig
│   │   ├── 2022-02-13 13:42:35.099423.png
│   │   ├── 2022-02-13 13:43:56.991011.png
│   │   └── 2022-02-13 13:48:51.539636.png
│   └── python_mscl_demo
│       ├── python3_mscl_demo.py
│       ├── python_mscl_class_demo.py
│       └── python_mscl_demo_simple.py
├── install_package
│   ├── c++-mscl_63.1.0_amd64.deb
│   └── python3-mscl_63.1.0_amd64.deb
└── README.md
```

## Installation
Follow steps to install MSCL libraries for python3 or cpp on [HowToUseMSCL](https://github.com/LORD-MicroStrain/MSCL/blob/master/HowToUseMSCL.md?).


## User demo
### python


#### demo 1 : python_mscl_demo_simple.py
Just run the source file with python3 in the terminal on top of the folder ./example_python/python_mscl_demo/
```bash
python3 python_mscl_demo_simple.py
```


#### demo 2: python_mscl_class_demo.py
Change the name of the source file in the command above.
```bash
python3 python_mscl_class_demo.py
```


### c++
#### Build using g++ in the terminal
##### demo 1 : cpp_mscl_demo_simple.cpp
###### Step 1. Complie the source file with g++ in the folder ./example_cpp/
```bash
g++ -I/usr/share/c++-mscl/source -I/usr/share/c++-mscl/Boost/include cpp_mscl_demo_simple.cpp -o cpp_demo_1 -L/usr/share/c++-mscl -lmscl -lstdc++ -std=c++11 -lpthread -pthread
```
###### Step 2. Run the executable file generated.
```bash
LD_PRELOAD=/usr/share/c++-mscl/libmscl.so ./cpp_demo_1
```


##### demo 2 : cpp_mscl_class_demo.cpp
Change the name of the source file in the command, from <cpp_mscl_demo_simple.cpp> to <cpp_mscl_class_demo.cpp>, target name from <cpp_demo_1> to <cpp_demo_2>.


#### Build using CMake in the terminal

```bash
cd ./example_cpp/build
cmake ..
make
```
If there are not any bug, you could run the executable file generated by:
```bash
cd ..
cd bin/
./example_demo 
./example_class
```
