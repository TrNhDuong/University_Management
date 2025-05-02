#include "data.h"
#include "baseEntity.h"
#include <fstream>
#include <iostream>
#include<exception>
using std::cout;
using std::fstream;


string StudentDatabase::getDataType() const {
    return "Student";
}

string LecturerDatabase::getDataType() const {
    return "Lecturer";
}

string FacultyDatabase::getDataType() const {
    return "Faculty";
}

int LecturerDatabase::find_obj(const string& id) const{ //return the index
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; //return -1 if it not find out
    return i;
}

Lecturer& LecturerDatabase::getData(const int& index){ //return the instance 
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index lecturer out of bound\n");
    }
    return _data[index];
}

