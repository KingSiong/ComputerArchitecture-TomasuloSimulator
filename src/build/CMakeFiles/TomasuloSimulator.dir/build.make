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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build"

# Include any dependencies generated for this target.
include CMakeFiles/TomasuloSimulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TomasuloSimulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TomasuloSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TomasuloSimulator.dir/flags.make

CMakeFiles/TomasuloSimulator.dir/main.cpp.o: CMakeFiles/TomasuloSimulator.dir/flags.make
CMakeFiles/TomasuloSimulator.dir/main.cpp.o: ../main.cpp
CMakeFiles/TomasuloSimulator.dir/main.cpp.o: CMakeFiles/TomasuloSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TomasuloSimulator.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TomasuloSimulator.dir/main.cpp.o -MF CMakeFiles/TomasuloSimulator.dir/main.cpp.o.d -o CMakeFiles/TomasuloSimulator.dir/main.cpp.o -c "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/main.cpp"

CMakeFiles/TomasuloSimulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TomasuloSimulator.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/main.cpp" > CMakeFiles/TomasuloSimulator.dir/main.cpp.i

CMakeFiles/TomasuloSimulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TomasuloSimulator.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/main.cpp" -o CMakeFiles/TomasuloSimulator.dir/main.cpp.s

CMakeFiles/TomasuloSimulator.dir/command.cpp.o: CMakeFiles/TomasuloSimulator.dir/flags.make
CMakeFiles/TomasuloSimulator.dir/command.cpp.o: ../command.cpp
CMakeFiles/TomasuloSimulator.dir/command.cpp.o: CMakeFiles/TomasuloSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TomasuloSimulator.dir/command.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TomasuloSimulator.dir/command.cpp.o -MF CMakeFiles/TomasuloSimulator.dir/command.cpp.o.d -o CMakeFiles/TomasuloSimulator.dir/command.cpp.o -c "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/command.cpp"

CMakeFiles/TomasuloSimulator.dir/command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TomasuloSimulator.dir/command.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/command.cpp" > CMakeFiles/TomasuloSimulator.dir/command.cpp.i

CMakeFiles/TomasuloSimulator.dir/command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TomasuloSimulator.dir/command.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/command.cpp" -o CMakeFiles/TomasuloSimulator.dir/command.cpp.s

CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o: CMakeFiles/TomasuloSimulator.dir/flags.make
CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o: ../Instruction.cpp
CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o: CMakeFiles/TomasuloSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o -MF CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o.d -o CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o -c "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/Instruction.cpp"

CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/Instruction.cpp" > CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.i

CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/Instruction.cpp" -o CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.s

CMakeFiles/TomasuloSimulator.dir/String.cpp.o: CMakeFiles/TomasuloSimulator.dir/flags.make
CMakeFiles/TomasuloSimulator.dir/String.cpp.o: ../String.cpp
CMakeFiles/TomasuloSimulator.dir/String.cpp.o: CMakeFiles/TomasuloSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TomasuloSimulator.dir/String.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TomasuloSimulator.dir/String.cpp.o -MF CMakeFiles/TomasuloSimulator.dir/String.cpp.o.d -o CMakeFiles/TomasuloSimulator.dir/String.cpp.o -c "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/String.cpp"

CMakeFiles/TomasuloSimulator.dir/String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TomasuloSimulator.dir/String.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/String.cpp" > CMakeFiles/TomasuloSimulator.dir/String.cpp.i

CMakeFiles/TomasuloSimulator.dir/String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TomasuloSimulator.dir/String.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/String.cpp" -o CMakeFiles/TomasuloSimulator.dir/String.cpp.s

CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o: CMakeFiles/TomasuloSimulator.dir/flags.make
CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o: ../RegisterStatus.cpp
CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o: CMakeFiles/TomasuloSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o -MF CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o.d -o CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o -c "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/RegisterStatus.cpp"

CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/RegisterStatus.cpp" > CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.i

CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/RegisterStatus.cpp" -o CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.s

CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o: CMakeFiles/TomasuloSimulator.dir/flags.make
CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o: ../ReserveStation.cpp
CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o: CMakeFiles/TomasuloSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o -MF CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o.d -o CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o -c "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/ReserveStation.cpp"

CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/ReserveStation.cpp" > CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.i

CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/ReserveStation.cpp" -o CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.s

CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o: CMakeFiles/TomasuloSimulator.dir/flags.make
CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o: ../InstructionStatus.cpp
CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o: CMakeFiles/TomasuloSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o -MF CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o.d -o CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o -c "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/InstructionStatus.cpp"

CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/InstructionStatus.cpp" > CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.i

CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/InstructionStatus.cpp" -o CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.s

# Object files for target TomasuloSimulator
TomasuloSimulator_OBJECTS = \
"CMakeFiles/TomasuloSimulator.dir/main.cpp.o" \
"CMakeFiles/TomasuloSimulator.dir/command.cpp.o" \
"CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o" \
"CMakeFiles/TomasuloSimulator.dir/String.cpp.o" \
"CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o" \
"CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o" \
"CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o"

# External object files for target TomasuloSimulator
TomasuloSimulator_EXTERNAL_OBJECTS =

TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/main.cpp.o
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/command.cpp.o
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/Instruction.cpp.o
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/String.cpp.o
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/RegisterStatus.cpp.o
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/ReserveStation.cpp.o
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/InstructionStatus.cpp.o
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/build.make
TomasuloSimulator: CMakeFiles/TomasuloSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable TomasuloSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TomasuloSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TomasuloSimulator.dir/build: TomasuloSimulator
.PHONY : CMakeFiles/TomasuloSimulator.dir/build

CMakeFiles/TomasuloSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TomasuloSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TomasuloSimulator.dir/clean

CMakeFiles/TomasuloSimulator.dir/depend:
	cd "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src" "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src" "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build" "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build" "/Users/shijinsong/Documents/Course/ComputerArchitecture/Lab#3/src/build/CMakeFiles/TomasuloSimulator.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TomasuloSimulator.dir/depend

