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
include CMakeFiles/templatematch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/templatematch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/templatematch.dir/flags.make

CMakeFiles/templatematch.dir/templatematch.cpp.obj: CMakeFiles/templatematch.dir/flags.make
CMakeFiles/templatematch.dir/templatematch.cpp.obj: CMakeFiles/templatematch.dir/includes_CXX.rsp
CMakeFiles/templatematch.dir/templatematch.cpp.obj: ../templatematch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/templatematch.dir/templatematch.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\templatematch.dir\templatematch.cpp.obj -c D:\Clion_Opencv\templatematch.cpp

CMakeFiles/templatematch.dir/templatematch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/templatematch.dir/templatematch.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Clion_Opencv\templatematch.cpp > CMakeFiles\templatematch.dir\templatematch.cpp.i

CMakeFiles/templatematch.dir/templatematch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/templatematch.dir/templatematch.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Clion_Opencv\templatematch.cpp -o CMakeFiles\templatematch.dir\templatematch.cpp.s

# Object files for target templatematch
templatematch_OBJECTS = \
"CMakeFiles/templatematch.dir/templatematch.cpp.obj"

# External object files for target templatematch
templatematch_EXTERNAL_OBJECTS =

templatematch.exe: CMakeFiles/templatematch.dir/templatematch.cpp.obj
templatematch.exe: CMakeFiles/templatematch.dir/build.make
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_dnn400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_gapi400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_ml400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_objdetect400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_photo400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_stitching400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_video400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_calib3d400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_features2d400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_flann400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_highgui400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_videoio400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_imgcodecs400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_imgproc400.dll.a
templatematch.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_core400.dll.a
templatematch.exe: CMakeFiles/templatematch.dir/linklibs.rsp
templatematch.exe: CMakeFiles/templatematch.dir/objects1.rsp
templatematch.exe: CMakeFiles/templatematch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable templatematch.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\templatematch.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/templatematch.dir/build: templatematch.exe

.PHONY : CMakeFiles/templatematch.dir/build

CMakeFiles/templatematch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\templatematch.dir\cmake_clean.cmake
.PHONY : CMakeFiles/templatematch.dir/clean

CMakeFiles/templatematch.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Clion_Opencv D:\Clion_Opencv D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug\CMakeFiles\templatematch.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/templatematch.dir/depend

