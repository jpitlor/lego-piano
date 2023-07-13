cmake_minimum_required(VERSION 3.25)
project(piano_server C)

add_subdirectory(wsServer)

set(CMAKE_C_STANDARD 23)

add_executable(piano_server main.c)
