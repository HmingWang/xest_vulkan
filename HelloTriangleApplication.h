//
// Created by 王海明 on 2022/6/23.
//

#ifndef XEST_VULKAN_HELLOTRIANGLEAPPLICATION_H
#define XEST_VULKAN_HELLOTRIANGLEAPPLICATION_H

#include <vector>
#include <optional>
#include "XestDefine.h"
#include "IApplication.h"

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value()&&presentFamily.has_value();
    }
};

struct SwapChainSupportDetails{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                      VkAllocationCallbacks *pAllocator, VkDebugUtilsMessengerEXT *pDebugMessenger);

void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
                                   const VkAllocationCallbacks *pAllocator);

class HelloTriangleApplication : implements IApplication {
    GLFWwindow *window{};
    VkInstance instance{};
    VkDebugUtilsMessengerEXT debugUtilsMessenger{};
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkPhysicalDeviceFeatures deviceFeatures{};
    VkPhysicalDeviceProperties deviceProperties{};
    VkDevice device{};
    VkQueue graphicsQueue{};
    VkSurfaceKHR surface{};
    VkQueue presentQueue{};
    VkSwapchainKHR swapChain{};
    std::vector<VkImage> swapChainImages{};
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews{};
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
    VKAPI_CALL
    debugCallBack(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType,
                  const VkDebugUtilsMessengerCallbackDataEXT *pCallBack, void *pUserData);

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);

    void pickPhysicalDevice();

    bool isDeviceSuitable(VkPhysicalDevice device);

    int rateDeviceSuitability(VkPhysicalDevice device);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    void createLogicalDevice();

    void createSurface();

    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapChainSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapChainPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    void createSwapChain();

    void createImageView();

    void createGraphicsPipline();
};


#endif //XEST_VULKAN_HELLOTRIANGLEAPPLICATION_H
