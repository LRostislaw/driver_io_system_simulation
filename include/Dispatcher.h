#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "IORequest.h"
#include "DeviceDriver.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

class Dispatcher {
public:
    Dispatcher();
    void run(); // моделирование работы диспетчера

private:
    DeviceDriver driver;
    int nextRequestId;
    int simulateOperationInterval(); // возвращает случайный интервал до следующей операции
    void generateRequest(); // создание нового запроса
};
#endif // DISPATCHER_H