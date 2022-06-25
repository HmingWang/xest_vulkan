//
// Created by whaim on 2022/6/25.
//

#include "HelloTriangleApplication.h"

void HelloTriangleApplication::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}


void HelloTriangleApplication::initVulkan() {
    createInstance();
    setupDebugMessenger();
    createSurface();
    pickPhysicalDevice();
    createLogicalDevice();
    createSwapChain();
    createImageViews();
    createRenderPass();
    createDescriptorSetLayout();
    createGraphicsPipeline();
    createCommandPool();
    createColorResources();
    createDepthResources();
    createFramebuffers();
    createTextureImage();
    createTextureImageView();
    createTextureSampler();
    loadModel();
    createVertexBuffer();
    createIndexBuffer();
    createUniformBuffers();
    createDescriptorPool();
    createDescriptorSets();
    createCommandBuffers();
    createSyncObjects();
}

void HelloTriangleApplication::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        drawFrame();
    }

    vkDeviceWaitIdle(device);
}

void HelloTriangleApplication::cleanup() {

}

void HelloTriangleApplication::run() {

    initWindow();
    initVulkan();
    mainLoop();
    cleanup();

}

void HelloTriangleApplication::framebufferResizeCallback(GLFWwindow *window, int width, int height) {
    auto app = reinterpret_cast<HelloTriangleApplication *>(glfwGetWindowUserPointer(window));
    app->framebufferResized = true;
}
