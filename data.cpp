#include "data.h"
#include "baseEntity.h"
#include <fstream>
#include <iostream>
#include<exception>
using std::cout;
using std::fstream;

vector<Student> StudentDatabase::_data;
vector<Lecturer> LecturerDatabase::_data;
vector<Faculty> FacultyDatabase:: _data;

string StudentDatabase::getDataType() const {
    return "Student";
}

string LecturerDatabase::getDataType() const {
    return "Lecturer";
}
int LecturerDatabase::find_obj(const string& id) const{ //return the index
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if(i == _data.size()) return -1; //return -1 if it not find out
    return i;
}
Lecturer& LecturerDatabase::getData(const int& index) const{ //return the instance 
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index lecturer out of bound\n");
    }
    else {
        return _data[index];
    }
}

string FacultyDatabase::getDataType() const {
    return "Faculty";
}