//
// Created by whaim on 2022/6/25.
//

#include "DemoApplication.h"

void DemoApplication::run() {
    initWindow();
    mainLoop();
    cleanup();
}

void DemoApplication::initWindow() {
    glfwInit();
    window=glfwCreateWindow(800,600,"vulkan demo", nullptr, nullptr);
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
}

void DemoApplication::initVulkan() {

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
    DeleteObject(hBmp);
    DeleteDC(hMem);
    ReleaseDC(hWnd,hDC);
    glfwDestroyWindow(window);
    glfwTerminate();
}

void DemoApplication::render() {
    ((int*)pBuffer)[rand()%(800*600)]=0xF000;


    BitBlt(hDC,0,0,800,600,hMem,0,0,SRCCOPY);
}
