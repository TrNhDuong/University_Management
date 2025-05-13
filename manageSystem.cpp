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
    ICommand* commandMachine = nullptr;
    while (true){
        cout << "Nhap chuc nang muon tim: 1.Display, 2.Search, 3.Add\n";
        int c;
        cin >> c;
        if (c == 1){
            commandMachine = new DisplayCommand();
            commandMachine->excute(mappingDatabase, "Student", "Id");
        } else if (c == 2){
            commandMachine = new SearchCommand();
            commandMachine->excute(mappingDatabase, "Student", "Id");
        } else if (c == 3){
            commandMachine = new AddCommand();
            commandMachine->excute(mappingDatabase, "Student", "");
        } else {
            break;
        }
        delete commandMachine;
        commandMachine = nullptr;
        cout << "Press to return menu\n";
        cin.ignore();
        if (cin.get())
            system("clear");
    }
}