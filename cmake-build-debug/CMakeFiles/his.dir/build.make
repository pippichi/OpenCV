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
include CMakeFiles/his.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/his.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/his.dir/flags.make

CMakeFiles/his.dir/xiangsuchongyingshe.cpp.obj: CMakeFiles/his.dir/flags.make
CMakeFiles/his.dir/xiangsuchongyingshe.cpp.obj: CMakeFiles/his.dir/includes_CXX.rsp
CMakeFiles/his.dir/xiangsuchongyingshe.cpp.obj: ../xiangsuchongyingshe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/his.dir/xiangsuchongyingshe.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\his.dir\xiangsuchongyingshe.cpp.obj -c D:\Clion_Opencv\xiangsuchongyingshe.cpp

CMakeFiles/his.dir/xiangsuchongyingshe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/his.dir/xiangsuchongyingshe.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Clion_Opencv\xiangsuchongyingshe.cpp > CMakeFiles\his.dir\xiangsuchongyingshe.cpp.i

CMakeFiles/his.dir/xiangsuchongyingshe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/his.dir/xiangsuchongyingshe.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Clion_Opencv\xiangsuchongyingshe.cpp -o CMakeFiles\his.dir\xiangsuchongyingshe.cpp.s

# Object files for target his
his_OBJECTS = \
"CMakeFiles/his.dir/xiangsuchongyingshe.cpp.obj"

# External object files for target his
his_EXTERNAL_OBJECTS =

his.exe: CMakeFiles/his.dir/xiangsuchongyingshe.cpp.obj
his.exe: CMakeFiles/his.dir/build.make
his.exe: CMakeFiles/his.dir/linklibs.rsp
his.exe: CMakeFiles/his.dir/objects1.rsp
his.exe: CMakeFiles/his.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Clion_Opencv\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable his.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\his.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/his.dir/build: his.exe

.PHONY : CMakeFiles/his.dir/build

CMakeFiles/his.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\his.dir\cmake_clean.cmake
.PHONY : CMakeFiles/his.dir/clean

CMakeFiles/his.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Clion_Opencv D:\Clion_Opencv D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug D:\Clion_Opencv\cmake-build-debug\CMakeFiles\his.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/his.dir/depend
