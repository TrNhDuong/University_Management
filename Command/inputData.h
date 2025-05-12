#ifndef INPUT_H
#define INPUT_H
#include "../Entity/baseEntity.h"
#include "../Entity/student.h"
#include "../Entity/lecturer.h"
#include "../Entity/faculty.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cin;
using std::cout;

class IDataInput{
public:
    virtual  string getInputType() const = 0;
    virtual BaseEntity* input() = 0;
    virtual ~IDataInput() = default;
    IDataInput() = default;
};

class StudentInput: public IDataInput{
public:
    string getInputType() const override;
    BaseEntity* input() override;
    StudentInput() = default;
    ~StudentInput() = default;
};

class LecturerInput: public IDataInput{
public:
    string getInputType() const override;
    BaseEntity* input() override;
    LecturerInput() = default;
    ~LecturerInput() = default;
};

class FacultyInput: public IDataInput{
public:
    string getInputType() const override;
    BaseEntity* input() override;
    FacultyInput() = default;
    ~FacultyInput() = default;
};

class InputFactory{
public:
    static IDataInput* create(const string& typeEntity);
};
#endif