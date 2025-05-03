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

//return the index

int FacultyDatabase::find(const string& id) const {

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

void StudentGetData::InputData(Student& student){
    cout << "Nhập tên sinh viên: ";
    string name;
    cin.ignore();
    getline(cin, name);
    student.setName(name);
    cout << "Nhập mã sinh viên: ";
    string id;
    cin >> id;
    student.setId(id);
    cout << "Nhập ngày sinh sinh viên (dd/mm/yyyy): ";
    string birth;
    cin >> birth;
    student.setBirth(birth);

    cout << "Nhập điểm trung bình sinh viên: ";
    float gpa;
    cin >> gpa;
    student.setGPA(gpa);

    cout << "Nhập số tín chỉ đã hoàn thành: ";
    int completedCredit;
    cin >> completedCredit;
    student.setCredit(completedCredit);
}

void LecturerGetData::InputData(Lecturer& lecturer){
    cout << "Nhập tên giảng viên: ";
    string name;
    cin.ignore();
    getline(cin, name);
    lecturer.setName(name);
    cout << "Nhập mã giảng viên: ";
    string id;
    cin >> id;
    lecturer.setId(id);
    cout << "Nhập ngày sinh giảng viên (dd/mm/yyyy): ";
    string birth;
    cin >> birth;
    lecturer.setBirth(birth);

    cout << "Nhập năm giảng dạy: ";
    int instructYear;
    cin >> instructYear;
    lecturer.setInstructYear(instructYear);

    cout << "Nhập học vị: ";
    string degree;
    cin.ignore();
    getline(cin, degree);
    lecturer.setDeg(degree);
}

void FacultyGetData::InputData(Faculty& faculty){
    cout << "Nhập tên khoa: ";
    string name;
    cin.ignore();
    getline(cin, name);
    faculty.setName(name);
    cout << "Nhập mã khoa: ";
    string id;
    cin >> id;
    faculty.setId(id);
    cout << "Nhập ngày thành lập khoa (dd/mm/yyyy): ";
    string birth;
    cin >> birth;
    faculty.setBirth(birth);

    cout << "Nhập email khoa: ";
    string email;
    cin.ignore();
    getline(cin, email);
    faculty.setMail(email);

    cout << "Nhập mã giảng viên trưởng khoa: ";
    string deanId;
    cin >> deanId;
    LecturerDatabase& lecturerDB = LecturerDatabase::getInstance();
    int index = lecturerDB.find(deanId);
    if (index != -1) {
        faculty.setDean(lecturerDB.getData(index));
    } else {
        cout << "Giảng viên không tồn tại trong hệ thống.\n";
        return;
    }
      
}