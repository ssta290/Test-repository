cmake_minimum_required(VERSION 3.10)
project(Animal)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "src/*.cpp")

add_executable(Animal ${SOURCES})