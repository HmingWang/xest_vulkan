cmake_minimum_required(VERSION 3.22)
project(PixelGame)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)

add_executable(${PROJECT_NAME} main.cpp olcPixelGameEngine.h DemoGame.hpp)
target_link_libraries(${PROJECT_NAME})