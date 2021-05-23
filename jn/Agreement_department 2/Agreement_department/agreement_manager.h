#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>

#include "agreement.h"
#include "specification_manager.h"
#include "console_manager.h"
#include "var.h"



// Static class
class AgreementManager {

    public:
        AgreementManager() = delete;

        static std::vector<Agreement> fetchAgreements();

        static Agreement createAgreement();

        static void changeOrganiztion(Agreement&);
        static void changeExpirationDate(Agreement&);

        static std::vector<unsigned long long> findPositionsById(const std::vector<Agreement>&, const unsigned long long);
        static std::vector<unsigned long long> findPositionsByOrganization(const std::vector<Agreement>&, const char[]);

    private:
        static unsigned long long msLastId;


        static Agreement parseStringToAgreement(const char[]);

};
