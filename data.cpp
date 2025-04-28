#include "data.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::fstream;

vector<Student> StudentDatabase::_dataBase;

int StudentDatabase::getSize() const{
    return _dataBase.size();
}

Student& StudentDatabase::getData(const int& index) const {
    return _dataBase[index];
}

void StudentDatabase::add(const Student& value){
    _dataBase.push_back(value);
}
void StudentDatabase::delete_obj(Student& value){
    //find value and delete it by using vector.erase
    int i = 0;
    for (const Student& s : _dataBase){
         if (s.getId() != value.getId()) {++i;}
         else break;
    }
    if (i <_databBase.size())_dataBase.erase(_dataBase.begin()+i);
    else {
        cout <<"Student with ID: " << value.getId() << " not found!\n"; 
    }
}

void StudentDatabaseDisplay::display(const StudentDatabase& studentDtb){
    int n = studentDtb.getSize();
    for (int i = 0; i < n; i++){ 
        StudentUI::print(studentDtb.getData(i));
    }
}

Student StudentDatabaseGetData::readLine(const string& inputLine){
    int len = inputLine.size();
    vector<string> list;
    string temp = "";
    for (int i = 0; i < len; i++)
        if (inputLine[i] == '|'){
            list.push_back(temp);
            temp = "";
        } else {
            temp += inputLine[i];
        }
    list.push_back(temp);
    Student ans;
    ans.setName(list[0]);
    ans.setId(list[1]);
    ans.setBirth(list[2]);
    ans.setGPA(stof(list[3]));
    ans.setCredit(stoi(list[4]));
    return ans;
}

StudentDatabase StudentDatabaseGetData::read(const string& inputFile){
    fstream file(inputFile, std::ios::in);
    StudentDatabase studentDTB;
    string line;
    while (getline(file, line)){
        Student value = readLine(line);
        studentDTB.add(value);
    }
    file.close();
    return studentDTB;
}

