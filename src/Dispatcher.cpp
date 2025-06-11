#include "Dispatcher.h"
#include <iostream>
#include <iomanip>

Dispatcher::Dispatcher() : nextRequestId(1) {
    std::srand(std::time(nullptr));
    printWelcome();
}

void Dispatcher::run(int maxRequests) {
    while (nextRequestId <= maxRequests) {
        if (std::rand() % 3 == 0) {
            int burst = getRandomInterval(1, 3);
            for (int i = 0; i < burst && nextRequestId <= maxRequests; i++) {
                generateRequest();
            }
        } else {
            generateRequest();
        }

        int waitTime = getRandomInterval(1, 2);
        printWaitTime(waitTime);
        std::this_thread::sleep_for(std::chrono::seconds(waitTime));

        if (driver.hasPendingRequests()) {
            driver.handleInterrupt();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    // Обработка оставшихся запросов
    while (driver.hasPendingRequests()) {
        driver.handleInterrupt();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    printCompletion();
}

// Создать новый запрос
void Dispatcher::generateRequest() {
    IORequest* request = new IORequest(nextRequestId);
    printNewRequest(nextRequestId);
    driver.addRequest(request);
    nextRequestId++;
}

// Получить случайный интервал
int Dispatcher::getRandomInterval(int min, int max) {
    return std::rand() % (max - min + 1) + min;
}

void Dispatcher::printWelcome() const {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║  Система управления вводом-выводом  ║\n";
    std::cout << "╚══════════════════════════════════════╝\n\n";
}

// Новый запрос
void Dispatcher::printNewRequest(int id) const {
    std::cout << "\n╭── Диспетчер ────────────\n";
    std::cout << "│  Новая операция IO [" << std::setw(2) << id << "]\n";
    std::cout << "╰────────────────────────\n";
}

// Ожидание
void Dispatcher::printWaitTime(int seconds) const {
    std::cout << "\n╭── Диспетчер ────────────\n";
    std::cout << "│  Ожидание " << seconds << " сек. до след. операции\n";
    std::cout << "╰────────────────────────\n";

    std::cout << "    ";
    for (int i = 0; i < seconds; i++) {
        std::cout << "• ";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\n";
}

// Завершение моделирования
void Dispatcher::printCompletion() const {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║  Все операции завершены успешно!    ║\n";
    std::cout << "╚══════════════════════════════════════╝\n\n";
}