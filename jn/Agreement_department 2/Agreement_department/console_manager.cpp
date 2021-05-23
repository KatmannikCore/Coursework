#include "console_manager.h"



void ConsoleManager::clearScreen() {

    #ifdef _WIN32

    COORD c00 { 0, 0 };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    DWORD tmp;
    FillConsoleOutputCharacter(
        hConsole,
        ' ',
        csbi.dwSize.X * csbi.dwSize.Y,
        c00,
        &tmp
    );

    SetConsoleCursorPosition(hConsole, c00);

    #else

    for (int i = 0; i < 30; i++) {
        std::cout << "\n";
    }

    #endif
}



void ConsoleManager::printRequest(const char string[]) {

    std::cout << string << "\n\n> ";
}



void ConsoleManager::printMessage(const char string[]) {

    std::cout << string;
}



int ConsoleManager::resolveYesNoChoice(const char label[]) {

    std::cout << "\n" << label
              << "\n1) Да"
              << "\n2) Нет"
              << "\n\n> ";

    return readInt();
}



void ConsoleManager::redrawMainMenu() {

    clearScreen();

    std::cout << DEFAULT_SCREEN_HEADER
              << "Главное меню:\n\n"
              << "1) Создать договор;\n"
              << "2) Список всех договоров;\n"
              << "3) Найти договор\n"
              << "4) Выход.\n\n"
              << "> ";
}



void ConsoleManager::redrawAgreementsMenu(const std::vector<Agreement>& agreements) {

    clearScreen();

    std::cout << DEFAULT_SCREEN_HEADER
              << "Список заключённых договоров:\n\n"
              << "0) Вернуться в главное меню;\n";

    for (int i = 0; i < agreements.size(); i++) {

        std::cout << i + 1 << ") "
                  << agreements[i].getOrganization()
                  << " (номер: "
                  << agreements[i].getId()
                  << ");\n";
    }

    std::cout << "\n> ";
}



void ConsoleManager::redrawAgreementPreviewMenu(const Agreement& agreement) {

    clearScreen();

    std::cout << DEFAULT_SCREEN_HEADER
              << "Информация по договору:\n"
              << "\tНомер договора: " << agreement.getId() << std::endl
              << "\tОрганизация, с которой заключён договор: " << agreement.getOrganization() << std::endl
              << "\tДата регистрации: " << convertDateToString(agreement.getRegistrationDate()) << std::endl
              << "\tДействителен по: " << convertDateToString(agreement.getExpirationDate()) << std::endl
              << std::endl;

    Specification const* spec = &agreement.getSpecification();

    std::cout << "Спецификация к договору " << spec->getId() << ":\n";

    long long i = 1;
    for (Specification::Supply sup : spec->getSuppliesList()) {

        std::cout << "\t" << i << ") Материал: "
                  << sup.material << std::endl
                  << "\t   Размерность: "
                  << sup.amount << " " << sup.measureUnit << std::endl
                  << "\t   Дата поставки: "
                  << convertDateToString(sup.arrivalDate) << std::endl
                  << "\t   Текущий статус: " << sup.statusToString() << std::endl;

        i++;
    }

    std::cout << "\n0) Назад;\n"
              << "1) Редакировать договор\n"
              << "2) Удалить запись\n"
              << "\n> ";
}



void ConsoleManager::redrawAgreementEditingMenu() {

    std::cout << "\n0) Отмена;"
              << "\n1) Изменить название предприятия;"
              << "\n2) Изменить дату истечения действия договора;"
              << "\n3) Изменить статус заказа."
              << "\n\n> ";
}



void ConsoleManager::redrawAgreementSearchMenu() {

    clearScreen();

    std::cout << "Меню поиска"
              << "\n0) Назад;"
              << "\n1) Найти по номеру;"
              << "\n2) Найти по имени;"
              << "\n\n> ";
}



void ConsoleManager::redrawAgreementSearchResultsMenu(const std::vector<Agreement>& vector,
                                                      const std::vector<unsigned long long>& indexes) {

    std::cout << "\nРезультаты поиска:"
              << "\n0) Назад;";

    for (long long i = 0; i < indexes.size(); i++) {
        std::cout << "\n" << i + 1 << ") "
                  << vector[indexes[i]].getOrganization() << " ("
                  << vector[indexes[i]].getId() << ");";
    }

    std::cout << "\n\n> ";
}



void ConsoleManager::redrawSpecificationEditingMenu(const Specification& spec) {

    std::cout << "\nВыберите заказ:" << std::endl;

    long long i = 1;
    for (Specification::Supply sup : spec.getSuppliesList()) {

        std::cout << i << ") "
                  << sup.material << " ("
                  << sup.amount << " "
                  << sup.measureUnit << ");"
                  << std::endl;
        i++;
    }

    std::cout << "\n\n> ";
}



void ConsoleManager::redrawSpecificationStatusEditingMenu() {

    std::cout << "\nНовый статус:"
              << "\n1) Ожидается;"
              << "\n2) Задерживается;"
              << "\n3) Получено;"
              << "\n4) Отменено."
              << "\n\n> ";              
}



void ConsoleManager::readString(char* buffer, const unsigned short size) {

    std::cin.getline(buffer, size);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(LLONG_MAX, '\n');
    }
}



int ConsoleManager::readInt() {

    char buf[BUFFER_SIZE];
    int  value;

    ConsoleManager::readString(buf, BUFFER_SIZE);

    try {
        value = std::stoi(buf);

        return value;
    }
    // std::invalid_argument, std::out_of_range
    catch (...) {
        return -1;
    }
}



std::string ConsoleManager::convertDateToString(const tm& timeStruct) {

    std::ostringstream ss;

    ss << (timeStruct.tm_mday / 10 == 0 ? "0" : "")
       << timeStruct.tm_mday
       << "."
       << ((timeStruct.tm_mon + 1) / 10 == 0 ? "0" : "")
       << timeStruct.tm_mon + 1
       << "."
       << 1900 + timeStruct.tm_year;

    return ss.str();
}
