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
