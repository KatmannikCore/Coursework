#include "specification_manager.h"



Specification SpecificationManager::fetchAgreementSpecification(const unsigned long long id) {

    std::ifstream      file;
    std::ostringstream ss;
    char               buf[BUFFER_SIZE];
    Specification      spec;


    spec.setId(id);

    ss << SPECIFICATION_FOLDER << SPECIFICATION_PREFIX << id << DEFAULT_FILE_SUFFIX;

    file.open(ss.str().c_str(), std::ios_base::in);

    if (file.is_open()) {

        while (true) {

            file.getline(buf, BUFFER_SIZE);

            if (file.eof()) {
                break;
            }

            spec.appendSupply(
                parseStringToSupply(buf)
            );
        }

        file.close();
    }
        
    return spec;
}



Specification::Supply SpecificationManager::createSupply() {

    Specification::Supply sup;
    char                  buf[BUFFER_SIZE];
    std::stringstream     ss;

    ConsoleManager::printRequest("\nМатериал:");
    ConsoleManager::readString(buf, BUFFER_SIZE);
    sup.material.append(buf);

    ConsoleManager::printRequest("\nКоличество:");
    ConsoleManager::readString(buf, BUFFER_SIZE);
    sup.amount = std::stoll(buf);
    
    ConsoleManager::printRequest("\nЕдиницы измерения (км, л, град и т. п.): ");
    ConsoleManager::readString(buf, BUFFER_SIZE);
    sup.measureUnit.append(buf);
    
    ConsoleManager::printRequest("\nДата поставки: ");
    ConsoleManager::readString(buf, BUFFER_SIZE);
    ss << buf;
    ss >> std::get_time(&sup.arrivalDate, "%d.%m.%Y");


    time_t now = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();

    if (now > std::mktime(&sup.arrivalDate)) {
        sup.status = Specification::SupplyStatus::DELAYED;
    }
    else {
        sup.status = Specification::SupplyStatus::AWAITING;
    }
    
    return sup;
}



void SpecificationManager::changeStatus(Specification::Supply& sup) {

    ConsoleManager::redrawSpecificationStatusEditingMenu();

    int choice = ConsoleManager::readInt();

    switch (choice) {
        case 1:
            sup.status = Specification::SupplyStatus::AWAITING;
            break;
        case 2:
            sup.status = Specification::SupplyStatus::DELAYED;
            break;
        case 3:
            sup.status = Specification::SupplyStatus::DELIVERED;
            break;
        case 4:
            sup.status = Specification::SupplyStatus::CANCELLED;
            break;
        default:
            break;
    }
}



Specification::Supply SpecificationManager::parseStringToSupply(const char string[]) {

    Specification::Supply sup;
    std::string           src(string);

    int start = 0;
    int end = src.find(DEFAULT_DELIM);
    sup.material = src.substr(start, end - start).c_str();

    start = ++end;
    end = src.find(DEFAULT_DELIM, end);
    sup.amount = std::stoll(src.substr(start, end - start));

    start = ++end;
    end = src.find(DEFAULT_DELIM, end);
    sup.measureUnit = src.substr(start, end - start);

    start = ++end;
    end = src.find(DEFAULT_DELIM, end);
    long long time = std::stoll(src.substr(start, end - start));
    gmtime_s(
        &(sup.arrivalDate),
        &time
    );
    
    start = ++end;
    end = src.size();
    sup.statusFromString(
        src.substr(start, end - start).c_str()
    );

    return sup;
}
