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

void FacultyUI::print(Faculty& faculty){
    cout << faculty.getId() << "|" << faculty.getName() << "|"
     << faculty.getBirth().getDay() << "/" << faculty.getBirth().getMonth() << "/" << faculty.getBirth().getYear() << "|"
    << faculty.getMail() << "|" << faculty.getDean().getId() << '\n';
}