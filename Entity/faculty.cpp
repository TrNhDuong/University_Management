#include "faculty.h"

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
    cout << format(
        "{:10}|{:25}|{:02}/{:02}/{:4}|{:30}|{:25}\n",
        faculty.getId(), faculty.getName(),
        faculty.getBirth().getDay(), faculty.getBirth().getMonth(), faculty.getBirth().getYear(), 
        faculty.getMail(), faculty.getDean().getName()
    );
}