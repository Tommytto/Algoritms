# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/timur/education/Algoritms/code/Search

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/timur/education/Algoritms/code/Search/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Search.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Search.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Search.dir/flags.make

CMakeFiles/Search.dir/main.cpp.o: CMakeFiles/Search.dir/flags.make
CMakeFiles/Search.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/timur/education/Algoritms/code/Search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Search.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Search.dir/main.cpp.o -c /home/timur/education/Algoritms/code/Search/main.cpp

CMakeFiles/Search.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Search.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/timur/education/Algoritms/code/Search/main.cpp > CMakeFiles/Search.dir/main.cpp.i

CMakeFiles/Search.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Search.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/timur/education/Algoritms/code/Search/main.cpp -o CMakeFiles/Search.dir/main.cpp.s

CMakeFiles/Search.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Search.dir/main.cpp.o.requires

CMakeFiles/Search.dir/main.cpp.o.provides: CMakeFiles/Search.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Search.dir/build.make CMakeFiles/Search.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Search.dir/main.cpp.o.provides

CMakeFiles/Search.dir/main.cpp.o.provides.build: CMakeFiles/Search.dir/main.cpp.o


CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o: CMakeFiles/Search.dir/flags.make
CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o: ../AlgoritmsInSorted.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/timur/education/Algoritms/code/Search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o -c /home/timur/education/Algoritms/code/Search/AlgoritmsInSorted.cpp

CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/timur/education/Algoritms/code/Search/AlgoritmsInSorted.cpp > CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.i

CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/timur/education/Algoritms/code/Search/AlgoritmsInSorted.cpp -o CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.s

CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.requires:

.PHONY : CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.requires

CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.provides: CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.requires
	$(MAKE) -f CMakeFiles/Search.dir/build.make CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.provides.build
.PHONY : CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.provides

CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.provides.build: CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o


CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o: CMakeFiles/Search.dir/flags.make
CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o: ../AlgoritmsInUnsorted.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/timur/education/Algoritms/code/Search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o -c /home/timur/education/Algoritms/code/Search/AlgoritmsInUnsorted.cpp

CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/timur/education/Algoritms/code/Search/AlgoritmsInUnsorted.cpp > CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.i

CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/timur/education/Algoritms/code/Search/AlgoritmsInUnsorted.cpp -o CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.s

CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.requires:

.PHONY : CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.requires

CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.provides: CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.requires
	$(MAKE) -f CMakeFiles/Search.dir/build.make CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.provides.build
.PHONY : CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.provides

CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.provides.build: CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o


# Object files for target Search
Search_OBJECTS = \
"CMakeFiles/Search.dir/main.cpp.o" \
"CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o" \
"CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o"

# External object files for target Search
Search_EXTERNAL_OBJECTS =

Search: CMakeFiles/Search.dir/main.cpp.o
Search: CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o
Search: CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o
Search: CMakeFiles/Search.dir/build.make
Search: CMakeFiles/Search.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/timur/education/Algoritms/code/Search/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Search"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Search.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Search.dir/build: Search

.PHONY : CMakeFiles/Search.dir/build

CMakeFiles/Search.dir/requires: CMakeFiles/Search.dir/main.cpp.o.requires
CMakeFiles/Search.dir/requires: CMakeFiles/Search.dir/AlgoritmsInSorted.cpp.o.requires
CMakeFiles/Search.dir/requires: CMakeFiles/Search.dir/AlgoritmsInUnsorted.cpp.o.requires

.PHONY : CMakeFiles/Search.dir/requires

CMakeFiles/Search.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Search.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Search.dir/clean

CMakeFiles/Search.dir/depend:
	cd /home/timur/education/Algoritms/code/Search/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/timur/education/Algoritms/code/Search /home/timur/education/Algoritms/code/Search /home/timur/education/Algoritms/code/Search/cmake-build-debug /home/timur/education/Algoritms/code/Search/cmake-build-debug /home/timur/education/Algoritms/code/Search/cmake-build-debug/CMakeFiles/Search.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Search.dir/depend

