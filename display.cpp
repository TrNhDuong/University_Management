#include "display.h"

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

}

FacultyDatabaseDisplay::~FacultyDatabaseDisplay(){

}

void DisplayFactory::display(IDatabase* database){
    if ("Student" == database->getDataType()){
        StudentDatabase* stuDTB = dynamic_cast<StudentDatabase*>(database);
        
    }
}