# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/guoyucan/Downloads/cmake-3.17.5/bin/cmake

# The command to remove a file.
RM = /home/guoyucan/Downloads/cmake-3.17.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guoyucan/Downloads/mscl_demo/example_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guoyucan/Downloads/mscl_demo/example_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/simple_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_demo.dir/flags.make

CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.o: CMakeFiles/simple_demo.dir/flags.make
CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.o: ../cpp_mscl_demo_simple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guoyucan/Downloads/mscl_demo/example_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.o -c /home/guoyucan/Downloads/mscl_demo/example_cpp/cpp_mscl_demo_simple.cpp

CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guoyucan/Downloads/mscl_demo/example_cpp/cpp_mscl_demo_simple.cpp > CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.i

CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guoyucan/Downloads/mscl_demo/example_cpp/cpp_mscl_demo_simple.cpp -o CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.s

# Object files for target simple_demo
simple_demo_OBJECTS = \
"CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.o"

# External object files for target simple_demo
simple_demo_EXTERNAL_OBJECTS =

../bin/simple_demo: CMakeFiles/simple_demo.dir/cpp_mscl_demo_simple.cpp.o
../bin/simple_demo: CMakeFiles/simple_demo.dir/build.make
../bin/simple_demo: /usr/share/c++-mscl/libmscl.so
../bin/simple_demo: CMakeFiles/simple_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guoyucan/Downloads/mscl_demo/example_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/simple_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_demo.dir/build: ../bin/simple_demo

.PHONY : CMakeFiles/simple_demo.dir/build

CMakeFiles/simple_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_demo.dir/clean

CMakeFiles/simple_demo.dir/depend:
	cd /home/guoyucan/Downloads/mscl_demo/example_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guoyucan/Downloads/mscl_demo/example_cpp /home/guoyucan/Downloads/mscl_demo/example_cpp /home/guoyucan/Downloads/mscl_demo/example_cpp/build /home/guoyucan/Downloads/mscl_demo/example_cpp/build /home/guoyucan/Downloads/mscl_demo/example_cpp/build/CMakeFiles/simple_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_demo.dir/depend
