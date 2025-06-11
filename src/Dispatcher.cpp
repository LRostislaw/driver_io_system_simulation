#include "Dispatcher.h"

Dispatcher::Dispatcher() : nextRequestId(1) {
    std::srand(std::time(nullptr));
}

int Dispatcher::simulateOperationInterval() {
    // интервал до следующей операции (например, от 1 до 3 секунд)
    return std::rand() % 3 + 1;
}

void Dispatcher::generateRequest() {
    IORequest* request = new IORequest(nextRequestId++);
    std::cout << "[Диспетчер] Появилась новая операция IO с ID: " << request->id << "\n";
    driver.addRequest(request);
}

void Dispatcher::run() {
    while (true) {
        // моделируем появление операции ввода-вывода
        generateRequest();

        // моделируем интервал до следующей операции
        int waitTime = simulateOperationInterval();
        std::cout << "[Диспетчер] Ожидание " << waitTime << " секунд до следующей операции.\n";
        std::this_thread::sleep_for(std::chrono::seconds(waitTime));

        // если драйвер обрабатывает текущий запрос
        if (driver.hasPendingRequests()) {
            driver.handleInterrupt();
        }
    }
}