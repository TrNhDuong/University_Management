/** 
 * @file manageSystem.h
 * @brief Triển khai lớp UniversitySystem cho hệ thống quản lý sinh viên.
 * @details Lớp này cung cấp các phương thức để chạy hệ thống quản lý sinh viên.
*/

#ifndef _MANAGE_SYSTEM_H_
#define _MANAGE_SYSTEM_H_
#include <iostream>
#include "data.h"
#include "readData.h"
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
public:
    /**
     * @brief Hàm khởi tạo mặc định cho lớp UniversitySystem.
     * @details Hàm này khởi tạo các cơ sở dữ liệu sinh viên, giảng viên và khoa.
     */
    void Run();

    friend class RunSystem;
};
#endif