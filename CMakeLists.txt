#a normal cmakelists.txt file
cmake_minimum_required(VERSION 3.2)

# set the location of the cmopiler

include_directories("C:/MinGW/include" "./include")


project(EmbeddedDiploma)


add_executable(EmbeddedDiploma app.c src/stack.c)

