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
    void setInstructYear(const int& year);
    void setDeg(const string& deg);
    Lecturer();
    ~Lecturer();
    friend class LecturerBuilder;
};
class LecturerBuilder;
#endif