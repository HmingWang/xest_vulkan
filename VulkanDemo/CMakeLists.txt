cmake_minimum_required(VERSION 3.22)
project(vulkan-demo)

include(BuildConfig.cmake)
set(CMAKE_CXX_STANDARD 23)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.*)
message(STATUS "the project source list: ${HPP_FILES}")

add_executable(${PROJECT_NAME} ${HPP_FILES})
target_link_libraries(${PROJECT_NAME} glfw3 vulkan-1)