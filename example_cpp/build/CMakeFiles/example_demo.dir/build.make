# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guoyucan/Downloads/Microstrain/example_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guoyucan/Downloads/Microstrain/example_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/example_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_demo.dir/flags.make

CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o: CMakeFiles/example_demo.dir/flags.make
CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o: ../cpp_mscl_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guoyucan/Downloads/Microstrain/example_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o -c /home/guoyucan/Downloads/Microstrain/example_cpp/cpp_mscl_demo.cpp

CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guoyucan/Downloads/Microstrain/example_cpp/cpp_mscl_demo.cpp > CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.i

CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guoyucan/Downloads/Microstrain/example_cpp/cpp_mscl_demo.cpp -o CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.s

CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.requires:

.PHONY : CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.requires

CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.provides: CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.requires
	$(MAKE) -f CMakeFiles/example_demo.dir/build.make CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.provides.build
.PHONY : CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.provides

CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.provides.build: CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o


# Object files for target example_demo
example_demo_OBJECTS = \
"CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o"

# External object files for target example_demo
example_demo_EXTERNAL_OBJECTS =

../bin/example_demo: CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o
../bin/example_demo: CMakeFiles/example_demo.dir/build.make
../bin/example_demo: /usr/share/c++-mscl/libmscl.so
../bin/example_demo: CMakeFiles/example_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guoyucan/Downloads/Microstrain/example_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/example_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_demo.dir/build: ../bin/example_demo

.PHONY : CMakeFiles/example_demo.dir/build

CMakeFiles/example_demo.dir/requires: CMakeFiles/example_demo.dir/cpp_mscl_demo.cpp.o.requires

.PHONY : CMakeFiles/example_demo.dir/requires

CMakeFiles/example_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_demo.dir/clean

CMakeFiles/example_demo.dir/depend:
	cd /home/guoyucan/Downloads/Microstrain/example_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guoyucan/Downloads/Microstrain/example_cpp /home/guoyucan/Downloads/Microstrain/example_cpp /home/guoyucan/Downloads/Microstrain/example_cpp/build /home/guoyucan/Downloads/Microstrain/example_cpp/build /home/guoyucan/Downloads/Microstrain/example_cpp/build/CMakeFiles/example_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_demo.dir/depend

