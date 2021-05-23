#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <chrono>



class Specification {

    public:

        enum class SupplyStatus : char {
            
            AWAITING,
            DELAYED,
            DELIVERED,
            CANCELLED,
            UNDEFINED

        };



        struct Supply {
            
            std::string        material;
            std::string        measureUnit;
            unsigned long long amount;

            tm arrivalDate  { 0 };

            Specification::SupplyStatus status = Specification::SupplyStatus::AWAITING;



            std::string statusToString();
            void        statusFromString(const char[]);
        };



        long long                   getId()           const;
        std::vector<struct Supply>& getSuppliesList() const;

        void setId(const unsigned long long);
        void appendSupply(const Supply&);

        std::string toString() const;

    private:
        unsigned long long mId;  // Same as an id of the agreement this specification belongs to.

        mutable std::vector<struct Supply> mSuppliesList;

};
