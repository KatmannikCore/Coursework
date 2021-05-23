#include "specification.h"



std::string Specification::Supply::statusToString() {

    switch (status) {
        case SupplyStatus::AWAITING:
            return "Ожидается";
        case SupplyStatus::DELAYED:
            return "Задерживается";
        case SupplyStatus::DELIVERED:
            return "Получено";
        case SupplyStatus::CANCELLED:
            return "Отменено";
        default:
            break;
    }
}



void Specification::Supply::statusFromString(const char string[]) {

    if (std::strcmp("Ожидается", string) == 0) {
        status = SupplyStatus::AWAITING;
    }
    else if (std::strcmp("Задерживается", string) == 0) {
        status = SupplyStatus::DELAYED;
    }
    else if (std::strcmp("Получено", string) == 0) {
        status = SupplyStatus::DELIVERED;
    }
    else if (std::strcmp("Отменено", string) == 0) {
        status = SupplyStatus::CANCELLED;
    }
    else {
        status = SupplyStatus::UNDEFINED;
    }
}



long long Specification::getId() const {

    return mId;
}



std::vector<struct Specification::Supply>& Specification::getSuppliesList() const {

    return mSuppliesList;
}



void Specification::setId(const unsigned long long id) {

    mId = id;
}



void Specification::appendSupply(const Supply& supply) {

    mSuppliesList.push_back(supply);
}



std::string Specification::toString() const {

    std::ostringstream ss;

    for (struct Supply sup : mSuppliesList) {

        ss << sup.material << "|"
           << sup.amount << "|"
           << sup.measureUnit << "|"
           << mktime(&sup.arrivalDate) << "|"
           << sup.statusToString()
           << std::endl;
    }

    return ss.str();
}
