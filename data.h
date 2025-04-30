#ifndef _DATA_H_
#define _DATA_H_
#include "baseEntity.h"
#include "student.h"
#include "lecturer.h"
#include "faculty.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class IDatabase{
public:
    virtual string getDataType() const = 0;
    virtual ~IDatabase() = default;
};

class StudentDatabase: public IDatabase{
private:
    vector<Student> _data;
public:
    string getDataType();
    ~StudentDatabase();

    friend class StudentDatabaseDisplay;
};

class LecturerDatabase: public IDatabase{
private:
    vector<Lecturer> _data;
public:
    string getDataType();
    ~LecturerDatabase();

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