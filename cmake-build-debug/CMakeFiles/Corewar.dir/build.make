# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rkyslyy/CLionProjects/corewar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rkyslyy/CLionProjects/corewar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Corewar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Corewar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Corewar.dir/flags.make

CMakeFiles/Corewar.dir/src/main.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Corewar.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/main.c.o   -c /Users/rkyslyy/CLionProjects/corewar/src/main.c

CMakeFiles/Corewar.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/CLionProjects/corewar/src/main.c > CMakeFiles/Corewar.dir/src/main.c.i

CMakeFiles/Corewar.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/CLionProjects/corewar/src/main.c -o CMakeFiles/Corewar.dir/src/main.c.s

CMakeFiles/Corewar.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/main.c.o.requires

CMakeFiles/Corewar.dir/src/main.c.o.provides: CMakeFiles/Corewar.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/main.c.o.provides

CMakeFiles/Corewar.dir/src/main.c.o.provides.build: CMakeFiles/Corewar.dir/src/main.c.o


CMakeFiles/Corewar.dir/src/read.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/read.c.o: ../src/read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Corewar.dir/src/read.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/read.c.o   -c /Users/rkyslyy/CLionProjects/corewar/src/read.c

CMakeFiles/Corewar.dir/src/read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/read.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/CLionProjects/corewar/src/read.c > CMakeFiles/Corewar.dir/src/read.c.i

CMakeFiles/Corewar.dir/src/read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/read.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/CLionProjects/corewar/src/read.c -o CMakeFiles/Corewar.dir/src/read.c.s

CMakeFiles/Corewar.dir/src/read.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/read.c.o.requires

CMakeFiles/Corewar.dir/src/read.c.o.provides: CMakeFiles/Corewar.dir/src/read.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/read.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/read.c.o.provides

CMakeFiles/Corewar.dir/src/read.c.o.provides.build: CMakeFiles/Corewar.dir/src/read.c.o


CMakeFiles/Corewar.dir/src/vizualize.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/vizualize.c.o: ../src/vizualize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Corewar.dir/src/vizualize.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/vizualize.c.o   -c /Users/rkyslyy/CLionProjects/corewar/src/vizualize.c

CMakeFiles/Corewar.dir/src/vizualize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/vizualize.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/CLionProjects/corewar/src/vizualize.c > CMakeFiles/Corewar.dir/src/vizualize.c.i

CMakeFiles/Corewar.dir/src/vizualize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/vizualize.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/CLionProjects/corewar/src/vizualize.c -o CMakeFiles/Corewar.dir/src/vizualize.c.s

CMakeFiles/Corewar.dir/src/vizualize.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/vizualize.c.o.requires

CMakeFiles/Corewar.dir/src/vizualize.c.o.provides: CMakeFiles/Corewar.dir/src/vizualize.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/vizualize.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/vizualize.c.o.provides

CMakeFiles/Corewar.dir/src/vizualize.c.o.provides.build: CMakeFiles/Corewar.dir/src/vizualize.c.o


# Object files for target Corewar
Corewar_OBJECTS = \
"CMakeFiles/Corewar.dir/src/main.c.o" \
"CMakeFiles/Corewar.dir/src/read.c.o" \
"CMakeFiles/Corewar.dir/src/vizualize.c.o"

# External object files for target Corewar
Corewar_EXTERNAL_OBJECTS =

Corewar: CMakeFiles/Corewar.dir/src/main.c.o
Corewar: CMakeFiles/Corewar.dir/src/read.c.o
Corewar: CMakeFiles/Corewar.dir/src/vizualize.c.o
Corewar: CMakeFiles/Corewar.dir/build.make
Corewar: CMakeFiles/Corewar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rkyslyy/CLionProjects/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Corewar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Corewar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Corewar.dir/build: Corewar

.PHONY : CMakeFiles/Corewar.dir/build

CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/main.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/read.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/vizualize.c.o.requires

.PHONY : CMakeFiles/Corewar.dir/requires

CMakeFiles/Corewar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Corewar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Corewar.dir/clean

CMakeFiles/Corewar.dir/depend:
	cd /Users/rkyslyy/CLionProjects/corewar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rkyslyy/CLionProjects/corewar /Users/rkyslyy/CLionProjects/corewar /Users/rkyslyy/CLionProjects/corewar/cmake-build-debug /Users/rkyslyy/CLionProjects/corewar/cmake-build-debug /Users/rkyslyy/CLionProjects/corewar/cmake-build-debug/CMakeFiles/Corewar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Corewar.dir/depend

