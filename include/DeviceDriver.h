#ifndef DEVICEDRIVER_H
#define DEVICEDRIVER_H

#include "IORequest.h"
#include <queue>
#include <cstdlib>
#include <ctime>

class DeviceDriver {
public:
    using RequestQueue = std::queue<IORequest*>;

    DeviceDriver();
    ~DeviceDriver();

    void initializeIO(); // инициализация ввода-вывода
    void handleInterrupt(); // обработка прерывания
    void addRequest(IORequest* request); // добавление запроса в очередь
    bool hasPendingRequests() const; // есть ли запросы
    IORequest* getNextRequest(); // получить следующий запрос

private:
    RequestQueue requestQueue;
    int deviceTime; // случайное время работы устройства
    int requestCount; // счетчик запросов
};

#endif // DEVICEDRIVER_H