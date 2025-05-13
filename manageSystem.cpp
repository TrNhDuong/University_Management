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
    ICommand* commandMachine = nullptr;
    while (true) {
        string typeCommand, typeEntity, typeSubCommand = "Id";
        typeCommand = mainMenu->getChoice();
        if (typeCommand == "1"){
            typeCommand = "Add";
        } else if (typeCommand == "2"){
            typeCommand = "Remove";
        } else if (typeCommand == "3"){
            typeCommand = "Replace";
        } else if (typeCommand == "4"){
            typeCommand = "Display";
        } else if (typeCommand == "5"){
            TurnOffProgram::excute();
        }
        typeEntity = entityMenu->getChoice();
        if (typeEntity == "1"){
            typeEntity = "Student";
        } else if (typeEntity == "2"){
            typeEntity = "Lecturer";
        } else if (typeEntity == "3"){
            typeEntity = "Faculty";
        } else {
            continue;
        }
        commandMachine = CommandFactory::create(typeCommand);
        commandMachine->excute(mappingDatabase, typeEntity, typeSubCommand);
        delete commandMachine;
        commandMachine = nullptr;
    }
}