cmake_minimum_required(VERSION 3.31)
project(stl)

set(CMAKE_CXX_STANDARD 20)

add_executable(stl main.cpp
        ZonaControl.cpp
        ZonaControl.hpp
        Drone.cpp
        Drone.hpp
        Evento.cpp
        Evento.hpp
        Utils.hpp
        Ministerio.cpp
        Ministerio.hpp)
