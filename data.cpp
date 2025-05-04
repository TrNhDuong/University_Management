#include "data.h"


string StudentDatabase::getDataType() const {
    return "Student";
}

string LecturerDatabase::getDataType() const {
    return "Lecturer";
}

string FacultyDatabase::getDataType() const {
    return "Faculty";
}

int StudentDatabase::getSize() const {
    return _data.size();
}

int LecturerDatabase::getSize() const {
    return _data.size();
}

int FacultyDatabase::getSize() const {
    return _data.size();
}

Student* StudentDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size())
        return nullptr;
    return &_data[index];
}

Lecturer* LecturerDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size())
        return nullptr;
    return &_data[index];
}

Faculty* FacultyDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size())
        return nullptr;
    return &_data[index];
}

