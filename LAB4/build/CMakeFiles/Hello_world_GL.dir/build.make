# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.0

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\apps\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\apps\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\build

# Include any dependencies generated for this target.
include CMakeFiles/Hello_world_GL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hello_world_GL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hello_world_GL.dir/flags.make

CMakeFiles/Hello_world_GL.dir/main.cpp.obj: CMakeFiles/Hello_world_GL.dir/flags.make
CMakeFiles/Hello_world_GL.dir/main.cpp.obj: CMakeFiles/Hello_world_GL.dir/includes_CXX.rsp
CMakeFiles/Hello_world_GL.dir/main.cpp.obj: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\build\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Hello_world_GL.dir/main.cpp.obj"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\Hello_world_GL.dir\main.cpp.obj -c C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\main.cpp

CMakeFiles/Hello_world_GL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hello_world_GL.dir/main.cpp.i"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\main.cpp > CMakeFiles\Hello_world_GL.dir\main.cpp.i

CMakeFiles/Hello_world_GL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hello_world_GL.dir/main.cpp.s"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\main.cpp -o CMakeFiles\Hello_world_GL.dir\main.cpp.s

CMakeFiles/Hello_world_GL.dir/main.cpp.obj.requires:
.PHONY : CMakeFiles/Hello_world_GL.dir/main.cpp.obj.requires

CMakeFiles/Hello_world_GL.dir/main.cpp.obj.provides: CMakeFiles/Hello_world_GL.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Hello_world_GL.dir\build.make CMakeFiles/Hello_world_GL.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Hello_world_GL.dir/main.cpp.obj.provides

CMakeFiles/Hello_world_GL.dir/main.cpp.obj.provides.build: CMakeFiles/Hello_world_GL.dir/main.cpp.obj

CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj: CMakeFiles/Hello_world_GL.dir/flags.make
CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj: CMakeFiles/Hello_world_GL.dir/includes_CXX.rsp
CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj: ../visuals.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\build\CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\Hello_world_GL.dir\visuals.cpp.obj -c C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\visuals.cpp

CMakeFiles/Hello_world_GL.dir/visuals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hello_world_GL.dir/visuals.cpp.i"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\visuals.cpp > CMakeFiles\Hello_world_GL.dir\visuals.cpp.i

CMakeFiles/Hello_world_GL.dir/visuals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hello_world_GL.dir/visuals.cpp.s"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\visuals.cpp -o CMakeFiles\Hello_world_GL.dir\visuals.cpp.s

CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.requires:
.PHONY : CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.requires

CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.provides: CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Hello_world_GL.dir\build.make CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.provides.build
.PHONY : CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.provides

CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.provides.build: CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj

CMakeFiles/Hello_world_GL.dir/shader.cpp.obj: CMakeFiles/Hello_world_GL.dir/flags.make
CMakeFiles/Hello_world_GL.dir/shader.cpp.obj: CMakeFiles/Hello_world_GL.dir/includes_CXX.rsp
CMakeFiles/Hello_world_GL.dir/shader.cpp.obj: ../shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\build\CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Hello_world_GL.dir/shader.cpp.obj"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\Hello_world_GL.dir\shader.cpp.obj -c C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\shader.cpp

CMakeFiles/Hello_world_GL.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hello_world_GL.dir/shader.cpp.i"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\shader.cpp > CMakeFiles\Hello_world_GL.dir\shader.cpp.i

CMakeFiles/Hello_world_GL.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hello_world_GL.dir/shader.cpp.s"
	C:\apps\Qt\Qt5.3.1\Tools\mingw482_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\shader.cpp -o CMakeFiles\Hello_world_GL.dir\shader.cpp.s

CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.requires:
.PHONY : CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.requires

CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.provides: CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Hello_world_GL.dir\build.make CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.provides.build
.PHONY : CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.provides

CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.provides.build: CMakeFiles/Hello_world_GL.dir/shader.cpp.obj

# Object files for target Hello_world_GL
Hello_world_GL_OBJECTS = \
"CMakeFiles/Hello_world_GL.dir/main.cpp.obj" \
"CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj" \
"CMakeFiles/Hello_world_GL.dir/shader.cpp.obj"

# External object files for target Hello_world_GL
Hello_world_GL_EXTERNAL_OBJECTS =

../bin/Hello_world_GL.exe: CMakeFiles/Hello_world_GL.dir/main.cpp.obj
../bin/Hello_world_GL.exe: CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj
../bin/Hello_world_GL.exe: CMakeFiles/Hello_world_GL.dir/shader.cpp.obj
../bin/Hello_world_GL.exe: CMakeFiles/Hello_world_GL.dir/build.make
../bin/Hello_world_GL.exe: ../freeglut-mingw/lib/libfreeglut.a
../bin/Hello_world_GL.exe: ../glew-mingw/lib/libglew32.dll.a
../bin/Hello_world_GL.exe: CMakeFiles/Hello_world_GL.dir/objects1.rsp
../bin/Hello_world_GL.exe: CMakeFiles/Hello_world_GL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ..\bin\Hello_world_GL.exe"
	C:\apps\CMake\bin\cmake.exe -E copy C:/Users/student.AD-IME-NTNU-NO.014/Desktop/LAB4/freeglut-mingw/bin/freeglut.dll C:/Users/student.AD-IME-NTNU-NO.014/Desktop/LAB4/bin/
	C:\apps\CMake\bin\cmake.exe -E copy C:/Users/student.AD-IME-NTNU-NO.014/Desktop/LAB4/glew-mingw/bin/glew32.dll C:/Users/student.AD-IME-NTNU-NO.014/Desktop/LAB4/bin/
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Hello_world_GL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hello_world_GL.dir/build: ../bin/Hello_world_GL.exe
.PHONY : CMakeFiles/Hello_world_GL.dir/build

CMakeFiles/Hello_world_GL.dir/requires: CMakeFiles/Hello_world_GL.dir/main.cpp.obj.requires
CMakeFiles/Hello_world_GL.dir/requires: CMakeFiles/Hello_world_GL.dir/visuals.cpp.obj.requires
CMakeFiles/Hello_world_GL.dir/requires: CMakeFiles/Hello_world_GL.dir/shader.cpp.obj.requires
.PHONY : CMakeFiles/Hello_world_GL.dir/requires

CMakeFiles/Hello_world_GL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Hello_world_GL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Hello_world_GL.dir/clean

CMakeFiles/Hello_world_GL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4 C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4 C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\build C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\build C:\Users\student.AD-IME-NTNU-NO.014\Desktop\LAB4\build\CMakeFiles\Hello_world_GL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hello_world_GL.dir/depend
