#include "faculty.h"
#include <format>

using std::cout, std::endl, std::format;

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

