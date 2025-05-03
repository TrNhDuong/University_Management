#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "baseEntity.h"
#include "lecturer.h"
#include <vector>
#include <iostream>
#include <format>
using std::format;
using std::cout;
using std::string, std::vector;

class Faculty : public BaseEntity{
protected:
    string _email;
    Lecturer _dean; // ID cua Truong khoa
public:
    string getType() const;
    string getMail() const;
    Lecturer getDean() const;
    void setMail(const string& mail);
    void setDean(const Lecturer& dean);

    Faculty();
    ~Faculty();
};

class FacultyUI{
public:
    static void print(Faculty& faculty);
};

#endif