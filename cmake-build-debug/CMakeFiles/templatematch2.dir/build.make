# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Clion_Opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Clion_Opencv\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/templatematch2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/templatematch2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/templatematch2.dir/flags.make

CMakeFiles/templatematch2.dir/templatematch2.cpp.obj: CMakeFiles/templatematch2.dir/flags.make
CMakeFiles/templatematch2.dir/templatematch2.cpp.obj: CMakeFiles/templatematch2.dir/includes_CXX.rsp
CMakeFiles/templatematch2.dir/templatematch2.cpp.obj: ../templatematch2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/templatematch2.dir/templatematch2.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\templatematch2.dir\templatematch2.cpp.obj -c D:\Clion_Opencv\templatematch2.cpp

CMakeFiles/templatematch2.dir/templatematch2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/templatematch2.dir/templatematch2.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Clion_Opencv\templatematch2.cpp > CMakeFiles\templatematch2.dir\templatematch2.cpp.i

CMakeFiles/templatematch2.dir/templatematch2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/templatematch2.dir/templatematch2.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Clion_Opencv\templatematch2.cpp -o CMakeFiles\templatematch2.dir\templatematch2.cpp.s

# Object files for target templatematch2
templatematch2_OBJECTS = \
"CMakeFiles/templatematch2.dir/templatematch2.cpp.obj"

# External object files for target templatematch2
templatematch2_EXTERNAL_OBJECTS =

templatematch2.exe: CMakeFiles/templatematch2.dir/templatematch2.cpp.obj
templatematch2.exe: CMakeFiles/templatematch2.dir/build.make
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_dnn400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_gapi400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_ml400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_objdetect400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_photo400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_stitching400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_video400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_calib3d400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_features2d400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_flann400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_highgui400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_videoio400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_imgcodecs400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_imgproc400.dll.a
templatematch2.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_core400.dll.a
templatematch2.exe: CMakeFiles/templatematch2.dir/linklibs.rsp
templatematch2.exe: CMakeFiles/templatematch2.dir/objects1.rsp
templatematch2.exe: CMakeFiles/templatematch2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable templatematch2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\templatematch2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/templatematch2.dir/build: templatematch2.exe

.PHONY : CMakeFiles/templatematch2.dir/build

CMakeFiles/templatematch2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\templatematch2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/templatematch2.dir/clean

CMakeFiles/templatematch2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Clion_Opencv D:\Clion_Opencv D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug\CMakeFiles\templatematch2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/templatematch2.dir/depend

