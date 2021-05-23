#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "specification.h"
#include "agreement_manager.h"
#include "console_manager.h"
#include "var.h"



// Static class
class SpecificationManager {

    public:
        SpecificationManager() = delete;

        static Specification         fetchAgreementSpecification(const unsigned long long);
        static Specification::Supply createSupply();
        static void                  changeStatus(Specification::Supply&);

    private:
        static Specification::Supply parseStringToSupply(const char[]);

};
