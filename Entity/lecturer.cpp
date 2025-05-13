#include "lecturer.h"
#include <iostream>
#include <format>
using std::format;
using std::cout;

Lecturer::Lecturer(){
    _name = "";
    _id = "";
}

void Lecturer::setInstructYear(const int& year){
    _instructYear = year;
}
void Lecturer::setDeg(const string& deg){
    _academicDegree = deg;
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
