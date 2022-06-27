#pragma once

// c++ headers
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <limits>
#include <array>
#include <optional>
#include <set>
#include <unordered_map>

#include "predef.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include<GLFW/glfw3native.h>

#ifdef OS_WINDOWS
    #define GLFW_EXPOSE_NATIVE_WIN32
#elif defined(OS_LINUX)
    #define GLFW_EXPOSE_NATIVE_X11
#endif
//#include <GLFW/glfw3native.h>
#undef OS_WINDOWS
#define interface class
#define implement public

#define CHECK(fn) \
do{               \
    std::cout<<"check func: "<<#fn<<std::endl;\
    if(fn!=VK_SUCCESS){\
        throw std::runtime_error(std::string("function error:")+__FILE__+":"+std::to_string(__LINE__)+":"+#fn);\
    }\
}\
while(0)

extern const std::vector<const char*> validationLayers;
extern const std::vector<const char*> deviceExtensions;
#include "IApplication.h"
#include "CommFunc.h"