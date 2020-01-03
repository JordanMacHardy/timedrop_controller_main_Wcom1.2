cmake_minimum_required(VERSION 3.13)
project(timedrop_controller_main_Wcom1_2)

set(CMAKE_CXX_STANDARD 14)


include_directories(.)

add_executable(timedrop_controller_main_Wcom1_2
        Button.cpp
        Button.h
        globalVariables.h
        Knob.cpp
        Knob.h
        pin_definitions.h
        setUp.h
        timedrop_controller_main_Wcom1.2.ino)
