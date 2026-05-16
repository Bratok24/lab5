#include <iostream>
#include "logic.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);  
    SetConsoleCP(CP_UTF8);        
    #endif
    
    std::cout << "[main] Запуск программы." << std::endl;
    f2();
    std::cout << "[main] Программа успешно завершена." << std::endl;
    return 0;
}
