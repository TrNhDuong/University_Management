#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "baseEntity.h"

class Student: public BaseEntity{
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
    
    Student();
    ~Student();
public:
    friend class StudentUI;
};

class StudentUI{
public:
    static void print(const Student& student);
};
#endif