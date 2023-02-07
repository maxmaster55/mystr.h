#a normal cmakelists.txt file
cmake_minimum_required(VERSION 3.2)

# set the location of the cmopiler
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

project(EmbeddedDiploma)


add_executable(EmbeddedDiploma app.c)

