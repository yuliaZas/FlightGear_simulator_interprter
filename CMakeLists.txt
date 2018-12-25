cmake_minimum_required(VERSION 3.13)
project(flight_simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(flight_simulator
        assigmentCommand.cpp
        assigmentCommand.h
        command.cpp
        command.h
        connectCommand.cpp
        connectCommand.h
        ifCommand.cpp
        ifCommand.h
        main.cpp
        ODSCommand.cpp
        ODSCommand.h
        Parser.cpp
        Parser.h
        printCommand.cpp
        printCommand.h
        sleepCommand.cpp
        sleepCommand.h
        varCommand.cpp
        varCommand.h
        whileCommand.cpp
        whileCommand.h)
