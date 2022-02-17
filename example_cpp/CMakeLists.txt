cmake_minimum_required(VERSION 3.0.0)
project(example_demo VERSION 0.1.0)


include(CTest)
include(CPack)


enable_testing()


add_executable(example_demo ${PROJECT_SOURCE_DIR}/cpp_mscl_demo_simple.cpp)
add_executable(example_class ${PROJECT_SOURCE_DIR}/cpp_mscl_class_demo.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


include_directories(/usr/share/c++-mscl/Boost/include/)
include_directories(/usr/share/c++-mscl/source/)


# https://stackoverflow.com/questions/8774593/cmake-link-to-external-library
target_link_libraries(example_demo /usr/share/c++-mscl/libmscl.so)
# https://stackoverflow.com/questions/1620918/cmake-and-libpthread
target_link_libraries(example_demo pthread)


target_link_libraries(example_class /usr/share/c++-mscl/libmscl.so)
target_link_libraries(example_class pthread)

