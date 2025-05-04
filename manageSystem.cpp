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
    SearchCommand searching;
    DisplayCommand displaying;
    displaying.displayDatabase(studentDB);
    searching.searchObject(studentDB, "23120243");
}