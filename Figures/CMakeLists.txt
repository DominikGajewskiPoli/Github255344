cmake_minimum_required(VERSION 3.22)
project(Figures)

set(CMAKE_CXX_STANDARD 14)

add_executable(Figures main.cpp Figure.cpp Figure.h Rectangle.cpp Rectangle.h Square.cpp Square.h
        Triangle.cpp Triangle.h Circle.h Circle.cpp
        Circle.cpp
        Rectangle.cpp)
