#include "manageSystem.h"
#include "faculty.h"
#include "menu.h"
#include "display.h"

void UniversitySystem::Run(){
    // studentDB = &StudentDatabase::getInstance();
    // lecturerDB = &LecturerDatabase::getInstance();
    facultyDB = &FacultyDatabase::getInstance();
    // StudentReadData& studentReader = StudentReadData::getInstance();
    // LecturerReadData& lecturerReader = LecturerReadData::getInstance();
    FacultyReadData& facultyReader = FacultyReadData::getInstance();
    // studentReader.readData("Data/StudentData.txt");
    // lecturerReader.readData("Data/LecturerData.txt");
    facultyReader.readData("Data/FacultyData.txt");

    DisplayFactory dpFactory;
    IDisplay* f = dpFactory.createDisplay(facultyDB);
    f->display(facultyDB);
    
}