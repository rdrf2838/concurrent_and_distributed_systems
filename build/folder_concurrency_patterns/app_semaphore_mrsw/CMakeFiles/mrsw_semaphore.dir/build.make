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
include folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/depend.make

# Include the progress variables for this target.
include folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/progress.make

# Include the compile flags for this target's objects.
include folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/flags.make

folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.o: folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/flags.make
folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.o: ../folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivin/CLionProjects/concurrent_and_distributed_systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.o"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_semaphore_mrsw && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.o -c /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore.cpp

folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.i"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_semaphore_mrsw && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore.cpp > CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.i

folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.s"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_semaphore_mrsw && /bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore.cpp -o CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.s

# Object files for target mrsw_semaphore
mrsw_semaphore_OBJECTS = \
"CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.o"

# External object files for target mrsw_semaphore
mrsw_semaphore_EXTERNAL_OBJECTS =

folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore: folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/mrsw_semaphore.cpp.o
folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore: folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/build.make
folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore: folder_concurrency_patterns/source/libpatterns.a
folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore: folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivin/CLionProjects/concurrent_and_distributed_systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mrsw_semaphore"
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_semaphore_mrsw && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mrsw_semaphore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/build: folder_concurrency_patterns/app_semaphore_mrsw/mrsw_semaphore

.PHONY : folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/build

folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/clean:
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_semaphore_mrsw && $(CMAKE_COMMAND) -P CMakeFiles/mrsw_semaphore.dir/cmake_clean.cmake
.PHONY : folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/clean

folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/depend:
	cd /home/ivin/CLionProjects/concurrent_and_distributed_systems/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivin/CLionProjects/concurrent_and_distributed_systems /home/ivin/CLionProjects/concurrent_and_distributed_systems/folder_concurrency_patterns/app_semaphore_mrsw /home/ivin/CLionProjects/concurrent_and_distributed_systems/build /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_semaphore_mrsw /home/ivin/CLionProjects/concurrent_and_distributed_systems/build/folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : folder_concurrency_patterns/app_semaphore_mrsw/CMakeFiles/mrsw_semaphore.dir/depend

