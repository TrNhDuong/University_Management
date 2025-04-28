#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "baseEntity.h"
#include "instructor.h"
#include <string>
#include <iostream>
using std::string;

class Faculty : public BaseEntity{
protected:
    string _email;
    Instructor _dean;
public:
    string getType() const;
    string getMail() const;
    Instructor getDean();
    void setMail(const string& mail);
    void setDean(const Instructor& dean);
    void prinInfo();

    Faculty();
    ~Faculty();
};
#endif