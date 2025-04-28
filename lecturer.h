#ifndef _LECTURER_H_
#define _LECTURER_H_
#include "baseEntity.h"
using std::string;

class Lecturer:public BaseEntity{
private:
    int _instructYear;
    string _academicDegree;
public:
    string getType();
    int getInstructYear() const;
    string getDegree() const;
    Lecturer();
    ~Lecturer();
};
#endif