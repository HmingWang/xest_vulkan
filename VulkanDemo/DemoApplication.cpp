//
// Created by whaim on 2022/6/25.
//

#include "DemoApplication.h"

void DemoApplication::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void DemoApplication::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window=glfwCreateWindow(800,600,"vulkan demo", nullptr, nullptr);
#ifdef OS_WINDOWS
    hWnd=glfwGetWin32Window(window);
    hDC= GetDC(hWnd);
    hMem = CreateCompatibleDC(hDC);
    //wl_surface* surface= glfwGetWaylandWindow(window);

    BITMAPINFO bmpInfo;
    bmpInfo.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
    bmpInfo.bmiHeader.biWidth=800;
    bmpInfo.bmiHeader.biHeight=600;
    bmpInfo.bmiHeader.biPlanes=1;
    bmpInfo.bmiHeader.biBitCount=32;
    bmpInfo.bmiHeader.biCompression=BI_RGB;
    bmpInfo.bmiHeader.biSizeImage=0;
    bmpInfo.bmiHeader.biXPelsPerMeter=0;
    bmpInfo.bmiHeader.biYPelsPerMeter=0;
    bmpInfo.bmiHeader.biClrUsed=0;
    bmpInfo.bmiHeader.biClrImportant=0;

    hBmp= CreateDIBSection(hDC,&bmpInfo,DIB_RGB_COLORS,(void**)&pBuffer,0,0);
    SelectObject(hMem,hBmp);
    memset(pBuffer,0,800*600*4);
    //DeleteObject(hBmp);
#elifdef OS_LINUX
    x11window=glfwGetX11Window(window);
#endif
}

IApplication *DemoApplication::getInstance() {
    return nullptr;
}

void DemoApplication::initVulkan() {

    //1. create instance
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    //get extensions
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

    //setup debug messenger
    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
    debugCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    debugCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    debugCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    debugCreateInfo.pfnUserCallback = debugCallback;

    uint32_t layerCount=0;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    std::vector<VkLayerProperties>  props(layerCount);
    vkEnumerateInstanceLayerProperties( &layerCount,props.data());
    for(const auto& e:props){
        std::cout<<e.layerName<<std::endl;
    }

    VkInstanceCreateInfo instanceCreateInfo{};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;
    instanceCreateInfo.enabledExtensionCount = extensions.size();
    instanceCreateInfo.ppEnabledExtensionNames = extensions.data();
    instanceCreateInfo.enabledLayerCount = validationLayers.size();
    instanceCreateInfo.ppEnabledLayerNames = validationLayers.data();
    instanceCreateInfo.pNext = &debugCreateInfo;

    CHECK(vkCreateInstance(&instanceCreateInfo, nullptr, &instance));
    //2 create debug messenger
    auto pfnVkCreateDebugUtilsMessengerExt=(PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    CHECK(pfnVkCreateDebugUtilsMessengerExt(instance, &debugCreateInfo, nullptr, &debugMessenger));

    //3. get physical device
    uint32_t deviceCount = 0;
    CHECK(vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr));
    physicalDeviceList.resize(deviceCount);
    CHECK(vkEnumeratePhysicalDevices(instance, &deviceCount, physicalDeviceList.data()));
    physicalDevice=physicalDeviceList.front();

    //4. get queue families
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, nullptr);
    queueFamilies.resize(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilies.data());

    //5. create logical device
    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    VkDeviceQueueCreateInfo queueCreateInfo{};
    float queuePriority=1.0f;
    queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueCreateInfo.queueFamilyIndex = 0;
    queueCreateInfo.queueCount = 1;
    queueCreateInfo.pQueuePriorities = &queuePriority;
    queueCreateInfos.push_back(queueCreateInfo);

    VkPhysicalDeviceFeatures deviceFeatures{};
    deviceFeatures.samplerAnisotropy = VK_TRUE;

    VkDeviceCreateInfo deviceCreateInfo{};
    deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.queueCreateInfoCount = queueCreateInfos.size();
    deviceCreateInfo.pQueueCreateInfos = queueCreateInfos.data();
    deviceCreateInfo.pEnabledFeatures = &deviceFeatures;
    deviceCreateInfo.enabledExtensionCount = deviceExtensions.size();
    deviceCreateInfo.ppEnabledExtensionNames = deviceExtensions.data();
    deviceCreateInfo.enabledLayerCount = validationLayers.size();
    deviceCreateInfo.ppEnabledLayerNames = validationLayers.data();

    CHECK(vkCreateDevice(physicalDevice, &deviceCreateInfo, nullptr, &device));

    //get queue
    vkGetDeviceQueue(device, 0, 0, &queue);

    CHECK(glfwCreateWindowSurface(instance,window, nullptr,&surface));

}

void DemoApplication::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        render();
        /* Swap front and back buffers */
       // glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void DemoApplication::cleanup() {
#ifdef OS_WINDOWS
    DeleteObject(hBmp);
    DeleteDC(hMem);
    ReleaseDC(hWnd,hDC);
#endif
    glfwDestroyWindow(window);
    glfwTerminate();
}

void DemoApplication::render() {
//    ((int*)pBuffer)[rand()%(800*600)]=0xF000;
//
//
//    BitBlt(hDC,0,0,800,600,hMem,0,0,SRCCOPY);
}
