cmake_minimum_required(VERSION 3.10)

project(TomasuloSimulator)

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -O2)

add_executable(TomasuloSimulator main.cpp command.cpp Instruction.cpp String.cpp RegisterStatus.cpp ReserveStation.cpp InstructionStatus.cpp)