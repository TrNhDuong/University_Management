#ifndef _MANAGE_SYSTEM_H_
#define _MANAGE_SYSTEM_H_
#include <iostream>
#include <map>
#include <unistd.h>
#include "data.h"
#include "readData.h"

#include "Command/display.h"
#include "Command/search.h"
#include "Command/command.h"

#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"

using std::map;
using std::cout;
using std::cin;


class UniversitySystem{
private:
    IDatabase* studentDB;
    IDatabase* lecturerDB;
    IDatabase* facultyDB;
    map<string, IDatabase*> mappingDatabase;
public:
    void SetUp();
    void Run();
};
#endif