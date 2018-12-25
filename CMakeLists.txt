cmake_minimum_required(VERSION 3.13)
project(flight_simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(flight_simulator
        command/assigmentCommand.cpp
        command/assigmentCommand.h
        command/command.cpp
        command/command.h
        command/connectCommand.cpp
        command/connectCommand.h
        command/ifCommand.cpp
        command/ifCommand.h
        main.cpp
        command/ODSCommand.cpp
        command/ODSCommand.h
        Parser.cpp
        Parser.h
        command/printCommand.cpp
        command/printCommand.h
        command/sleepCommand.cpp
        command/sleepCommand.h
        command/varCommand.cpp
        command/varCommand.h
        command/whileCommand.cpp
        command/whileCommand.h)
