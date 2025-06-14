#include "DeviceDriver.h"
#include <chrono>
#include <thread>

class Dispatcher {
    DeviceDriver driver;
    int nextRequestId;

public:
    Dispatcher();
    void run(int maxRequests = 12); 

private:
    void generateRequest();
    int getRandomInterval(int min, int max);
    void printWelcome() const;
    void printNewRequest(int id) const;
    void printWaitTime(int seconds) const;
    void printCompletion() const;
};