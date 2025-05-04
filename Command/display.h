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

class IUI{
public:
    virtual void print(BaseEntity*) = 0;
    virtual ~IUI() = default;
};

class LecturerUI: public IUI{
public:
    void print(BaseEntity* lecturer) override;
};

class StudentUI: public IUI{
public:
    void print(BaseEntity* student) override;
};

class FacultyUI: public IUI{
public:
    void print(BaseEntity* student) override;
};

class UIFactory {
public:
    static IUI* createUI(const string& type) {
        if (type == "Student")
            return new StudentUI();
        else if (type == "Lecturer")
            return new LecturerUI();

        return nullptr;
    }
};

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