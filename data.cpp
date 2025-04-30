#include "data.h"
#include "baseEntity.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::fstream;

vector<Student> StudentDatabase::_data;
vector<Lecturer> LecturerDatabase::_data;
vector<Faculty> FacultyDatabase::_data;

string StudentDatabase::getDataType() const {
    return "Student";
}

string LecturerDatabase::getDataType() const {
    return "Lecturer";
}

string FacultyDatabase::getDataType() const {
    return "Faculty";
}