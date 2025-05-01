#include "faculty.h"
#include <iostream>
#include <format>
using std::cout;
using std::format;

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

Lecturer Faculty::getDean(){
    return _dean;
}

void Faculty::setDean(const Lecturer& dean){
    _dean = dean;
}

void FacultyUI::print(const Faculty& faculty){
    
}