//
// Created by 王海明 on 2022/6/27.
//

#include "CommFunc.h"

void check(VkResult result,const char* msg){
    if(result!=VK_SUCCESS){
        throw std::runtime_error(std::string("function error:")+__FILE__+":"+std::to_string(__LINE__)+":"+msg);
    }
    std::cout<<"check function success --- "<<msg<<""<<std::endl;

}

VkBool32 debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
}