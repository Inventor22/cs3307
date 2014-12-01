cmake_minimum_required(VERSION 2.8.4)
project(robotSim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES robot.cpp Algorithm.h HumiditySensor.h HumiditySensor.cpp IRSensor.h IRSensor.cpp LowestVal.h LowestVal.cpp LowFreq.h LowFreq.cpp Sensor.h Sensor.cpp)
add_executable(robotSim ${SOURCE_FILES})
