//
// Created by 王海明 on 2022/6/27.
//

#ifndef XEST_VULKAN_COMMFUNC_H
#define XEST_VULKAN_COMMFUNC_H

#include "XestHeader.h"


void check(VkResult result, const char *msg);

VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                             VkDebugUtilsMessageTypeFlagsEXT messageType,
                                             const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                                             void *pUserData);

#endif //XEST_VULKAN_COMMFUNC_H
