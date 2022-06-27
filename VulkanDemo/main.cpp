#include "XestHeader.h"
#include "DemoApplication.h"


const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME,
};

int main() {
    try {
        DemoApplication app;
        app.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}