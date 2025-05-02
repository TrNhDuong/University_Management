#ifndef _MANAGE_SYSTEM_H_
#define _MANAGE_SYSTEM_H_
#include <iostream>
#include "data.h"
#include "readData.h"
using std::cout;
using std::cin;

class UniversitySystem{
private:
    IDatabase* studentDB;
    IDatabase* lecturerDB;
    IDatabase* facultyDB;
public:
    void Run();
    friend class RunSystem;
};
#endif