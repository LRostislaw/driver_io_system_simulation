#include "DeviceDriver.h"

DeviceDriver::DeviceDriver() : deviceTime(0), requestCount(0) {
    std::srand(std::time(nullptr));
}

DeviceDriver::~DeviceDriver() {
    while (!requestQueue.empty()) {
        delete requestQueue.front();
        requestQueue.pop();
    }
}

void DeviceDriver::initializeIO() {
    deviceTime = std::rand() % 5 + 1; // случайное время работы устройства от 1 до 5
    std::cout << "[Драйвер] Инициализация устройства. Время работы: " << deviceTime << " единиц.\n";
}

void DeviceDriver::handleInterrupt() {
    if (requestQueue.empty()) {
        std::cout << "[Драйвер] Нет запросов для обработки.\n";
        return;
    }
    IORequest* request = getNextRequest();
    std::cout << "[Драйвер] Завершение операции IO с запросом ID: " << request->id << "\n";
    delete request; // удаляем завершённый запрос
    if (!requestQueue.empty()) {
        initializeIO(); // инициируем следующую операцию
    } else {
        std::cout << "[Драйвер] Очередь запросов пуста.\n";
    }
}

void DeviceDriver::addRequest(IORequest* request) {
    bool wasEmpty = requestQueue.empty();
    requestQueue.push(request);
    std::cout << "[Драйвер] Добавлен запрос ID: " << request->id << " в очередь.\n";
    if (wasEmpty) {
        initializeIO();
    }
}

bool DeviceDriver::hasPendingRequests() const {
    return !requestQueue.empty();
}

IORequest* DeviceDriver::getNextRequest() {
    if (requestQueue.empty()) return nullptr;
    IORequest* request = requestQueue.front();
    requestQueue.pop();
    return request;
}