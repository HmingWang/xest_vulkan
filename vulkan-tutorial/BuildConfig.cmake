message(STATUS "custom find vulkan")

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")

    find_package(Vulkan)
    include_directories(../external)

    set(LIB_VULKAN glfw3 vulkan X11)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")

    # 包含目录
    include_directories(/usr/local/Cellar/glfw/3.3.7/include)
    include_directories(/usr/local/Cellar/glm/0.9.9.8/include)
    include_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/include)

    # 库目录
    link_directories(/usr/local/Cellar/glfw/3.3.7/lib)
    link_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/lib)

    set(LIB_VULKAN glfw vulkan)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")

    include_directories(D:/VulkanSDK/1.3.216.0/Include)
    include_directories("C:/Program Files (x86)/GLFW/include")
    include_directories(D:/VulkanSDK/glm-0.9.9.8/glm)
    include_directories(D:/VulkanSDK/tinyobjloader-1.0.6)
    # 库目录
    link_directories(D:/vulkanSDK/1.3.216.0/Lib)
    link_directories("C:/Program Files (x86)/GLFW/lib")


    include_directories(/usr/local/Cellar/glfw/3.3.7/include)
    include_directories(/usr/local/Cellar/glm/0.9.9.8/include)
    include_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/include)

    # 库目录
    link_directories(/usr/local/Cellar/glfw/3.3.7/lib)
    link_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/lib)
    set(LIB_VULKAN glfw3 vulkan-1)
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for IBM AIX")
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()