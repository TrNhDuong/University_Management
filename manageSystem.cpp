#include "manageSystem.h"


void UniversitySystem::SetUp(){
    studentDB = &StudentDatabase::getInstance();
    lecturerDB = &LecturerDatabase::getInstance();
    facultyDB = &FacultyDatabase::getInstance();

    StudentReadData& studentReader = StudentReadData::getInstance();
    LecturerReadData& lecturerReader = LecturerReadData::getInstance();
    FacultyReadData& facultyReader = FacultyReadData::getInstance();

    studentReader.readData("Data/StudentData.txt");
    lecturerReader.readData("Data/LecturerData.txt");
    facultyReader.readData("Data/FacultyData.txt");

    mappingDatabase["Student"] = studentDB;
    mappingDatabase["Lecturer"] = lecturerDB;
    mappingDatabase["Faculty"] = facultyDB;
}

void UniversitySystem::Run(){
    SetUp();

    MenuFactory menuFactory;
    unique_ptr<Menu> mainMenu = menuFactory.createMenu("Main");
    unique_ptr<Menu> entityMenu = menuFactory.createMenu("Entity");
    unique_ptr<Menu> subMenu = menuFactory.createMenu("Sub");

    ICommand* commandMachine = nullptr;
    
    while (true) {
        string typeCommand, typeEntity, typeSubCommand = "";
        typeCommand = mainMenu->getChoice();
        if (typeCommand == "Exit"){
            TurnOffProgram::execute(mappingDatabase);
            break;
        }
        while (true){
            typeEntity = entityMenu->getChoice();
            if (typeEntity == "Exit"){
                break;
            }

            if (typeCommand == "Search"){
                typeSubCommand = subMenu->getChoice();
            }
            
            commandMachine = CommandFactory::create(typeCommand);
            commandMachine->execute(mappingDatabase, typeEntity, typeSubCommand);
            delete commandMachine;
            commandMachine = nullptr;
        }
    }
}