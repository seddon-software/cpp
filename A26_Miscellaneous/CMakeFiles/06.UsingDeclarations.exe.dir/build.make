# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/chris/home/workspace/cpp/Build2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/home/workspace/cpp/Build2/build

# Include any dependencies generated for this target.
include /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/progress.make

# Include the compile flags for this target's objects.
include /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/flags.make

/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o: /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/flags.make
/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o: /home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.cpp
/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o: /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/home/workspace/cpp/Build2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o"
	cd /home/chris/home/workspace/cpp/A26_Miscellaneous && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o -MF CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o.d -o CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o -c /home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.cpp

/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.i"
	cd /home/chris/home/workspace/cpp/A26_Miscellaneous && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.cpp > CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.i

/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.s"
	cd /home/chris/home/workspace/cpp/A26_Miscellaneous && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.cpp -o CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.s

# Object files for target 06.UsingDeclarations.exe
06_UsingDeclarations_exe_OBJECTS = \
"CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o"

# External object files for target 06.UsingDeclarations.exe
06_UsingDeclarations_exe_EXTERNAL_OBJECTS =

/home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.exe: /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/06.UsingDeclarations.cpp.o
/home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.exe: /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/build.make
/home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.exe: /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/home/workspace/cpp/Build2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 06.UsingDeclarations.exe"
	cd /home/chris/home/workspace/cpp/A26_Miscellaneous && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/06.UsingDeclarations.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/build: /home/chris/home/workspace/cpp/A26_Miscellaneous/06.UsingDeclarations.exe
.PHONY : /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/build

/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/clean:
	cd /home/chris/home/workspace/cpp/A26_Miscellaneous && $(CMAKE_COMMAND) -P CMakeFiles/06.UsingDeclarations.exe.dir/cmake_clean.cmake
.PHONY : /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/clean

/home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/depend:
	cd /home/chris/home/workspace/cpp/Build2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/home/workspace/cpp/Build2 /home/chris/home/workspace/cpp/A26_Miscellaneous /home/chris/home/workspace/cpp/Build2/build /home/chris/home/workspace/cpp/A26_Miscellaneous /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : /home/chris/home/workspace/cpp/A26_Miscellaneous/CMakeFiles/06.UsingDeclarations.exe.dir/depend

