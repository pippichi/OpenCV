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
include CMakeFiles/imageMoments.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imageMoments.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imageMoments.dir/flags.make

CMakeFiles/imageMoments.dir/imageMoments.cpp.obj: CMakeFiles/imageMoments.dir/flags.make
CMakeFiles/imageMoments.dir/imageMoments.cpp.obj: CMakeFiles/imageMoments.dir/includes_CXX.rsp
CMakeFiles/imageMoments.dir/imageMoments.cpp.obj: ../imageMoments.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/imageMoments.dir/imageMoments.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\imageMoments.dir\imageMoments.cpp.obj -c D:\Clion_Opencv\imageMoments.cpp

CMakeFiles/imageMoments.dir/imageMoments.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imageMoments.dir/imageMoments.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Clion_Opencv\imageMoments.cpp > CMakeFiles\imageMoments.dir\imageMoments.cpp.i

CMakeFiles/imageMoments.dir/imageMoments.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imageMoments.dir/imageMoments.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Clion_Opencv\imageMoments.cpp -o CMakeFiles\imageMoments.dir\imageMoments.cpp.s

# Object files for target imageMoments
imageMoments_OBJECTS = \
"CMakeFiles/imageMoments.dir/imageMoments.cpp.obj"

# External object files for target imageMoments
imageMoments_EXTERNAL_OBJECTS =

imageMoments.exe: CMakeFiles/imageMoments.dir/imageMoments.cpp.obj
imageMoments.exe: CMakeFiles/imageMoments.dir/build.make
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_dnn400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_gapi400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_ml400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_objdetect400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_photo400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_stitching400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_video400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_calib3d400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_features2d400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_flann400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_highgui400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_videoio400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_imgcodecs400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_imgproc400.dll.a
imageMoments.exe: D:/opencv4.0/opencv/mingw64_build/install/x64/mingw/lib/libopencv_core400.dll.a
imageMoments.exe: CMakeFiles/imageMoments.dir/linklibs.rsp
imageMoments.exe: CMakeFiles/imageMoments.dir/objects1.rsp
imageMoments.exe: CMakeFiles/imageMoments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable imageMoments.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\imageMoments.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imageMoments.dir/build: imageMoments.exe

.PHONY : CMakeFiles/imageMoments.dir/build

CMakeFiles/imageMoments.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\imageMoments.dir\cmake_clean.cmake
.PHONY : CMakeFiles/imageMoments.dir/clean

CMakeFiles/imageMoments.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Clion_Opencv D:\Clion_Opencv D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug\CMakeFiles\imageMoments.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imageMoments.dir/depend

