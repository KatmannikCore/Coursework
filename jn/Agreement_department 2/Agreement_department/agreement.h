#pragma once

#include <string>
#include <sstream>
#include <time.h>

#include "specification.h"



class Agreement {

    public:
        long long      getId()               const;
        std::string    getOrganization()     const;
        Specification& getSpecification()    const;
        tm             getRegistrationDate() const;
        tm             getExpirationDate()   const;

        void setId(const unsigned long long);
        void setOrganization(const std::string);
        void setSpecification(Specification);
        void setRegistrationDate(const long long);
        void setExpirationDate(const long long);
        void setExpirationDate(const tm&);

        std::string toString() const;

    private:
        unsigned long long mId;

        std::string mOrganization;

        mutable Specification mSpecification;

        mutable tm mRegistrationDate {};
        mutable tm mExpirationDate {};

};
