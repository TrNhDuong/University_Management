#include "faculty.h"
#include "utils.h"

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


void Faculty::setDean(const Lecturer& dean){
    _dean = dean;
}

Lecturer Faculty::getDean() const{
    return _dean;
}

// void FacultyInfo::printFacultyInfo(const Faculty& faculty){
//     cout << format("Faculty Name: {}\n", faculty.getName());
//     cout << format("Faclty ID: {}\n", faculty.getId());
//     cout << format("Faculty Birth: {:02}/{:02}/{}\n"
//         , faculty.getBirth().getDay()
//         , faculty.getBirth().getMonth()
//         , faculty.getBirth().getYear());
//     cout << format("Faculty Dean: {}\n", faculty.getDean().getName());
// }

void FacultyInfo::printFacultyInfo(const Faculty& faculty){
    std::cout << std::left
          << std::setw(10) << faculty.getId()
          << std::setw(20) << faculty.getName()
          << std::setw(12)
          << (std::format("{:02}/{:02}/{}", faculty.getBirth().getDay(), faculty.getBirth().getMonth(), faculty.getBirth().getYear()))
          << std::setw(30) << faculty.getMail()
          << std::setw(25) << faculty.getDean().getName()
          << "\n";
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

    cout << "Tên trưởng khoa: ";
    getline(cin, tem);
    Lecturer dean;
    dean.setName(tem);
    newData.setDean(dean);

    cout << "Thằng ngu đã nhập dữ liệu thành công!\n";
    
    return newData;
    
}