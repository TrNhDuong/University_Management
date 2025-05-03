#include "student.h"
#include <format>
#include <iostream>
using std::cout;
using std::format;

Student::Student(){
    _name = "";
    _gpa = 0;
    _id = "";
    _completedCredit = 0;
}

Student::~Student(){
    
}

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

void Student::setEnrollYear(const int& year){
    _enrollYear = year;
}

void StudentUI::print(const Student& st){
    cout << format(
        "{:10}|{:25}|{:02}/{:02}/{:04}|{:5}|{:4}\n",
        st.getId(),st.getName(), 
        st.getBirth().getDay(), st.getBirth().getMonth(), st.getBirth().getYear(), 
        st.getGPA(), st.getCompletedCredit()
        );
}
