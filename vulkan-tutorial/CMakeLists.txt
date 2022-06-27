cmake_minimum_required(VERSION 3.22)
project(vulkan-tutorial)

set(CMAKE_CXX_STANDARD 23)
include(BuildConfig.cmake)



add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${LIB_VULKAN})