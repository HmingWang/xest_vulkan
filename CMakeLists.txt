cmake_minimum_required(VERSION 3.22)
project(xest_vulkan)

set(CMAKE_CXX_STANDARD 23)
# 包含目录
include_directories(/usr/local/Cellar/glfw/3.3.7/include)
include_directories(/usr/local/Cellar/glm/0.9.9.8/include)
include_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/include)

# 库目录
link_directories(/usr/local/Cellar/glfw/3.3.7/lib)
link_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/lib)

add_executable(main main.cpp IApplication.h XestDefine.h HelloTriangleApplication.cpp HelloTriangleApplication.h)
target_link_libraries(main glfw vulkan)
