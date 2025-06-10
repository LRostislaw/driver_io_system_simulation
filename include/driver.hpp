#pragma once
#include <queue>

struct IORequest {
    int id;
    int duration;
};

class DeviceDriver {
public:
    void (*initializeIO)(DeviceDriver*);
    void (*interruptHandler)(DeviceDriver*);

    std::queue<IORequest> requestQueue;
    int currentOperationTime;

    DeviceDriver();
    
    static void initIO(DeviceDriver* driver);
    static void handleInterrupt(DeviceDriver* driver);
};