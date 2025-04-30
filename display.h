#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "data.h"

class IDisplay{
public:
    virtual ~IDisplay() = default;
};

class StudentDatabaseDisplay: public IDisplay{
public:
    static void display(StudentDatabase* studentDTB);
    ~StudentDatabaseDisplay();
};

class LecturerDatabaseDisplay: public IDisplay{
public:
    static void display(LecturerDatabase* lecturerDTB);
    ~LecturerDatabaseDisplay();
};

class FacultyDatabaseDisplay: public IDisplay{
public:
    static void display(FacultyDatabase* facultyDTB);
    ~FacultyDatabaseDisplay();
};

class DisplayFactory{
public:
    void display(IDatabase* database);
};
#endif