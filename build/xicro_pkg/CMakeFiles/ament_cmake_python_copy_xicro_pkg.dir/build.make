# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/poom/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/poom/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/poom/ieee_ws/src/Xicro/xicro_pkg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/poom/ieee_ws/build/xicro_pkg

# Utility rule file for ament_cmake_python_copy_xicro_pkg.

# Include any custom commands dependencies for this target.
include CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/progress.make

CMakeFiles/ament_cmake_python_copy_xicro_pkg:
	/home/poom/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E copy_directory /home/poom/ieee_ws/src/Xicro/xicro_pkg/xicro_pkg /home/poom/ieee_ws/build/xicro_pkg/ament_cmake_python/xicro_pkg/xicro_pkg

ament_cmake_python_copy_xicro_pkg: CMakeFiles/ament_cmake_python_copy_xicro_pkg
ament_cmake_python_copy_xicro_pkg: CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/build.make
.PHONY : ament_cmake_python_copy_xicro_pkg

# Rule to build all files generated by this target.
CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/build: ament_cmake_python_copy_xicro_pkg
.PHONY : CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/build

CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/clean

CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/depend:
	cd /home/poom/ieee_ws/build/xicro_pkg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/poom/ieee_ws/src/Xicro/xicro_pkg /home/poom/ieee_ws/src/Xicro/xicro_pkg /home/poom/ieee_ws/build/xicro_pkg /home/poom/ieee_ws/build/xicro_pkg /home/poom/ieee_ws/build/xicro_pkg/CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ament_cmake_python_copy_xicro_pkg.dir/depend
