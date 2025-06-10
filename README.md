# Симулятор системы ввода-вывода

## Установка зависимостей на Arch Linux
```bash
sudo pacman -S base-devel cmake gcc

# Клонирование (если нужно)
git clone https://ваш_репозиторий.git
cd io_system_simulation

# Сборка
mkdir build && cd build
cmake ..
make

# Запуск
./io_simulation

# Клонирование репозитория
git clone https://github.com/ваш-репозиторий/io_system_simulation.git
cd io_system_simulation

# Создание директории сборки
mkdir build && cd build
cmake ..
make

# Запуск программы
./io_simulation