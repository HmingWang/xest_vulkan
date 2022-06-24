cmake_minimum_required(VERSION 3.22)
project(xest_vulkan)

set(CMAKE_CXX_STANDARD 23)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    #编写语句
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    #编写语句
    # 包含目录
    include_directories(/usr/local/Cellar/glfw/3.3.7/include)
    include_directories(/usr/local/Cellar/glm/0.9.9.8/include)
    include_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/include)

    # 库目录
    link_directories(/usr/local/Cellar/glfw/3.3.7/lib)
    link_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    #编写语句
    include_directories(D:/VulkanSDK/1.3.216.0/Include)
    include_directories("C:/Program Files (x86)/GLFW/include")
    # 库目录
    link_directories(D:/vulkanSDK/1.3.216.0/Lib)
    link_directories("C:/Program Files (x86)/GLFW/lib")

elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    #编写语句
else()
    message(STATUS "Cur System: ${CMAKE_SYSTEM_NAME}")
endif()


set(CMAKE_CXX_FLAGS /std:c++latest)




add_executable(main main.cpp IApplication.h XestDefine.h HelloTriangleApplication.cpp HelloTriangleApplication.h)
target_link_libraries(main glfw3 vulkan-1)
