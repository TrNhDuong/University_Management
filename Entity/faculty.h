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
    Lecturer _dean; // ID cua Truong khoa
public:
    string getType() const;
    Lecturer getDean() const;
    void setDean(const Lecturer& dean);

    Faculty();
    ~Faculty();
};


#endif