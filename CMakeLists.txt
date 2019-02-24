cmake_minimum_required(VERSION 3.5)
project(lettcode_practice)

set(CMAKE_CXX_FLAGS "-fno-stack-protector ${CMAKE_CXX_FLAGS} -std=c++11 ")

ADD_SUBDIRECTORY(array)
SET(SOURCE_FILES main.cpp array/init.cpp)
ADD_EXECUTABLE(lettcode-practice ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(lettcode-practice array)