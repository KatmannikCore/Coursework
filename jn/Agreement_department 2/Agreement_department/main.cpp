#include "department_manager.h"



int main(int argc, char argv[]) {

    setlocale(LC_ALL, "ru-RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    return DepartmentManager().startManagerLoop();
}
