#include "agreement_manager.h"



unsigned long long AgreementManager::msLastId = 0;



std::vector<Agreement> AgreementManager::fetchAgreements() {
    
    char                   buf[BUFFER_SIZE];
    std::ifstream          file;
    std::vector<Agreement> agreements;


    file.open(AGREEMENTS_FILEPATH, std::ios_base::in);

    if (file.is_open()) {

        while (true) {

            file.getline(buf, BUFFER_SIZE);

            if (file.eof()) {
                break;
            }

            Agreement agr = parseStringToAgreement(buf);
            agr.setSpecification(
                SpecificationManager::fetchAgreementSpecification(agr.getId())
            );

            agreements.push_back(agr);

            msLastId = agr.getId() > msLastId ? agr.getId() : msLastId;
        }

        file.close();
    }

    return agreements;
}



Agreement AgreementManager::createAgreement() {

    Agreement         agr;
    char              buf[BUFFER_SIZE];
    std::stringstream ss;
    tm                tmp {};


    ConsoleManager::printRequest("\n¬ведите название организации:");
    ConsoleManager::readString(buf, BUFFER_SIZE);
    agr.setOrganization(buf);

    ConsoleManager::printRequest("\n¬ведите дату истечени€ действи€ договора:");
    ConsoleManager::readString(buf, BUFFER_SIZE);
    ss << buf;
    ss >> std::get_time(&tmp, "%d.%m.%Y");
    agr.setExpirationDate(tmp);


    agr.setId(++msLastId);

    agr.setRegistrationDate(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count()
    );

    return agr;
}



void AgreementManager::changeOrganiztion(Agreement& agreement) {

    ConsoleManager::printRequest("\n¬ведите новое название:");

    char buf[BUFFER_SIZE];

    ConsoleManager::readString(buf, BUFFER_SIZE);

    agreement.setOrganization(std::string(buf));
}



void AgreementManager::changeExpirationDate(Agreement& agreement) {

    ConsoleManager::printRequest("\n¬ведите новую дату:");

    char              buf[BUFFER_SIZE];
    std::stringstream ss;
    tm                tmp {};

    ConsoleManager::readString(buf, BUFFER_SIZE);
    ss << buf;
    ss >> std::get_time(&tmp, "%d.%m.%Y");
    agreement.setExpirationDate(tmp);
}



std::vector<unsigned long long>
AgreementManager::findPositionsById(const std::vector<Agreement>& vector, const unsigned long long id) {

    std::vector<unsigned long long> indexes;
    for (long long i = 0; i < vector.size(); i++) {

        if (vector[i].getId() == id) {
            indexes.push_back(i);
        }
    }

    return indexes;
}



std::vector<unsigned long long>
AgreementManager::findPositionsByOrganization(const std::vector<Agreement>& vector, const char org[]) {

    std::vector<unsigned long long> indexes;
    for (long long i = 0; i < vector.size(); i++) {

        int result = vector[i].getOrganization().find(org);
        if (result != -1) {
            indexes.push_back(i);
        }
    }

    return indexes;
}



Agreement AgreementManager::parseStringToAgreement(const char string[]) {

    Agreement   obj;
    std::string src(string);

    int start = 0;
    int end   = src.find(DEFAULT_DELIM);
    obj.setId(
        std::stoll(src.substr(start, end - start))
    );
    
    start = ++end;
    end   = src.find(DEFAULT_DELIM, end);
    obj.setOrganization(
        src.substr(start, end - start).c_str()
    );
    
    start = ++end;
    end   = src.find(DEFAULT_DELIM, end);
    obj.setRegistrationDate(
        std::stoll(src.substr(start, end - start))
    );
    
    start = ++end;
    end   = src.size();
    obj.setExpirationDate(
        std::stoll(src.substr(start, end - start))
    );
 
    return obj;
}
