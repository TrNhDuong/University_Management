#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "individual.h"

class Student: public Individual{
private:
    int _enrollYear;
    float _gpa;
    int _completedCredit;
public:
    string getType();
    void setGPA(const float& gpa);
    void setCredit(const int& credit);
    float getGPA() const;
    int getCompletedCredit() const;
};
#endif