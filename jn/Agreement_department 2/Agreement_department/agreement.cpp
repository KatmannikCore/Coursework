#include "agreement.h"



long long Agreement::getId() const {

    return mId;
}



std::string Agreement::getOrganization() const {

    return mOrganization;
}



Specification& Agreement::getSpecification() const {

    return mSpecification;
}



tm Agreement::getRegistrationDate() const {

    return mRegistrationDate;
}



tm Agreement::getExpirationDate() const {

    return mExpirationDate;
}



void Agreement::setId(const unsigned long long id) {

    mId = id;
}



void Agreement::setOrganization(const std::string orgName) {

    mOrganization = orgName.size() == 0 ? "UNKNOWN" : orgName;
}



void Agreement::setSpecification(Specification spec) {

    mSpecification = spec;
}



void Agreement::setRegistrationDate(const long long timeSinceEpoch) {

    gmtime_s(&mRegistrationDate, &timeSinceEpoch);
}



void Agreement::setExpirationDate(const long long timeSinceEpoch) {

    gmtime_s(&mExpirationDate, &timeSinceEpoch);
}



void Agreement::setExpirationDate(const tm& date) {

    mExpirationDate = date;
}



std::string Agreement::toString() const {

    std::ostringstream ss;
    ss << mId << "|"
       << mOrganization << "|"
       << mktime(&mRegistrationDate) << "|"
       << mktime(&mExpirationDate);

    return ss.str();
}
