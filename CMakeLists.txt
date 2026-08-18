cmake_minimum_required(VERSION 4.3)
project(PIDController)

set(CMAKE_CXX_STANDARD 20)

add_executable(PIDController main.cpp
        PID.cpp
        PID.h
        robot.cpp
        robot.h
        State.h
        Motor.cpp
        Motor.h
        Encoder.cpp
        Encoder.h
        MotorController.cpp
        MotorController.h
        DifferentialDrive.cpp
        DifferentialDrive.h)
