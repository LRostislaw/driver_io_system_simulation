#ifndef DEVICEDRIVER_H
#define DEVICEDRIVER_H

#include "IORequest.h"
#include <queue>
#include <string>

class DeviceDriver {
    std::queue<IORequest*> requestQueue;
    int deviceTime;

public:
    DeviceDriver();
    ~DeviceDriver();

    void initializeIO();
    void handleInterrupt();
    void addRequest(IORequest* request);
    bool hasPendingRequests() const;
    void printQueue() const;

private:
    IORequest* getNextRequest();
    void printDeviceStatus(const std::string& action, const std::string& details = "") const;
};

#endif