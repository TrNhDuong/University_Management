/** 
 * @file manageSystem.h
 * @brief Triển khai lớp UniversitySystem cho hệ thống quản lý sinh viên.
 * @details Lớp này cung cấp các phương thức để chạy hệ thống quản lý sinh viên.
*/

#ifndef _MANAGE_SYSTEM_H_
#define _MANAGE_SYSTEM_H_
#include <iostream>
#include <unordered_map>

#include "data.h"
#include "readData.h"

#include "Command/display.h"
#include "Command/search.h"
#include "Command/command.h"

#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"

using std::unordered_map;
using std::cout;
using std::cin;

/**
 * @class UniversitySystem
 * @brief Lớp quản lý hệ thống sinh viên.
 * @details Lớp này cung cấp các phương thức để chạy hệ thống quản lý sinh viên.
 */
class UniversitySystem{
private:
    /**
     * @brief Cơ sở dữ liệu sinh viên.
     * @details Cơ sở dữ liệu này chứa danh sách sinh viên trong hệ thống.
     */
    IDatabase* studentDB;
    IDatabase* lecturerDB;
    IDatabase* facultyDB;
    unordered_map<string, IDatabase*> mappingDatabase;
public:
    void SetUp();
    void Run();
};
#endif