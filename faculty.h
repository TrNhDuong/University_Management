#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "baseEntity.h"
#include "lecturer.h"
#include "utils.h"

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

class FacultyInfo{
    public:
        static void printFacultyInfo(const Faculty& faculty);
        static Faculty getInfo();
};

class FacultyData{
    public:
        static vector<Faculty> _data;
    public:
        static void addFaculty(Faculty& faculty);
        static void removeFaculty(Faculty& faculty);
        static void replaceFaculty(Faculty& oldFaculty, Faculty& newFaculty);
};


#endif