#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "data.h"
#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"
#include <iostream>
#include <format>
using std::format;
using std::cout;

class IDisplay{
public:
    virtual void display(IDatabase* data) = 0;
    virtual ~IDisplay() = default;
};

class StudentDatabaseDisplay: public IDisplay{
public:
    void display(IDatabase* studentDTB);
    ~StudentDatabaseDisplay();
};

class LecturerDatabaseDisplay: public IDisplay{
public:
    void display(IDatabase* lecturerDTB);
    ~LecturerDatabaseDisplay();
};

class FacultyDatabaseDisplay: public IDisplay{
public:
    void display(IDatabase* facultyDTB);
    ~FacultyDatabaseDisplay();
};

class DisplayFactory{
public:
    static IDisplay* createDisplay(const string& type);
};
#endif