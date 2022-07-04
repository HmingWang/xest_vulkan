//
// Created by whaim on 2022/6/25.
//

#ifndef XEST_VULKAN_DEMOAPPLICATION_H
#define XEST_VULKAN_DEMOAPPLICATION_H

#include "XestHeader.h"




class DemoApplication :implement IApplication{
public:
    void run() override;

private:
    void initWindow() override;
    void initVulkan() override;
    void mainLoop() override;
    void cleanup() override;

private:

    GLFWwindow* window;
    VkInstance instance;
    VkSurfaceKHR surface;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice;
    std::vector<VkPhysicalDevice> physicalDeviceList;
    VkDevice device;


private:
    std::vector<VkQueueFamilyProperties> queueFamilies;
    VkQueue queue;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;


    void render();

    VkFormat
    findSupportedFormat(const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

    VkFormat findDepthFormat();
};


#endif //XEST_VULKAN_DEMOAPPLICATION_H
