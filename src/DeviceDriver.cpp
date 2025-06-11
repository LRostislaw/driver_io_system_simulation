#include "DeviceDriver.h"
#include <cstdlib>
#include <ctime>

// Конструктор
DeviceDriver::DeviceDriver() : deviceTime(0) {
    std::srand(std::time(nullptr));
}

// Деструктор
DeviceDriver::~DeviceDriver() {
    while (!requestQueue.empty()) {
        delete requestQueue.front();
        requestQueue.pop();
    }
}

// Инициализация устройства
void DeviceDriver::initializeIO() {
    deviceTime = std::rand() % 5 + 1; // 1-5
    printDeviceStatus("Инициализация устройства", 
                      "Время работы: " + std::to_string(deviceTime) + " единиц");
}

// Обработка прерывания (завершение операции)
void DeviceDriver::handleInterrupt() {
    if (requestQueue.empty()) {
        printDeviceStatus("Нет запросов для обработки");
        return;
    }
    IORequest* request = getNextRequest();
    printDeviceStatus("Завершение операции", "ID: " + std::to_string(request->id));
    delete request;

    if (!requestQueue.empty()) {
        initializeIO();
    } else {
        printDeviceStatus("Очередь запросов пуста");
    }
}

// Добавление запроса
void DeviceDriver::addRequest(IORequest* request) {
    bool wasEmpty = requestQueue.empty();
    requestQueue.push(request);
    printDeviceStatus("Добавлен запрос", "ID: " + std::to_string(request->id));
    if (wasEmpty) {
        initializeIO();
    }
}

// Проверка наличия запросов
bool DeviceDriver::hasPendingRequests() const {
    return !requestQueue.empty();
}

// Вывод очереди запросов
void DeviceDriver::printQueue() const {
    std::cout << "┌───────────────────────┐\n";
    std::cout << "│  Очередь запросов:    │\n";

    if (requestQueue.empty()) {
        std::cout << "│  └── (пусто)          │\n";
    } else {
        std::queue<IORequest*> temp = requestQueue;
        while (!temp.empty()) {
            temp.front()->print();
            temp.pop();
        }
    }
    std::cout << "└───────────────────────┘\n";
}

// Внутренний вывод статуса устройства
void DeviceDriver::printDeviceStatus(const std::string& action, const std::string& details) const {
    std::cout << "\n╭── Драйвер устройства ──\n";
    std::cout << "│  " << std::left << std::setw(18) << action;
    if (!details.empty()) {
        std::cout << ": " << details;
    }
    std::cout << "\n╰────────────────────────\n";
    printQueue();
}

// Получить следующий запрос из очереди
IORequest* DeviceDriver::getNextRequest() {
    if (requestQueue.empty()) return nullptr;
    IORequest* request = requestQueue.front();
    requestQueue.pop();
    return request;
}