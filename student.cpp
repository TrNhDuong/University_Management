#include "student.h"

string Student::getType(){
    return "Student";
}

float Student::getGPA() const{
    return _gpa;
}

int Student::getCompletedCredit() const{
    return _completedCredit;
}

void Student::setGPA(const float& gpa){
    _gpa = gpa;
}

void Student::setCredit(const int& credit){
    _completedCredit = credit;
}
