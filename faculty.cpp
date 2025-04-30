#include "faculty.h"

string Faculty::getType(){
    return "Faculty";
}

string Faculty::getMail(){
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
