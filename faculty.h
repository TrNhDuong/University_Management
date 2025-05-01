#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "baseEntity.h"
#include "lecturer.h"
#include <string>
using std::string;

class Faculty : public BaseEntity{
    string _email;
    Lecturer _dean;
public:
    string getType();
    string getMail();
    Lecturer getDean();
    void setMail(const string& mail);
    void setDean(const Lecturer& dean);
    Faculty();
    ~Faculty();
};

class FacultyUI{
public:
    static void print(const Faculty& faculty);
};
#endif