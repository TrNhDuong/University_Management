#include "display.h"
#include <iostream>
#include <format>
using std::format;
using std::cout;

void StudentDatabaseDisplay::display(IDatabase* database){
    StudentDatabase* studentDTB = dynamic_cast<StudentDatabase*>(database);
    int size = studentDTB->_data.size();
    for (int i = 0; i < size; i++)
        StudentUI::print(studentDTB->_data[i]);
};

StudentDatabaseDisplay::~StudentDatabaseDisplay(){

}

void LecturerDatabaseDisplay::display(IDatabase* database){
    LecturerDatabase* lecturerDTB = dynamic_cast<LecturerDatabase*>(database);
    int size = lecturerDTB->_data.size();
    for (int i = 0; i < size; i++)
        LecturerUI::print(lecturerDTB->_data[i]);
}

LecturerDatabaseDisplay::~LecturerDatabaseDisplay(){

}

void FacultyDatabaseDisplay::display(IDatabase* database){
    FacultyDatabase* facultyDTB = dynamic_cast<FacultyDatabase*>(database);
    int size = facultyDTB->_data.size();

}

FacultyDatabaseDisplay::~FacultyDatabaseDisplay(){

}

IDisplay* DisplayFactory::createDisplay(IDatabase* database){
    if ("Student" == database->getDataType()){
        return new StudentDatabaseDisplay();
    } else if ("Lecturer" == database->getDataType()){
        return new LecturerDatabaseDisplay();
    } else if ("Faculty" == database->getDataType()){
        FacultyDatabase* facultyDTB = dynamic_cast<FacultyDatabase*>(database);
        return new FacultyDatabaseDisplay();
    }
    return nullptr;
}