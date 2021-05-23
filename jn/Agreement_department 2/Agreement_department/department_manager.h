#pragma once

#include <fstream>
#include <sstream>

#include "console_manager.h"
#include "agreement_manager.h"
#include "specification_manager.h"
#include "agreement.h"



class DepartmentManager {

    public:

        enum class ManagerState : char {
            
            MAIN,
            SHOW_AGR_LIST,
            SHOW_AGR_PARTICULAR,
            CREATE_AGR,
            DELETE_AGR,
            EDIT_AGR,
            FIND_AGR,
            EDIT_SPEC,
            TERMINATE

        };



        DepartmentManager();
        ~DepartmentManager();
        
        int startManagerLoop();

    private:
        ManagerState mManagerState;

        std::vector<Agreement> mAgreementsList;


        int resolveMainMenuChoice();
        int resolveAgreementsMenuChoice();
        int resolveAgreementPreviewMenuChoice(int);
        int resolveAgreementSearchResultsMenuChoice();

        int resolveAgreementCreation();
        int resolveAgreementRemoval(int);
        int resolveAgreementEditing(int);
        int resolveAgreementSearch();
        int resolveSpecificationEditing(int);
};
