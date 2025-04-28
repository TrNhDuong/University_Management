#ifndef _INSTRUCTOR_H_
#define _INSTRUCTOR_H_
#include "baseEntity.h"
using std::string;

class Instructor:public BaseEntity{
private:
    int _instructYear;
    string _academicDegree;
public:
    string getType();
    int getInstructYear() const;
    string getDegree() const;
    Instructor();
    ~Instructor();
};
#endif