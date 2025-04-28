#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "baseEntity.h"
#include <string>
using std::string;

class Faculty : public BaseEntity{
    string _email;
public:
    string getType();
    string getMail();
    void setMail(const string& mail);

    Faculty();
    ~Faculty();
};
#endif