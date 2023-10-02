cmake_minimum_required(VERSION 3.25)
project(a7_912_Daraban_Tudor_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a7_912_Daraban_Tudor_1
        Event.cpp
        Event.h
        main.cpp
        Repo.cpp
        Repo.h
        ServiceAdmin.cpp
        ServiceAdmin.h
        UI.cpp
        UI.h EventFile.cpp EventFile.h CSVEventList.cpp CSVEventList.h HTMLEventList.cpp HTMLEventList.h eventValidator.cpp eventValidator.h)
