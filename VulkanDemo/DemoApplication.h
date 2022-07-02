//
// Created by whaim on 2022/6/25.
//

#ifndef XEST_VULKAN_DEMOAPPLICATION_H
#define XEST_VULKAN_DEMOAPPLICATION_H

#include "XestHeader.h"

struct Vertex {
    glm::vec3 pos;
    glm::vec3 color;
    glm::vec2 texCoord;
};

const int MAX_FRAMES_IN_FLIGHT = 2;

class DemoApplication :implement IApplication{
public:
    void run() override;

    IApplication *getInstance() override;

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
    std::vector<VkQueueFamilyProperties> queueFamilies;
    VkQueue queue;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkImage colorImage;
    VkDeviceMemory colorImageMemory;
    VkImageView colorImageView;

    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
    VkCommandPool commandPool;
    VkDescriptorPool descriptorPool;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;

#ifdef OS_WINDOWS
    HWND hWnd{};
    HDC hDC{};
    HDC hMem{};
    void* pBuffer{};
    HBITMAP hBmp{};
#elifdef OS_LINUX
    Window x11window{};
#endif

    void render();

    VkFormat
    findSupportedFormat(const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

    VkFormat findDepthFormat();

    VkShaderModule createShaderModule(const std::vector<char> &code);

    void drawFrame();
};


#endif //XEST_VULKAN_DEMOAPPLICATION_H
