/**
 * @file manageSystem.h
 * @brief Quản lý hệ thống đại học
 * @details Lớp UniversitySystem đại diện cho hệ thống quản lý đại học, bao gồm các cơ sở dữ liệu cho sinh viên, giảng viên và khoa.
 * @note Bao gồm các phương thức để thiết lập hệ thống, chạy hệ thống và quản lý các cơ sở dữ liệu.
 * @note Lớp này sử dụng các lớp Command để thực hiện các thao tác trên cơ sở dữ liệu.
 * @note Các lớp Entity đại diện cho các thực thể trong hệ thống như Student, Lecturer, Faculty.
 */

#ifndef _MANAGE_SYSTEM_H_
#define _MANAGE_SYSTEM_H_
#include <iostream>
#include <map>
#include <unistd.h>
#include "data.h"
#include "readData.h"
#include "menu.h"

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

/**
 * @class UniversitySystem
 * @brief Lớp đại diện cho hệ thống quản lý đại học
 * @details Lớp này quản lý các cơ sở dữ liệu cho sinh viên, giảng viên và khoa, cung cấp các phương thức để thiết lập và chạy hệ thống.
 * @note Bao gồm các phương thức SetUp để thiết lập các cơ sở dữ liệu và Run để chạy hệ thống.
 */
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