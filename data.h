#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include "student.h"
#include "lecturer.h"
#include"faculty.h"
#include <string>
using std::vector;
using std::string;


class IDatabase{
public:
    virtual string getDataType() const = 0;
    virtual ~IDatabase() = default;
};

class StudentDatabase: public IDatabase{
private:
    static vector<Student> _data;
public:
    string getDataType() const;
    friend class StudentDatabaseDisplay;
};


class LecturerDatabase: public IDatabase{
private:
    static vector<Lecturer> _data;
public:
    string getDataType() const;
    friend class LecturerDatabaseDisplay;
};


class FacultyDatabase: public IDatabase{
private:
    vector<Faculty> _data;
public:
    string getDataType();
    ~FacultyDatabase();
    
    friend class FacultyDatabaseDisplay;
};




#endif