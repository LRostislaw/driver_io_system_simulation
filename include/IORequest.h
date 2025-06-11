#ifndef IOREQUEST_H
#define IOREQUEST_H

#include <iostream>
#include <string>

class IORequest {
public:
    int id; // идентификатор операции
    IORequest(int id) : id(id) {}
    void print() const {
        std::cout << "Запрос IO ID: " << id << std::endl;
    }
};

#endif // IOREQUEST_H