//
// Created by whaim on 2022/6/25.
//

#ifndef XEST_VULKAN_DEMOAPPLICATION_H
#define XEST_VULKAN_DEMOAPPLICATION_H

#include "XestHeader.h"

class DemoApplication :implement IApplication{
public:
    void run() override;

    IApplication *getInstance() override;

private:
    void initWindow() override;
    void initVulkan() override;
    void mainLoop() override;
    void cleanup() override;

    GLFWwindow* window{};

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
};


#endif //XEST_VULKAN_DEMOAPPLICATION_H
