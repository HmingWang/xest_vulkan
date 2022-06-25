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
    glfwMakeContextCurrent(window);

}

void DemoApplication::initVulkan() {

}

void DemoApplication::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glfwf
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void DemoApplication::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
