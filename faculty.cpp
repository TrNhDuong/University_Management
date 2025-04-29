#include "faculty.h"
#include <format>

using std::cout, std::endl, std::format, std::cin;

string Faculty::getType() const{
    return "Faculty";
}

string Faculty::getMail() const{
    return _email;
}

void Faculty::setMail(const string& mail){
    _email = mail;
}

Faculty::Faculty(){
    _name = "";
    _id = "";
    _email = "";
}

Faculty::~Faculty(){
}


void Faculty::setDean(const Instructor& dean){
    _dean = dean;
}

Instructor Faculty::getDean() const{
    return _dean;
}

void FacultyInfo::printFacultyInfo(const Faculty& faculty){
    cout << format("Faculty Name: {}\n", faculty.getName());
    cout << format("Faclty ID: {}\n", faculty.getId());
    cout << format("Faculty Birth: {:02}/{:02}/{}\n"
        , faculty.getBirth().getDay()
        , faculty.getBirth().getMonth()
        , faculty.getBirth().getYear());
    cout << format("Faculty Dean: {}\n", faculty.getDean().getName());
}

void FacultyData::addFaculty(Faculty& faculty){
    addData(_data, faculty);
}


void FacultyData::removeFaculty(Faculty& faculty){
    removeData(_data, faculty);
}


void FacultyData::replaceFaculty(Faculty& oldFaculty, Faculty& newFaculty){
    replaceData(_data, oldFaculty, newFaculty);
}

vector<Faculty> FacultyData::_data;

Faculty FacultyInfo::getInfo(){
    Faculty newData;
    string tem;
    cout << "====Mời bạn nhập thông tin Khoa mới====\n";

    cout << "Tên khoa: ";
    getline(cin, tem);
    newData.setName(tem);

    cout << "Mã khoa: ";
    getline(cin, tem);
    newData.setId(tem);

    cout << "Ngày thành lập: ";
    getline(cin, tem);
    newData.setBirth(tem);

    cout << "Email: ";
    getline(cin, tem);
    newData.setMail(tem);

    // cout << "\nMã trưởng khoa: ";
    // getline(cin, tem);

    cout << "Thằng ngu đã nhập dữ liệu thành công!\n";
    
    return newData;
    
}