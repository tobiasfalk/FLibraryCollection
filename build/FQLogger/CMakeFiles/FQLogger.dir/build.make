# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tobias/git/FLC/FLibraryCollection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tobias/git/FLC/FLibraryCollection/build

# Include any dependencies generated for this target.
include FQLogger/CMakeFiles/FQLogger.dir/depend.make

# Include the progress variables for this target.
include FQLogger/CMakeFiles/FQLogger.dir/progress.make

# Include the compile flags for this target's objects.
include FQLogger/CMakeFiles/FQLogger.dir/flags.make

FQLogger/CMakeFiles/FQLogger.dir/FQLogger.cpp.o: FQLogger/CMakeFiles/FQLogger.dir/flags.make
FQLogger/CMakeFiles/FQLogger.dir/FQLogger.cpp.o: ../FQLogger/FQLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tobias/git/FLC/FLibraryCollection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object FQLogger/CMakeFiles/FQLogger.dir/FQLogger.cpp.o"
	cd /home/tobias/git/FLC/FLibraryCollection/build/FQLogger && /usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FQLogger.dir/FQLogger.cpp.o -c /home/tobias/git/FLC/FLibraryCollection/FQLogger/FQLogger.cpp

FQLogger/CMakeFiles/FQLogger.dir/FQLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FQLogger.dir/FQLogger.cpp.i"
	cd /home/tobias/git/FLC/FLibraryCollection/build/FQLogger && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tobias/git/FLC/FLibraryCollection/FQLogger/FQLogger.cpp > CMakeFiles/FQLogger.dir/FQLogger.cpp.i

FQLogger/CMakeFiles/FQLogger.dir/FQLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FQLogger.dir/FQLogger.cpp.s"
	cd /home/tobias/git/FLC/FLibraryCollection/build/FQLogger && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tobias/git/FLC/FLibraryCollection/FQLogger/FQLogger.cpp -o CMakeFiles/FQLogger.dir/FQLogger.cpp.s

# Object files for target FQLogger
FQLogger_OBJECTS = \
"CMakeFiles/FQLogger.dir/FQLogger.cpp.o"

# External object files for target FQLogger
FQLogger_EXTERNAL_OBJECTS =

FQLogger/libFQLogger.so: FQLogger/CMakeFiles/FQLogger.dir/FQLogger.cpp.o
FQLogger/libFQLogger.so: FQLogger/CMakeFiles/FQLogger.dir/build.make
FQLogger/libFQLogger.so: /usr/lib64/libQt5Core.so.5.12.7
FQLogger/libFQLogger.so: FQLogger/CMakeFiles/FQLogger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tobias/git/FLC/FLibraryCollection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libFQLogger.so"
	cd /home/tobias/git/FLC/FLibraryCollection/build/FQLogger && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FQLogger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
FQLogger/CMakeFiles/FQLogger.dir/build: FQLogger/libFQLogger.so

.PHONY : FQLogger/CMakeFiles/FQLogger.dir/build

FQLogger/CMakeFiles/FQLogger.dir/clean:
	cd /home/tobias/git/FLC/FLibraryCollection/build/FQLogger && $(CMAKE_COMMAND) -P CMakeFiles/FQLogger.dir/cmake_clean.cmake
.PHONY : FQLogger/CMakeFiles/FQLogger.dir/clean

FQLogger/CMakeFiles/FQLogger.dir/depend:
	cd /home/tobias/git/FLC/FLibraryCollection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tobias/git/FLC/FLibraryCollection /home/tobias/git/FLC/FLibraryCollection/FQLogger /home/tobias/git/FLC/FLibraryCollection/build /home/tobias/git/FLC/FLibraryCollection/build/FQLogger /home/tobias/git/FLC/FLibraryCollection/build/FQLogger/CMakeFiles/FQLogger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : FQLogger/CMakeFiles/FQLogger.dir/depend

