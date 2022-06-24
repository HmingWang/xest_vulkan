//
// Created by 王海明 on 2022/6/23.
//

#ifndef XEST_VULKAN_HELLOTRIANGLEAPPLICATION_H
#define XEST_VULKAN_HELLOTRIANGLEAPPLICATION_H

#include <vector>
#include "XestDefine.h"
#include "IApplication.h"

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,VkAllocationCallbacks *pAllocator,VkDebugUtilsMessengerEXT* pDebugMessenger);
void DestroyDebugUtilsMessengerEXT(VkInstance instance,VkDebugUtilsMessengerEXT debugMessenger,const VkAllocationCallbacks *pAllocator);

class HelloTriangleApplication:implements IApplication  {
    GLFWwindow *window{};
    VkInstance instance{};
    VkDebugUtilsMessengerEXT debugUtilsMessenger{};
public:
    void run() override;
    void initWindow() override;
    void initVulkan() override;
    void mainLoop() override;
    void cleanup() override;

    void createInstance();
    void setupDebugMessenger();

    std::vector<const char *> getRequiredExtensions();

    bool checkValidationLayerSupport();

    static VKAPI_ATTR VkBool32
    VKAPI_CALL debugCallBack(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType,
                  const VkDebugUtilsMessengerCallbackDataEXT *pCallBack, void *pUserData);

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
};


#endif //XEST_VULKAN_HELLOTRIANGLEAPPLICATION_H
