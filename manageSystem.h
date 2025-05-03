#ifndef _MANAGE_SYSTEM_H_
#define _MANAGE_SYSTEM_H_
#include <iostream>
#include "data.h"
#include "readData.h"
#include "menu.h"
#include "display.h"
#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"
#include "search.h"
#include <unordered_map>
using std::unordered_map;
using std::cout;
using std::cin;

class UniversitySystem{
private:
    IDatabase* studentDB;
    IDatabase* lecturerDB;
    IDatabase* facultyDB;
    unordered_map<string, IDatabase*> mappingDatabase;
public:
    void SetUp();
    void Run();
    friend class Command;
};
#endif