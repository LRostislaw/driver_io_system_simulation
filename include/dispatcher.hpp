#pragma once
#include "driver.hpp"

class IODispatcher {
public:
    static int nextRequestId;
    
    static void completeIO(DeviceDriver* driver);
    static void createRequest(DeviceDriver* driver);
};