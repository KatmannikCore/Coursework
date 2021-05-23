#include "department_manager.h"



DepartmentManager::DepartmentManager() {

    mManagerState = ManagerState::MAIN;
}



DepartmentManager::~DepartmentManager() {

    std::ofstream file;

    file.open(AGREEMENTS_FILEPATH, std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        for (Agreement agr : mAgreementsList) {

            std::string out(agr.toString());
            file.write(out.c_str(), out.size());
            file.write("\n", 1);

            std::ofstream specFile;
            std::ostringstream ss;
            ss << SPECIFICATION_FOLDER << SPECIFICATION_PREFIX << agr.getId() << DEFAULT_FILE_SUFFIX;

            specFile.open(ss.str().c_str(), std::ios::out | std::ios::trunc);

            if (specFile.is_open()) {
                
                std::string out_(agr.getSpecification().toString());
                specFile.write(out_.c_str(), out_.size());

                specFile.close();
            }
        }

        file.close();
    }
}



int DepartmentManager::startManagerLoop() {

    mAgreementsList = AgreementManager::fetchAgreements();

    int exitCode = 0;

    while (true) {

        switch (mManagerState) {
            case ManagerState::MAIN:
                exitCode = resolveMainMenuChoice();
                break;
            case ManagerState::CREATE_AGR:
                exitCode = resolveAgreementCreation();
                break;
            case ManagerState::SHOW_AGR_LIST:
                exitCode = resolveAgreementsMenuChoice();
                break;
            case ManagerState::SHOW_AGR_PARTICULAR:
                exitCode = resolveAgreementPreviewMenuChoice(exitCode);
                break;
            case ManagerState::DELETE_AGR:
                exitCode = resolveAgreementRemoval(exitCode);
                break;
            case ManagerState::EDIT_AGR:
                exitCode = resolveAgreementEditing(exitCode);
                break;
            case ManagerState::FIND_AGR:
                exitCode = resolveAgreementSearch();
                break;
            case ManagerState::EDIT_SPEC:
                exitCode = resolveSpecificationEditing(exitCode);
                break;
            case ManagerState::TERMINATE:
                return 0;
            default:
                return -1;
        }
    }
}



int DepartmentManager::resolveMainMenuChoice() {

    ConsoleManager::redrawMainMenu();

    int choice = ConsoleManager::readInt();

    switch (choice) {
        case 1:
            mManagerState = ManagerState::CREATE_AGR;
            break;
        case 2:
            mManagerState = ManagerState::SHOW_AGR_LIST;
            break;
        case 3:
            mManagerState = ManagerState::FIND_AGR;
            break;
        case 4:
            mManagerState = ManagerState::TERMINATE;
            break;
        default:
            break;
    }

    return 0;
}



int DepartmentManager::resolveAgreementsMenuChoice() {

    ConsoleManager::redrawAgreementsMenu(mAgreementsList);

    int choice = ConsoleManager::readInt();

    if (choice == 0) {
        mManagerState = ManagerState::MAIN;
    }
    else if (choice > 0 && choice <= mAgreementsList.size()) {
        mManagerState = ManagerState::SHOW_AGR_PARTICULAR;
        return choice;
    }

    return 0;
}



int DepartmentManager::resolveAgreementPreviewMenuChoice(int index) {

    ConsoleManager::redrawAgreementPreviewMenu(mAgreementsList[index - 1]);

    int choice = ConsoleManager::readInt();

    switch (choice) {
        case 0:
            mManagerState = ManagerState::SHOW_AGR_LIST;
            return 0;
        case 1:
            mManagerState = ManagerState::EDIT_AGR;
            break;
        case 2:
            mManagerState = ManagerState::DELETE_AGR;
            break;
        default:
            break;
    }

    return index;
}



int DepartmentManager::resolveAgreementCreation() {

    ConsoleManager::clearScreen();

    Agreement agr = AgreementManager::createAgreement();

    Specification spec;
    spec.setId(agr.getId());

    int choice;
    while (true) {
        choice = ConsoleManager::resolveYesNoChoice("\nДобавить запись в спецификацию?");

        if (choice != 1) {
            break;
        }

        spec.appendSupply(
            SpecificationManager::createSupply()
        );
    }
    
    agr.setSpecification(spec);
    mAgreementsList.push_back(agr);

    mManagerState = ManagerState::MAIN;
    return 0;
}



int DepartmentManager::resolveAgreementRemoval(int index) {

    int choice = ConsoleManager::resolveYesNoChoice("\nВы уверены?");

    if (choice == 1) {
        mAgreementsList.erase(mAgreementsList.begin() + index - 1);
        mManagerState = ManagerState::SHOW_AGR_LIST;

        return 0;
    }
    else {
        mManagerState = ManagerState::SHOW_AGR_PARTICULAR;
        
        return index;
    }
}



int DepartmentManager::resolveAgreementEditing(int index) {
    
    ConsoleManager::redrawAgreementEditingMenu();

    int choice = ConsoleManager::readInt();

    if (choice == 1) {
        AgreementManager::changeOrganiztion(mAgreementsList[index - 1]);
        mManagerState = ManagerState::SHOW_AGR_PARTICULAR;
    }
    else if (choice == 2) {
        AgreementManager::changeExpirationDate(mAgreementsList[index - 1]);
        mManagerState = ManagerState::SHOW_AGR_PARTICULAR;
    }
    else if (choice == 3) {
        mManagerState = ManagerState::EDIT_SPEC;
    }

    return index;
}



int DepartmentManager::resolveAgreementSearch() {

    ConsoleManager::redrawAgreementSearchMenu();

    int choice = ConsoleManager::readInt();

    std::vector<unsigned long long> indexes;
    if (choice == 1) {
        ConsoleManager::printRequest("\nВведите номер: ");
        long long agrId = ConsoleManager::readInt();

        indexes = AgreementManager::findPositionsById(mAgreementsList, agrId);
    }
    else if (choice == 2) {
        ConsoleManager::printRequest("\nВведите название организации: ");
        char buf[BUFFER_SIZE];
        ConsoleManager::readString(buf, BUFFER_SIZE);

        indexes = AgreementManager::findPositionsByOrganization(mAgreementsList, buf);
    }
    else {
        mManagerState = ManagerState::MAIN;
        return 0;
    }

    if (indexes.size() > 0) {
        ConsoleManager::redrawAgreementSearchResultsMenu(mAgreementsList, indexes);
    }
    else {
        ConsoleManager::printRequest("\nНет результатов (нажмите любую клавишу, чтобы вернуться)");
    }

    choice = ConsoleManager::readInt();

    if (choice > 0 && choice < indexes.size() + 1) {
        mManagerState = ManagerState::SHOW_AGR_PARTICULAR;
        return indexes[choice - 1] + 1;
    }

    mManagerState = ManagerState::MAIN;
    return 0;
}



int DepartmentManager::resolveSpecificationEditing(int index) {

    Specification& spec = mAgreementsList[index - 1].getSpecification();

    ConsoleManager::redrawSpecificationEditingMenu(spec);

    int choice = ConsoleManager::readInt() - 1;

    if (choice >= 0 && choice < spec.getSuppliesList().size()) {

        Specification::Supply& sup = spec.getSuppliesList()[choice];
        SpecificationManager::changeStatus(sup);
    }

    mManagerState = ManagerState::SHOW_AGR_PARTICULAR;
    return index;
}
