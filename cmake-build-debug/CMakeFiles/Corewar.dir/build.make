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
CMAKE_SOURCE_DIR = /Users/rkyslyy/corewar2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rkyslyy/corewar2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Corewar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Corewar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Corewar.dir/flags.make

CMakeFiles/Corewar.dir/src/main.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Corewar.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/main.c.o   -c /Users/rkyslyy/corewar2/src/main.c

CMakeFiles/Corewar.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/main.c > CMakeFiles/Corewar.dir/src/main.c.i

CMakeFiles/Corewar.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/main.c -o CMakeFiles/Corewar.dir/src/main.c.s

CMakeFiles/Corewar.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/main.c.o.requires

CMakeFiles/Corewar.dir/src/main.c.o.provides: CMakeFiles/Corewar.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/main.c.o.provides

CMakeFiles/Corewar.dir/src/main.c.o.provides.build: CMakeFiles/Corewar.dir/src/main.c.o


CMakeFiles/Corewar.dir/src/read.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/read.c.o: ../src/read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Corewar.dir/src/read.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/read.c.o   -c /Users/rkyslyy/corewar2/src/read.c

CMakeFiles/Corewar.dir/src/read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/read.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/read.c > CMakeFiles/Corewar.dir/src/read.c.i

CMakeFiles/Corewar.dir/src/read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/read.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/read.c -o CMakeFiles/Corewar.dir/src/read.c.s

CMakeFiles/Corewar.dir/src/read.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/read.c.o.requires

CMakeFiles/Corewar.dir/src/read.c.o.provides: CMakeFiles/Corewar.dir/src/read.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/read.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/read.c.o.provides

CMakeFiles/Corewar.dir/src/read.c.o.provides.build: CMakeFiles/Corewar.dir/src/read.c.o


CMakeFiles/Corewar.dir/src/vizualize.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/vizualize.c.o: ../src/vizualize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Corewar.dir/src/vizualize.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/vizualize.c.o   -c /Users/rkyslyy/corewar2/src/vizualize.c

CMakeFiles/Corewar.dir/src/vizualize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/vizualize.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/vizualize.c > CMakeFiles/Corewar.dir/src/vizualize.c.i

CMakeFiles/Corewar.dir/src/vizualize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/vizualize.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/vizualize.c -o CMakeFiles/Corewar.dir/src/vizualize.c.s

CMakeFiles/Corewar.dir/src/vizualize.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/vizualize.c.o.requires

CMakeFiles/Corewar.dir/src/vizualize.c.o.provides: CMakeFiles/Corewar.dir/src/vizualize.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/vizualize.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/vizualize.c.o.provides

CMakeFiles/Corewar.dir/src/vizualize.c.o.provides.build: CMakeFiles/Corewar.dir/src/vizualize.c.o


CMakeFiles/Corewar.dir/src/inits.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/inits.c.o: ../src/inits.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Corewar.dir/src/inits.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/inits.c.o   -c /Users/rkyslyy/corewar2/src/inits.c

CMakeFiles/Corewar.dir/src/inits.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/inits.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/inits.c > CMakeFiles/Corewar.dir/src/inits.c.i

CMakeFiles/Corewar.dir/src/inits.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/inits.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/inits.c -o CMakeFiles/Corewar.dir/src/inits.c.s

CMakeFiles/Corewar.dir/src/inits.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/inits.c.o.requires

CMakeFiles/Corewar.dir/src/inits.c.o.provides: CMakeFiles/Corewar.dir/src/inits.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/inits.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/inits.c.o.provides

CMakeFiles/Corewar.dir/src/inits.c.o.provides.build: CMakeFiles/Corewar.dir/src/inits.c.o


CMakeFiles/Corewar.dir/src/converts.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/converts.c.o: ../src/converts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Corewar.dir/src/converts.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/converts.c.o   -c /Users/rkyslyy/corewar2/src/converts.c

CMakeFiles/Corewar.dir/src/converts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/converts.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/converts.c > CMakeFiles/Corewar.dir/src/converts.c.i

CMakeFiles/Corewar.dir/src/converts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/converts.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/converts.c -o CMakeFiles/Corewar.dir/src/converts.c.s

CMakeFiles/Corewar.dir/src/converts.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/converts.c.o.requires

CMakeFiles/Corewar.dir/src/converts.c.o.provides: CMakeFiles/Corewar.dir/src/converts.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/converts.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/converts.c.o.provides

CMakeFiles/Corewar.dir/src/converts.c.o.provides.build: CMakeFiles/Corewar.dir/src/converts.c.o


CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o: ../src/live_ld_st_add_sub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o   -c /Users/rkyslyy/corewar2/src/live_ld_st_add_sub.c

CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/live_ld_st_add_sub.c > CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.i

CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/live_ld_st_add_sub.c -o CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.s

CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.requires

CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.provides: CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.provides

CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.provides.build: CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o


CMakeFiles/Corewar.dir/src/read2.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/read2.c.o: ../src/read2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Corewar.dir/src/read2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/read2.c.o   -c /Users/rkyslyy/corewar2/src/read2.c

CMakeFiles/Corewar.dir/src/read2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/read2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/read2.c > CMakeFiles/Corewar.dir/src/read2.c.i

CMakeFiles/Corewar.dir/src/read2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/read2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/read2.c -o CMakeFiles/Corewar.dir/src/read2.c.s

CMakeFiles/Corewar.dir/src/read2.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/read2.c.o.requires

CMakeFiles/Corewar.dir/src/read2.c.o.provides: CMakeFiles/Corewar.dir/src/read2.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/read2.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/read2.c.o.provides

CMakeFiles/Corewar.dir/src/read2.c.o.provides.build: CMakeFiles/Corewar.dir/src/read2.c.o


CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o: ../src/and_or_xor_zjmp_ldi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o   -c /Users/rkyslyy/corewar2/src/and_or_xor_zjmp_ldi.c

CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/and_or_xor_zjmp_ldi.c > CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.i

CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/and_or_xor_zjmp_ldi.c -o CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.s

CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.requires

CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.provides: CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.provides

CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.provides.build: CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o


CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o: ../src/sti_fork_lld_lldi_lfork.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o   -c /Users/rkyslyy/corewar2/src/sti_fork_lld_lldi_lfork.c

CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/sti_fork_lld_lldi_lfork.c > CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.i

CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/sti_fork_lld_lldi_lfork.c -o CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.s

CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.requires

CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.provides: CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.provides

CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.provides.build: CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o


CMakeFiles/Corewar.dir/src/vis_methods.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/vis_methods.c.o: ../src/vis_methods.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Corewar.dir/src/vis_methods.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/vis_methods.c.o   -c /Users/rkyslyy/corewar2/src/vis_methods.c

CMakeFiles/Corewar.dir/src/vis_methods.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/vis_methods.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/vis_methods.c > CMakeFiles/Corewar.dir/src/vis_methods.c.i

CMakeFiles/Corewar.dir/src/vis_methods.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/vis_methods.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/vis_methods.c -o CMakeFiles/Corewar.dir/src/vis_methods.c.s

CMakeFiles/Corewar.dir/src/vis_methods.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/vis_methods.c.o.requires

CMakeFiles/Corewar.dir/src/vis_methods.c.o.provides: CMakeFiles/Corewar.dir/src/vis_methods.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/vis_methods.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/vis_methods.c.o.provides

CMakeFiles/Corewar.dir/src/vis_methods.c.o.provides.build: CMakeFiles/Corewar.dir/src/vis_methods.c.o


CMakeFiles/Corewar.dir/src/vis_methods2.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/vis_methods2.c.o: ../src/vis_methods2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Corewar.dir/src/vis_methods2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/vis_methods2.c.o   -c /Users/rkyslyy/corewar2/src/vis_methods2.c

CMakeFiles/Corewar.dir/src/vis_methods2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/vis_methods2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/vis_methods2.c > CMakeFiles/Corewar.dir/src/vis_methods2.c.i

CMakeFiles/Corewar.dir/src/vis_methods2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/vis_methods2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/vis_methods2.c -o CMakeFiles/Corewar.dir/src/vis_methods2.c.s

CMakeFiles/Corewar.dir/src/vis_methods2.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/vis_methods2.c.o.requires

CMakeFiles/Corewar.dir/src/vis_methods2.c.o.provides: CMakeFiles/Corewar.dir/src/vis_methods2.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/vis_methods2.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/vis_methods2.c.o.provides

CMakeFiles/Corewar.dir/src/vis_methods2.c.o.provides.build: CMakeFiles/Corewar.dir/src/vis_methods2.c.o


CMakeFiles/Corewar.dir/src/sub_main.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/sub_main.c.o: ../src/sub_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Corewar.dir/src/sub_main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/sub_main.c.o   -c /Users/rkyslyy/corewar2/src/sub_main.c

CMakeFiles/Corewar.dir/src/sub_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/sub_main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/sub_main.c > CMakeFiles/Corewar.dir/src/sub_main.c.i

CMakeFiles/Corewar.dir/src/sub_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/sub_main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/sub_main.c -o CMakeFiles/Corewar.dir/src/sub_main.c.s

CMakeFiles/Corewar.dir/src/sub_main.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/sub_main.c.o.requires

CMakeFiles/Corewar.dir/src/sub_main.c.o.provides: CMakeFiles/Corewar.dir/src/sub_main.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/sub_main.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/sub_main.c.o.provides

CMakeFiles/Corewar.dir/src/sub_main.c.o.provides.build: CMakeFiles/Corewar.dir/src/sub_main.c.o


CMakeFiles/Corewar.dir/src/sub_main2.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/sub_main2.c.o: ../src/sub_main2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Corewar.dir/src/sub_main2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/sub_main2.c.o   -c /Users/rkyslyy/corewar2/src/sub_main2.c

CMakeFiles/Corewar.dir/src/sub_main2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/sub_main2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/sub_main2.c > CMakeFiles/Corewar.dir/src/sub_main2.c.i

CMakeFiles/Corewar.dir/src/sub_main2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/sub_main2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/sub_main2.c -o CMakeFiles/Corewar.dir/src/sub_main2.c.s

CMakeFiles/Corewar.dir/src/sub_main2.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/sub_main2.c.o.requires

CMakeFiles/Corewar.dir/src/sub_main2.c.o.provides: CMakeFiles/Corewar.dir/src/sub_main2.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/sub_main2.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/sub_main2.c.o.provides

CMakeFiles/Corewar.dir/src/sub_main2.c.o.provides.build: CMakeFiles/Corewar.dir/src/sub_main2.c.o


CMakeFiles/Corewar.dir/src/run_processes.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/run_processes.c.o: ../src/run_processes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/Corewar.dir/src/run_processes.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/run_processes.c.o   -c /Users/rkyslyy/corewar2/src/run_processes.c

CMakeFiles/Corewar.dir/src/run_processes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/run_processes.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/run_processes.c > CMakeFiles/Corewar.dir/src/run_processes.c.i

CMakeFiles/Corewar.dir/src/run_processes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/run_processes.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/run_processes.c -o CMakeFiles/Corewar.dir/src/run_processes.c.s

CMakeFiles/Corewar.dir/src/run_processes.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/run_processes.c.o.requires

CMakeFiles/Corewar.dir/src/run_processes.c.o.provides: CMakeFiles/Corewar.dir/src/run_processes.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/run_processes.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/run_processes.c.o.provides

CMakeFiles/Corewar.dir/src/run_processes.c.o.provides.build: CMakeFiles/Corewar.dir/src/run_processes.c.o


CMakeFiles/Corewar.dir/src/sub_main3.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/sub_main3.c.o: ../src/sub_main3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/Corewar.dir/src/sub_main3.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/sub_main3.c.o   -c /Users/rkyslyy/corewar2/src/sub_main3.c

CMakeFiles/Corewar.dir/src/sub_main3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/sub_main3.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/sub_main3.c > CMakeFiles/Corewar.dir/src/sub_main3.c.i

CMakeFiles/Corewar.dir/src/sub_main3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/sub_main3.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/sub_main3.c -o CMakeFiles/Corewar.dir/src/sub_main3.c.s

CMakeFiles/Corewar.dir/src/sub_main3.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/sub_main3.c.o.requires

CMakeFiles/Corewar.dir/src/sub_main3.c.o.provides: CMakeFiles/Corewar.dir/src/sub_main3.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/sub_main3.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/sub_main3.c.o.provides

CMakeFiles/Corewar.dir/src/sub_main3.c.o.provides.build: CMakeFiles/Corewar.dir/src/sub_main3.c.o


CMakeFiles/Corewar.dir/src/sub_main4.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/sub_main4.c.o: ../src/sub_main4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/Corewar.dir/src/sub_main4.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/sub_main4.c.o   -c /Users/rkyslyy/corewar2/src/sub_main4.c

CMakeFiles/Corewar.dir/src/sub_main4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/sub_main4.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/sub_main4.c > CMakeFiles/Corewar.dir/src/sub_main4.c.i

CMakeFiles/Corewar.dir/src/sub_main4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/sub_main4.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/sub_main4.c -o CMakeFiles/Corewar.dir/src/sub_main4.c.s

CMakeFiles/Corewar.dir/src/sub_main4.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/sub_main4.c.o.requires

CMakeFiles/Corewar.dir/src/sub_main4.c.o.provides: CMakeFiles/Corewar.dir/src/sub_main4.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/sub_main4.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/sub_main4.c.o.provides

CMakeFiles/Corewar.dir/src/sub_main4.c.o.provides.build: CMakeFiles/Corewar.dir/src/sub_main4.c.o


CMakeFiles/Corewar.dir/src/lil_func.c.o: CMakeFiles/Corewar.dir/flags.make
CMakeFiles/Corewar.dir/src/lil_func.c.o: ../src/lil_func.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/Corewar.dir/src/lil_func.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Corewar.dir/src/lil_func.c.o   -c /Users/rkyslyy/corewar2/src/lil_func.c

CMakeFiles/Corewar.dir/src/lil_func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corewar.dir/src/lil_func.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rkyslyy/corewar2/src/lil_func.c > CMakeFiles/Corewar.dir/src/lil_func.c.i

CMakeFiles/Corewar.dir/src/lil_func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corewar.dir/src/lil_func.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rkyslyy/corewar2/src/lil_func.c -o CMakeFiles/Corewar.dir/src/lil_func.c.s

CMakeFiles/Corewar.dir/src/lil_func.c.o.requires:

.PHONY : CMakeFiles/Corewar.dir/src/lil_func.c.o.requires

CMakeFiles/Corewar.dir/src/lil_func.c.o.provides: CMakeFiles/Corewar.dir/src/lil_func.c.o.requires
	$(MAKE) -f CMakeFiles/Corewar.dir/build.make CMakeFiles/Corewar.dir/src/lil_func.c.o.provides.build
.PHONY : CMakeFiles/Corewar.dir/src/lil_func.c.o.provides

CMakeFiles/Corewar.dir/src/lil_func.c.o.provides.build: CMakeFiles/Corewar.dir/src/lil_func.c.o


# Object files for target Corewar
Corewar_OBJECTS = \
"CMakeFiles/Corewar.dir/src/main.c.o" \
"CMakeFiles/Corewar.dir/src/read.c.o" \
"CMakeFiles/Corewar.dir/src/vizualize.c.o" \
"CMakeFiles/Corewar.dir/src/inits.c.o" \
"CMakeFiles/Corewar.dir/src/converts.c.o" \
"CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o" \
"CMakeFiles/Corewar.dir/src/read2.c.o" \
"CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o" \
"CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o" \
"CMakeFiles/Corewar.dir/src/vis_methods.c.o" \
"CMakeFiles/Corewar.dir/src/vis_methods2.c.o" \
"CMakeFiles/Corewar.dir/src/sub_main.c.o" \
"CMakeFiles/Corewar.dir/src/sub_main2.c.o" \
"CMakeFiles/Corewar.dir/src/run_processes.c.o" \
"CMakeFiles/Corewar.dir/src/sub_main3.c.o" \
"CMakeFiles/Corewar.dir/src/sub_main4.c.o" \
"CMakeFiles/Corewar.dir/src/lil_func.c.o"

# External object files for target Corewar
Corewar_EXTERNAL_OBJECTS =

Corewar: CMakeFiles/Corewar.dir/src/main.c.o
Corewar: CMakeFiles/Corewar.dir/src/read.c.o
Corewar: CMakeFiles/Corewar.dir/src/vizualize.c.o
Corewar: CMakeFiles/Corewar.dir/src/inits.c.o
Corewar: CMakeFiles/Corewar.dir/src/converts.c.o
Corewar: CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o
Corewar: CMakeFiles/Corewar.dir/src/read2.c.o
Corewar: CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o
Corewar: CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o
Corewar: CMakeFiles/Corewar.dir/src/vis_methods.c.o
Corewar: CMakeFiles/Corewar.dir/src/vis_methods2.c.o
Corewar: CMakeFiles/Corewar.dir/src/sub_main.c.o
Corewar: CMakeFiles/Corewar.dir/src/sub_main2.c.o
Corewar: CMakeFiles/Corewar.dir/src/run_processes.c.o
Corewar: CMakeFiles/Corewar.dir/src/sub_main3.c.o
Corewar: CMakeFiles/Corewar.dir/src/sub_main4.c.o
Corewar: CMakeFiles/Corewar.dir/src/lil_func.c.o
Corewar: CMakeFiles/Corewar.dir/build.make
Corewar: ../libft/libft.a
Corewar: ../libft/ft_printf/libftprintf.a
Corewar: CMakeFiles/Corewar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking C executable Corewar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Corewar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Corewar.dir/build: Corewar

.PHONY : CMakeFiles/Corewar.dir/build

CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/main.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/read.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/vizualize.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/inits.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/converts.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/live_ld_st_add_sub.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/read2.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/and_or_xor_zjmp_ldi.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/sti_fork_lld_lldi_lfork.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/vis_methods.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/vis_methods2.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/sub_main.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/sub_main2.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/run_processes.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/sub_main3.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/sub_main4.c.o.requires
CMakeFiles/Corewar.dir/requires: CMakeFiles/Corewar.dir/src/lil_func.c.o.requires

.PHONY : CMakeFiles/Corewar.dir/requires

CMakeFiles/Corewar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Corewar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Corewar.dir/clean

CMakeFiles/Corewar.dir/depend:
	cd /Users/rkyslyy/corewar2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rkyslyy/corewar2 /Users/rkyslyy/corewar2 /Users/rkyslyy/corewar2/cmake-build-debug /Users/rkyslyy/corewar2/cmake-build-debug /Users/rkyslyy/corewar2/cmake-build-debug/CMakeFiles/Corewar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Corewar.dir/depend

