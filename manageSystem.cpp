/**
 * @file manageSystem.cpp
 * @brief Triển khai lớp UniversitySystem cho hệ thống quản lý sinh viên.
 * @details
 * Lớp này chứa các phương thức để khởi động hệ thống quản lý sinh viên, bao gồm việc đọc dữ liệu từ file,
 * tạo các menu và thực hiện các lệnh tương ứng với lựa chọn của người dùng.
 */

#include "menu.h"
#include "manageSystem.h"

void UniversitySystem::SetUp(){
    studentDB = &StudentDatabase::getInstance();
    lecturerDB = &LecturerDatabase::getInstance();
    facultyDB = &FacultyDatabase::getInstance();

    StudentReadData& studentReader = StudentReadData::getInstance();
    LecturerReadData& lecturerReader = LecturerReadData::getInstance();
    FacultyReadData& facultyReader = FacultyReadData::getInstance();

    studentReader.readData("Data/StudentData.txt");
    lecturerReader.readData("Data/LecturerData.txt");
    facultyReader.readData("Data/FacultyData.txt");

    mappingDatabase["Student"] = studentDB;
    mappingDatabase["Lecturer"] = lecturerDB;
    mappingDatabase["Faculty"] = facultyDB;
}

void UniversitySystem::Run(){
    SetUp();
    SearchCommand searching;
    DisplayCommand displaying;
    displaying.displayDatabase(studentDB);
    searching.searchObject(studentDB, "23120243");
}