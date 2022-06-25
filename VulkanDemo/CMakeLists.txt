cmake_minimum_required(VERSION 3.22)
project(vulkan-demo)

set(CMAKE_CXX_STANDARD 23)


include_directories(D:/VulkanSDK/1.3.216.0/Include)
include_directories("C:/Program Files (x86)/GLFW/include")
include_directories(D:/VulkanSDK/glm-0.9.9.8/glm)
include_directories(D:/VulkanSDK/tinyobjloader-1.0.6)
# ¿âÄ¿Â¼
link_directories(D:/vulkanSDK/1.3.216.0/Lib)
link_directories("C:/Program Files (x86)/GLFW/lib")


include_directories(/usr/local/Cellar/glfw/3.3.7/include)
include_directories(/usr/local/Cellar/glm/0.9.9.8/include)
include_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/include)

# ¿âÄ¿Â¼
link_directories(/usr/local/Cellar/glfw/3.3.7/lib)
link_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/lib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} glfw3 vulkan-1)