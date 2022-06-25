#pragma once

#include "XestHeader.h"

interface IApplication{
public:
    virtual void run()=0;
private:
    virtual void initWindow()=0;
    virtual void initVulkan()=0;
    virtual void mainLoop()=0;
    virtual void cleanup()=0;
};