//
// Created by 王海明 on 2022/6/23.
//

#ifndef XEST_VULKAN_IAPPLICATION_H
#define XEST_VULKAN_IAPPLICATION_H

#include "XestDefine.h"

interface IApplication {
public:
    virtual void run()=0;
    virtual void initWindow()=0;
    virtual void initVulkan()=0;
    virtual void mainLoop()=0;
    virtual void cleanup()=0;
};


#endif //XEST_VULKAN_IAPPLICATION_H
