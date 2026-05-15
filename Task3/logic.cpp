#include "logic.h"
#include <iostream>

// Функция 6 (верхняя) - выбрасывает double
void f6() {
    int calc = 5 * 5;
    std::cout << "[f6] Начало. Простое действие: 5 * 5 = " << calc << std::endl;
    std::cout << "[f6] Генерируем исключение типа double..." << std::endl;
    
    throw 3.14159; // Выброс исключения
    
    std::cout << "[f6] Конец (не будет достигнуто)." << std::endl;
}

// Функция 5
void f5() {
    std::cout << "[f5] Начало." << std::endl;
    f6();
    std::cout << "[f5] Конец (не будет достигнуто)." << std::endl;
}

// Функция 4 (четвертая снизу) - ловит int
void f4() {
    std::cout << "[f4] Начало. Подготовка к блоку try." << std::endl;
    try {
        f5();
    } catch (int e) {
        std::cout << "[f4] Перехвачено исключение типа int: " << e << std::endl;
    }
    // Выполнится, если исключение не возникло или было перехвачено здесь (в нашем случае мы пропустим double дальше)
    std::cout << "[f4] Конец." << std::endl; 
}

// Функция 3 (третья снизу) - ловит int и double
void f3() {
    std::cout << "[f3] Начало. Подготовка к блоку try." << std::endl;
    try {
        f4();
    } catch (int e) {
        std::cout << "[f3] Перехвачено исключение типа int: " << e << std::endl;
    } catch (double e) {
        std::cout << "[f3] Перехвачено исключение типа double: " << e << std::endl;
    }
    std::cout << "[f3] Конец. Восстановление нормального потока выполнения." << std::endl;
}

// Функция 2 (вторая снизу)
void f2() {
    int calc = 100 / 2;
    std::cout << "[f2] Начало. Простое действие: 100 / 2 = " << calc << std::endl;
    f3();
    std::cout << "[f2] Конец." << std::endl;
}