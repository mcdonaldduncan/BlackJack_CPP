cmake_minimum_required (VERSION 3.22)

project (BlackJackCPP)

include_directories(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2")

add_executable (BlackJackCPP BlackJackCPP.cpp GameLogic.cpp)

