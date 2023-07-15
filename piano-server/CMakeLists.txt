cmake_minimum_required(VERSION 3.25)
project(piano_server C)
set(CMAKE_C_STANDARD 23)

find_library(WS NAMES ws)
include_directories(/usr/local/include/wsserver /usr/local/include/pigpio)

add_executable(piano_server main.c midi.c midi.h gpio.c gpio.h websocket.c websocket.h)
target_link_libraries(piano_server ${WS})