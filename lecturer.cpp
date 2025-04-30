#include "lecturer.h"
#include <iostream>
#include <format>
using std::format;
using std::cout;

Lecturer::Lecturer(){
    _name = "";
    _id = "";
}

Lecturer::~Lecturer(){
    
}

string Lecturer::getType(){
    return "Lecturer";
}

int Lecturer::getInstructYear() const {
    return _instructYear;
}

string Lecturer::getDegree() const {
    return _academicDegree;
}

void LecturerUI::print(const Lecturer& lt){
    cout << format(
        "{:10}|{:25}|{:2}/{:2}/{:4}|{:5}|{:4}\n",
        lt.getId(),lt.getName(), 
        lt.getBirth().getDay(), lt.getBirth().getMonth(), lt.getBirth().getYear(), 
        lt.getInstructYear(), lt.getDegree()
    );
}