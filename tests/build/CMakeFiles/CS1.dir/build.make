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
CMAKE_SOURCE_DIR = /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build

# Include any dependencies generated for this target.
include CMakeFiles/CS1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CS1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CS1.dir/flags.make

CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o: CMakeFiles/CS1.dir/flags.make
CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o: ../C-S_test_01/src/ClientTaskImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o -c /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/ClientTaskImpl.cpp

CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/ClientTaskImpl.cpp > CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.i

CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/ClientTaskImpl.cpp -o CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.s

CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.requires:

.PHONY : CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.requires

CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.provides: CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.requires
	$(MAKE) -f CMakeFiles/CS1.dir/build.make CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.provides.build
.PHONY : CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.provides

CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.provides.build: CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o


CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o: CMakeFiles/CS1.dir/flags.make
CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o: ../C-S_test_01/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o -c /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/main.cpp

CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/main.cpp > CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.i

CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/main.cpp -o CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.s

CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.requires:

.PHONY : CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.requires

CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.provides: CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CS1.dir/build.make CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.provides

CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.provides.build: CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o


CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o: CMakeFiles/CS1.dir/flags.make
CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o: ../C-S_test_01/src/ServerTaskImlp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o -c /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/ServerTaskImlp.cpp

CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/ServerTaskImlp.cpp > CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.i

CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/C-S_test_01/src/ServerTaskImlp.cpp -o CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.s

CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.requires:

.PHONY : CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.requires

CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.provides: CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.requires
	$(MAKE) -f CMakeFiles/CS1.dir/build.make CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.provides.build
.PHONY : CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.provides

CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.provides.build: CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o


# Object files for target CS1
CS1_OBJECTS = \
"CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o" \
"CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o" \
"CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o"

# External object files for target CS1
CS1_EXTERNAL_OBJECTS =

CS1: CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o
CS1: CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o
CS1: CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o
CS1: CMakeFiles/CS1.dir/build.make
CS1: /usr/local/systemC/scnsl/lib/libscnsl.so
CS1: /usr/local/systemC/lib-linux64/libsystemc.so
CS1: /usr/lib/x86_64-linux-gnu/libdl.so
CS1: CMakeFiles/CS1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CS1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CS1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CS1.dir/build: CS1

.PHONY : CMakeFiles/CS1.dir/build

CMakeFiles/CS1.dir/requires: CMakeFiles/CS1.dir/C-S_test_01/src/ClientTaskImpl.cpp.o.requires
CMakeFiles/CS1.dir/requires: CMakeFiles/CS1.dir/C-S_test_01/src/main.cpp.o.requires
CMakeFiles/CS1.dir/requires: CMakeFiles/CS1.dir/C-S_test_01/src/ServerTaskImlp.cpp.o.requires

.PHONY : CMakeFiles/CS1.dir/requires

CMakeFiles/CS1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CS1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CS1.dir/clean

CMakeFiles/CS1.dir/depend:
	cd /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build /home/elia/Scrivania/scnsl_opc_ua/scnsl_op_ua_sim/tests/build/CMakeFiles/CS1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CS1.dir/depend
