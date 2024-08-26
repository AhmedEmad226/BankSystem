cmake_minimum_required(VERSION 3.28)
project(MoazProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MoazProject main.cpp
        Person.h
        Admin.h
        Employee.h
        Client.h
        DataSourceInterface.h)
