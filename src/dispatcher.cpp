#include "dispatcher.hpp"
#include <iostream>
#include <random>

int IODispatcher::nextRequestId = 0;

void IODispatcher::completeIO(DeviceDriver* driver) {
    if (!driver->requestQueue.empty()) {
        IORequest completed = driver->requestQueue.front();
        driver->requestQueue.pop();
        
        std::cout << "Completed IO operation #" << completed.id 
                  << " (duration: " << completed.duration << " ms)\n";
        
        if (!driver->requestQueue.empty()) {
            driver->initializeIO(driver);
        }
    }
}

void IODispatcher::createRequest(DeviceDriver* driver) {
    IORequest newRequest;
    newRequest.id = ++nextRequestId;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);
    newRequest.duration = dist(gen);
    
    bool wasEmpty = driver->requestQueue.empty();
    driver->requestQueue.push(newRequest);
    
    std::cout << "Created new IO request #" << newRequest.id 
              << " (duration: " << newRequest.duration << " ms)\n";
    
    if (wasEmpty) {
        driver->initializeIO(driver);
    }
}