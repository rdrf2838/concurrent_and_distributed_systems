# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/ivin/CLionProjects/concurrent_and_distributed_systems

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivin/CLionProjects/concurrent_and_distributed_systems/build

# Include any dependencies generated for this target.
include folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/depend.make

# Include the progress variables for this target.
include folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/progress.make

# Include the compile flags for this target's objects.
include folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/flags.make

folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/sleepmutex.cpp.o: folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/flags.make
folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/sleepmutex.cpp.o: ../folder_concurrency_patterns/app_sleepmutex/sleepmutex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivin/CLionProjects/concurrent_and_distributed_systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/sleepmutex.cpp.o"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_sleepmutex && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sleepmutex.dir/sleepmutex.cpp.o -c /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_sleepmutex/sleepmutex.cpp

folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/sleepmutex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sleepmutex.dir/sleepmutex.cpp.i"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_sleepmutex && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_sleepmutex/sleepmutex.cpp > CMakeFiles/sleepmutex.dir/sleepmutex.cpp.i

folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/sleepmutex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sleepmutex.dir/sleepmutex.cpp.s"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_sleepmutex && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_sleepmutex/sleepmutex.cpp -o CMakeFiles/sleepmutex.dir/sleepmutex.cpp.s

# Object files for target sleepmutex
sleepmutex_OBJECTS = \
"CMakeFiles/sleepmutex.dir/sleepmutex.cpp.o"

# External object files for target sleepmutex
sleepmutex_EXTERNAL_OBJECTS =

folder_concurrency_patterns/app_sleepmutex/sleepmutex: folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/sleepmutex.cpp.o
folder_concurrency_patterns/app_sleepmutex/sleepmutex: folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/build.make
folder_concurrency_patterns/app_sleepmutex/sleepmutex: folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivin/CLionProjects/concurrent_and_distributed_systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sleepmutex"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_sleepmutex && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sleepmutex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/build: folder_concurrency_patterns/app_sleepmutex/sleepmutex

.PHONY : folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/build

folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/clean:
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_sleepmutex && $(CMAKE_COMMAND) -P CMakeFiles/sleepmutex.dir/cmake_clean.cmake
.PHONY : folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/clean

folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/depend:
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivin/CLionProjects/concurrent_and_distributed_systems /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_sleepmutex /home/ivin/CLionProjects/concurrent_and_distributed_systems/build /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_sleepmutex /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : folder_concurrency_patterns/app_sleepmutex/CMakeFiles/sleepmutex.dir/depend

