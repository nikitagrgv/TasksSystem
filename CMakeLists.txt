cmake_minimum_required(VERSION 3.24)
project(TasksSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(TasksSystem src/main.cpp src/TasksManager.cpp src/TasksManager.h)
