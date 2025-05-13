#include "data.h"

#pragma region getDataType
string StudentDatabase::getDataType() const {
    return "Student";
}

string LecturerDatabase::getDataType() const {
    return "Lecturer";
}

string FacultyDatabase::getDataType() const {
    return "Faculty";
}
#pragma endregion

#pragma region getSize

int StudentDatabase::getSize() const {
    return _data.size();
}

int LecturerDatabase::getSize() const {
    return _data.size();
}

int FacultyDatabase::getSize() const {
    return _data.size();
}
#pragma endregion
//since the singleton in each student, faculty and lecturer database 
//=> Can not use virtual for find_obj() and getData() method 
//find_obj()

#pragma region find(id)
//return -1 if not exists in database
int StudentDatabase::find(const string& id) const {
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1;
    return i;
}

int LecturerDatabase::find(const string& id) const{
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; 
    return i;
}

int FacultyDatabase::find(const string& id) const{
    int size = _data.size();
    int index = -1;
    for (int i = 0; i < size; i++)
        if (_data[i].getId() == id){
            index = i;
            break;
        }
    return index;
}
#pragma endregion

#pragma region getData
//Get data at index 
BaseEntity* FacultyDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Faculty out of bound\n");
    }
    return &_data[index];
}

BaseEntity* StudentDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Student out of bound\n");
    }
    return &_data[index];
}

BaseEntity* LecturerDatabase::getData(const int& index){ //return the instance 
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Lecturer out of bound\n");
    }
    return &_data[index];
}

#pragma endregion

#pragma region Add, Remove, Replace Student
//Add, Remove, Replace method
//Student
void StudentDatabase:: Add(BaseEntity* obj){
    Student* s = dynamic_cast<Student*>(obj);
    _data.push_back(*s);
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
bool StudentDatabase::Remove(BaseEntity* obj){
    return Remove(obj->getId());
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
#pragma endregion

#pragma region Add, Remove, Replace Faculty

void FacultyDatabase:: Add(BaseEntity* obj){
    Faculty* s = dynamic_cast<Faculty*>(obj);
    _data.push_back(*s);
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
bool FacultyDatabase::Remove(BaseEntity* obj){
    return Remove(obj->getId());
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

#pragma endregion

#pragma region Add, Remove, Replace Lecturer

void LecturerDatabase:: Add(BaseEntity* obj){
    Lecturer* s = dynamic_cast<Lecturer*>(obj);
    _data.push_back(*s);
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
bool LecturerDatabase::Remove(BaseEntity* obj){
    return Remove(obj->getId());
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

#pragma endregion