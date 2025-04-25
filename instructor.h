#ifndef _INSTRUCTOR_H_
#define _INSTRUCTOR_H_
#include "individual.h"
using std::string;

class Instructor:public Individual{
private:
    int _instructYear;
    string _academicDegree;
public:
    int getInstructYear() const;
    string getDegree() const;
    Instructor();
    ~Instructor();
};
#endif