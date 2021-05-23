#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <time.h>

#ifdef _WIN32
    #include <Windows.h>
#endif

#include "agreement.h"
#include "var.h"



// Static class
class ConsoleManager {
    
    public:
        ConsoleManager() = delete;

        static void clearScreen();
        static void printRequest(const char[]);
        static void printMessage(const char[]);

        static int resolveYesNoChoice(const char[]);

        static void redrawMainMenu();
        static void redrawAgreementsMenu(const std::vector<Agreement>&);
        static void redrawAgreementPreviewMenu(const Agreement&);
        static void redrawAgreementEditingMenu();
        static void redrawAgreementSearchMenu();
        static void redrawAgreementSearchResultsMenu(const std::vector<Agreement>&, const std::vector<unsigned long long>&);
        static void redrawSpecificationEditingMenu(const Specification&);
        static void redrawSpecificationStatusEditingMenu();

        static void readString(char*, const unsigned short = BUFFER_SIZE);
        static int  readInt();

    private:
        static std::string convertDateToString(const tm&);

};
