#include "driver.hpp"
#include "dispatcher.hpp"
#include <thread>
#include <random>
#include <chrono>

void simulateIOSystem(int numOperations) {
    DeviceDriver driver;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> intervalDist(1, 5);
    
    for (int i = 0; i < numOperations; ++i) {
        IODispatcher::createRequest(&driver);
        
        if (!driver.requestQueue.empty()) {
            int waitTime = intervalDist(gen);
            std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
            
            driver.interruptHandler(&driver);
            IODispatcher::completeIO(&driver);
        }
    }
}

int main() {
    simulateIOSystem(5);
    return 0;
}

//g++ -o main.cpp driver.cpp dispetcher.cpp