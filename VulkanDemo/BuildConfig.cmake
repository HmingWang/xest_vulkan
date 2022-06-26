message(STATUS "custom find vulkan")

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")

    find_package(Vulkan)
    set(LIB_VULKAN vulkan X11)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")

    # ����Ŀ¼
    include_directories(/usr/local/Cellar/glfw/3.3.7/include)
    include_directories(/usr/local/Cellar/glm/0.9.9.8/include)
    include_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/include)

    # ��Ŀ¼
    link_directories(/usr/local/Cellar/glfw/3.3.7/lib)
    link_directories(/Users/whaim/VulkanSDK/1.3.216.0/macOS/lib)

elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")

    # ����Ŀ¼
    include_directories(D:/VulkanSDK/1.3.216.0/Include)
    include_directories("C:/Program Files (x86)/GLFW/include")
    include_directories(D:/VulkanSDK/glm-0.9.9.8/glm)
    include_directories(D:/VulkanSDK/tinyobjloader-1.0.6)
    # ��Ŀ¼
    link_directories(D:/vulkanSDK/1.3.216.0/Lib)
    link_directories("C:/Program Files (x86)/GLFW/lib")
    set(LIB_VULKAN vulkan-1)

elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for IBM AIX")
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()