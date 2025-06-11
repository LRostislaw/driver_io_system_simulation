#include <iostream>
#include <iomanip>

class IORequest {
public:
    int id;
    IORequest(int id) : id(id) {}

    void print() const {
        std::cout << "│  ├── Запрос IO [" << std::setw(2) << id << "]\n";
    }
};