#include "display.h"
#include <iostream>
#include <format>
using std::format;
using std::cout;

void StudentDatabaseDisplay::display(StudentDatabase* studentDTB){
    int size = studentDTB->_data.size();
    for (int i = 0; i < size; i++)
        StudentUI::print(studentDTB->_data[i]);
};

StudentDatabaseDisplay::~StudentDatabaseDisplay(){

}

void LecturerDatabaseDisplay::display(LecturerDatabase* lecturerDTB){
    int size = lecturerDTB->_data.size();
    for (int i = 0; i < size; i++)
        LecturerUI::print(lecturerDTB->_data[i]);
}

LecturerDatabaseDisplay::~LecturerDatabaseDisplay(){

}

void FacultyDatabaseDisplay::display(FacultyDatabase* facultyDTB){
    int size = facultyDTB->_data.size();
}

FacultyDatabaseDisplay::~FacultyDatabaseDisplay(){

}

void DisplayFactory::display(IDatabase* database){
    if ("Student" == database->getDataType()){
        StudentDatabase* stuDTB = dynamic_cast<StudentDatabase*>(database);
        StudentDatabaseDisplay::display(stuDTB);
    } else if ("Lecturer" == database->getDataType()){
        LecturerDatabase* lecturerDTB = dynamic_cast<LecturerDatabase*>(database);
        LecturerDatabaseDisplay::display(lecturerDTB);
    } else if ("Faculty" == database->getDataType()){
        FacultyDatabase* facultyDTB = dynamic_cast<FacultyDatabase*>(database);
        FacultyDatabaseDisplay::display(facultyDTB);
    }
}