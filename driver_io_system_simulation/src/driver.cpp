#include "driver.hpp"
#include <iostream>
#include <random>

DeviceDriver::DeviceDriver() {
    initializeIO = &DeviceDriver::initIO;
    interruptHandler = &DeviceDriver::handleInterrupt;
    currentOperationTime = 0;
}

void DeviceDriver::initIO(DeviceDriver* driver) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);
    
    driver->currentOperationTime = dist(gen);
    std::cout << "IO operation initialized. Duration: " 
              << driver->currentOperationTime << " ms\n";
}

void DeviceDriver::handleInterrupt(DeviceDriver* driver) {
    std::cout << "Processing IO interrupt\n";
}