cmake_minimum_required(VERSION 3.12)
project(flight_simulator)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-pthread")

include_directories(.)

add_executable(
        assigmentCommand.h
        assigmentCommand.cpp
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
        whileCommand.h
        Expression/Expression.h
        Expression/Number.h
        Expression/Number.cpp
        Expression/BinaryExpression.h
        Expression/BinaryExpression.cpp
        Expression/Plus.cpp
        Expression/Plus.h
        Expression/Minus.h
        Expression/Minus.cpp
        Expression/Mul.h
        Expression/Mul.cpp
        Expression/Div.cpp
        Expression/Div.h
        Expression/Bigger.h
        Expression/Bigger.cpp
        Expression/Smaller.h
        Expression/Smaller.cpp
        Expression/Equal.h
        Expression/Equal.cpp
        Expression/NotEqual.h
        Expression/NotEqual.cpp
        Expression/BiggerEqual.h
        Expression/BiggerEqual.cpp
        Expression/SmallerEqual.h
        Expression/SmallerEqual.cpp
        Expression/ExpressionFactory.h
        Expression/ExpressionFactory.cpp
        Lexer.h
        Lexer.cpp
        openDataServer.cpp openDataServer.h connectToServer.cpp connectToServer.h exitCommand.cpp exitCommand.h State.cpp State.h ISearchable.cpp ISearchable.h matrixMaze.cpp matrixMaze.h)
