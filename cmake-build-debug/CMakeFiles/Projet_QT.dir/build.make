# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Projet_QT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Projet_QT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Projet_QT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projet_QT.dir/flags.make

CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o: CMakeFiles/Projet_QT.dir/flags.make
CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o: Projet_QT_autogen/mocs_compilation.cpp
CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o: CMakeFiles/Projet_QT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o -MF CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o -c "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/Projet_QT_autogen/mocs_compilation.cpp"

CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/Projet_QT_autogen/mocs_compilation.cpp" > CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.i

CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/Projet_QT_autogen/mocs_compilation.cpp" -o CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.s

CMakeFiles/Projet_QT.dir/main.cpp.o: CMakeFiles/Projet_QT.dir/flags.make
CMakeFiles/Projet_QT.dir/main.cpp.o: /mnt/c/Users/damra/OneDrive/Bureau/C++/Projet\ QT/main.cpp
CMakeFiles/Projet_QT.dir/main.cpp.o: CMakeFiles/Projet_QT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Projet_QT.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projet_QT.dir/main.cpp.o -MF CMakeFiles/Projet_QT.dir/main.cpp.o.d -o CMakeFiles/Projet_QT.dir/main.cpp.o -c "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/main.cpp"

CMakeFiles/Projet_QT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projet_QT.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/main.cpp" > CMakeFiles/Projet_QT.dir/main.cpp.i

CMakeFiles/Projet_QT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projet_QT.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/main.cpp" -o CMakeFiles/Projet_QT.dir/main.cpp.s

CMakeFiles/Projet_QT.dir/MainWindow.cpp.o: CMakeFiles/Projet_QT.dir/flags.make
CMakeFiles/Projet_QT.dir/MainWindow.cpp.o: /mnt/c/Users/damra/OneDrive/Bureau/C++/Projet\ QT/MainWindow.cpp
CMakeFiles/Projet_QT.dir/MainWindow.cpp.o: CMakeFiles/Projet_QT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Projet_QT.dir/MainWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projet_QT.dir/MainWindow.cpp.o -MF CMakeFiles/Projet_QT.dir/MainWindow.cpp.o.d -o CMakeFiles/Projet_QT.dir/MainWindow.cpp.o -c "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/MainWindow.cpp"

CMakeFiles/Projet_QT.dir/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projet_QT.dir/MainWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/MainWindow.cpp" > CMakeFiles/Projet_QT.dir/MainWindow.cpp.i

CMakeFiles/Projet_QT.dir/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projet_QT.dir/MainWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/MainWindow.cpp" -o CMakeFiles/Projet_QT.dir/MainWindow.cpp.s

CMakeFiles/Projet_QT.dir/MyScene.cpp.o: CMakeFiles/Projet_QT.dir/flags.make
CMakeFiles/Projet_QT.dir/MyScene.cpp.o: /mnt/c/Users/damra/OneDrive/Bureau/C++/Projet\ QT/MyScene.cpp
CMakeFiles/Projet_QT.dir/MyScene.cpp.o: CMakeFiles/Projet_QT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Projet_QT.dir/MyScene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projet_QT.dir/MyScene.cpp.o -MF CMakeFiles/Projet_QT.dir/MyScene.cpp.o.d -o CMakeFiles/Projet_QT.dir/MyScene.cpp.o -c "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/MyScene.cpp"

CMakeFiles/Projet_QT.dir/MyScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projet_QT.dir/MyScene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/MyScene.cpp" > CMakeFiles/Projet_QT.dir/MyScene.cpp.i

CMakeFiles/Projet_QT.dir/MyScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projet_QT.dir/MyScene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/MyScene.cpp" -o CMakeFiles/Projet_QT.dir/MyScene.cpp.s

# Object files for target Projet_QT
Projet_QT_OBJECTS = \
"CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Projet_QT.dir/main.cpp.o" \
"CMakeFiles/Projet_QT.dir/MainWindow.cpp.o" \
"CMakeFiles/Projet_QT.dir/MyScene.cpp.o"

# External object files for target Projet_QT
Projet_QT_EXTERNAL_OBJECTS =

Projet_QT: CMakeFiles/Projet_QT.dir/Projet_QT_autogen/mocs_compilation.cpp.o
Projet_QT: CMakeFiles/Projet_QT.dir/main.cpp.o
Projet_QT: CMakeFiles/Projet_QT.dir/MainWindow.cpp.o
Projet_QT: CMakeFiles/Projet_QT.dir/MyScene.cpp.o
Projet_QT: CMakeFiles/Projet_QT.dir/build.make
Projet_QT: /usr/lib/x86_64-linux-gnu/libQt6Widgets.so.6.4.2
Projet_QT: /usr/lib/x86_64-linux-gnu/libQt6Gui.so.6.4.2
Projet_QT: /usr/lib/x86_64-linux-gnu/libQt6Core.so.6.4.2
Projet_QT: /usr/lib/x86_64-linux-gnu/libGLX.so
Projet_QT: /usr/lib/x86_64-linux-gnu/libOpenGL.so
Projet_QT: CMakeFiles/Projet_QT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Projet_QT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projet_QT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projet_QT.dir/build: Projet_QT
.PHONY : CMakeFiles/Projet_QT.dir/build

CMakeFiles/Projet_QT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projet_QT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projet_QT.dir/clean

CMakeFiles/Projet_QT.dir/depend:
	cd "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT" "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT" "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug" "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug" "/mnt/c/Users/damra/OneDrive/Bureau/C++/Projet QT/cmake-build-debug/CMakeFiles/Projet_QT.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Projet_QT.dir/depend

