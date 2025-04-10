# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build

# Include any dependencies generated for this target.
include src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/compiler_depend.make

# Include the progress variables for this target.
include src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/progress.make

# Include the compile flags for this target's objects.
include src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/flags.make

src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o: src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/flags.make
src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o: /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/src/EtherCAT_slave_base/EtherCAT_slave_base.cpp
src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o: src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o"
	cd /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o -MF CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o.d -o CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o -c /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/src/EtherCAT_slave_base/EtherCAT_slave_base.cpp

src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.i"
	cd /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/src/EtherCAT_slave_base/EtherCAT_slave_base.cpp > CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.i

src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.s"
	cd /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/src/EtherCAT_slave_base/EtherCAT_slave_base.cpp -o CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.s

# Object files for target ethercat_slave_base
ethercat_slave_base_OBJECTS = \
"CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o"

# External object files for target ethercat_slave_base
ethercat_slave_base_EXTERNAL_OBJECTS =

src/EtherCAT_slave_base/libethercat_slave_base.a: src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/EtherCAT_slave_base.cpp.o
src/EtherCAT_slave_base/libethercat_slave_base.a: src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/build.make
src/EtherCAT_slave_base/libethercat_slave_base.a: src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libethercat_slave_base.a"
	cd /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base && $(CMAKE_COMMAND) -P CMakeFiles/ethercat_slave_base.dir/cmake_clean_target.cmake
	cd /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ethercat_slave_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/build: src/EtherCAT_slave_base/libethercat_slave_base.a
.PHONY : src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/build

src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/clean:
	cd /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base && $(CMAKE_COMMAND) -P CMakeFiles/ethercat_slave_base.dir/cmake_clean.cmake
.PHONY : src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/clean

src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/depend:
	cd /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/src/EtherCAT_slave_base /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base /home/abhinayh56/Abhinay/Ethercat_IGH/EtherCAT_main/EtherCAT_layer/build/src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/EtherCAT_slave_base/CMakeFiles/ethercat_slave_base.dir/depend

