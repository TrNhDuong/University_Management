#include "instructor.h"

Instructor::Instructor(){
    _name = "";
    _id = "";
}

Instructor::~Instructor(){
    
}

string Instructor::getType(){
    return "Instructor";
}

int Instructor::getInstructYear() const {
    return _instructYear;
}

string Instructor::getDegree() const {
    return _academicDegree;
}