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
//since the singleton in each student, faculty and lecturer database 
//=> Can not use virtual for find_obj() and getData() method 
//find_obj()
Student* StudentDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size())
        return nullptr;
    return &_data[index];
}

int LecturerDatabase::find(const string& id) const{ //return the index
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; //return -1 if it not find out
    return i;
}

int StudentDatabase::find(const string& id) const {
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; //return -1 if it not find out
    return i;
}

int LecturerDatabase::find(const string& id) const{ //return the index
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; //return -1 if it not find out
    return i;
}

//Get data()
Faculty& FacultyDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Faculty out of bound\n");
    }
    return _data[index];
}

Student& StudentDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Student out of bound\n");
    }
    return _data[index];
}
Lecturer& LecturerDatabase::getData(const int& index){ //return the instance 
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Lecturer out of bound\n");
    }
    return _data[index];
}


//Add, Remove, Replace method
//Student
void StudentDatabase:: Add(const Student& obj){
    _data.push_back(obj);
}
bool StudentDatabase::Remove(const string& ID){
    for (int i = 0; i < _data.size(); ++i){
        if (ID == _data[i].getId()){
            _data.erase(_data.begin()+i);
            return true; 
            break;
        }
    }
    return false; //if delete failed
}
bool StudentDatabase::Remove(Student& obj){
    return Remove(obj.getId());
}
bool StudentDatabase::Replace(Student& des, Student& src){
    int index = find(des.getId());
    if(index >= 0){
        _data[index].setName(src.getName());
        _data[index].setId(src.getId());
        _data[index].setBirth(src.getBirth());
        _data[index].setGPA(src.getGPA());
        _data[index].setEnrollYear(src.getEnrollYear());
        _data[index].setCredit(src.getCompletedCredit());
        return true;
    }else {
        return false; //if des obj not found
    }
}


//Faculty
void FacultyDatabase:: Add(const Faculty& obj){
    _data.push_back(obj);
}
bool FacultyDatabase::Remove(const string& ID){
    for (int i = 0; i < _data.size(); ++i){
        if (ID == _data[i].getId()){
            _data.erase(_data.begin()+i);
            return true; 
            break;
        }
    }
    return false; //if delete failed
}
bool FacultyDatabase::Remove(Faculty& obj){
    return Remove(obj.getId());
}
bool FacultyDatabase::Replace(Faculty& des, Faculty& src){
    int index = find(des.getId());
    if(index >= 0){
        _data[index].setName(src.getName());
        _data[index].setId(src.getId());
        _data[index].setBirth(src.getBirth());
        _data[index].setMail(src.getMail());
        _data[index].setDean(src.getDean());
        return true;
    }else {
        return false; //if des obj not found
    }
}



//Lecturer
void LecturerDatabase:: Add(const Lecturer& obj){
    _data.push_back(obj);
}
bool LecturerDatabase::Remove(const string& ID){
    for (int i = 0; i < _data.size(); ++i){
        if (ID == _data[i].getId()){
            _data.erase(_data.begin()+i);
            return true; 
            break;
        }
    }
    return false; //if delete failed
}
bool LecturerDatabase::Remove(Lecturer& obj){
    return Remove(obj.getId());
}
bool LecturerDatabase::Replace(Lecturer& des, Lecturer& src){
    int index = find(des.getId());
    if(index >= 0){
        _data[index].setName(src.getName());
        _data[index].setId(src.getId());
        _data[index].setBirth(src.getBirth());
        _data[index].setInstructYear(src.getInstructYear());
        _data[index].setDeg(src.getDegree());
        return true;
    }else {
        return false; //if des obj not found
    }
}