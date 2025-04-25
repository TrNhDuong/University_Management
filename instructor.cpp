#include "instructor.h"

Instructor::Instructor(){
    _name = "A";
    _id = "11111111";
}

Instructor::~Instructor(){
    
}

int Instructor::getInstructYear() const {
    return _instructYear;
}

string Instructor::getDegree() const {
    return _academicDegree;
}