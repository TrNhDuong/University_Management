/**
 * @file readData.h
 * @brief Định nghĩa các lớp để đọc dữ liệu từ file
 * @details Các lớp này sử dụng phương thức Singleton để đảm bảo chỉ có một instance duy nhất của mỗi lớp.
 * @note Bao gồm các lớp để đọc dữ liệu cho sinh viên, giảng viên và khoa.
 * @note Các lớp này kế thừa từ lớp trừu tượng IReadData và triển khai phương thức readData để đọc dữ liệu từ file.
 */

#ifndef _READDATA_H
#define _READDATA_H
#include <string> 
#include <sstream>
#include <fstream>
#include "data.h"
#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"
#include "Entity/check.h" //kiểm lỗi dữ liệu
#include<exception> //kiểm lỗi dữ liệu
#include<stdexcept> //kiểm lỗi: sử dụng throw runtime_error
#include <iostream>
using std::getline;
using std::exception, std::runtime_error;
using std::ifstream, std::ofstream;
using std::string, std::stringstream;

/**
 * @class IReadData
 * @brief Lớp trừu tượng đại diện cho máy đọc dữ liệu
 * @details Các lớp con sẽ triển khai phương thức readData để đọc dữ liệu từ file.
 * @note Các lớp con bao gồm FacultyReadData, LecturerReadData và StudentReadData.
 */
class IReadData{
public:
    virtual ~IReadData() = default;
};

/**
 * @class FacultyReadData
 * @brief Lớp đại diện cho máy đọc dữ liệu khoa
 * @details Lớp này kế thừa từ IReadData và triển khai phương thức readData để đọc dữ liệu khoa từ file.
 * @note Sử dụng Singleton để đảm bảo chỉ có một instance duy nhất của lớp này.
 */
class FacultyReadData: public IReadData {
private:
    FacultyReadData() = default; 
    FacultyReadData(const FacultyReadData&) = delete;
    FacultyReadData& operator= (const FacultyReadData&) = delete; 
    ~FacultyReadData() = default;
    ifstream _fileIn; //There is a possibility that program read multiple of files each, so i wont create a class to singleton the ifstream. 
public:
    static FacultyReadData& getInstance(){
        static FacultyReadData instance;
        return instance;
    };
    void readData(const string& filename);
};

/**
 * @class LecturerReadData
 * @brief Lớp đại diện cho máy đọc dữ liệu giảng viên
 * @details Lớp này kế thừa từ IReadData và triển khai phương thức readData để đọc dữ liệu giảng viên từ file.
 * @note Sử dụng Singleton để đảm bảo chỉ có một instance duy nhất của lớp này.
 */
class LecturerReadData : public IReadData{
private:
    LecturerReadData() = default;
    LecturerReadData(const LecturerReadData&) = delete;
    LecturerReadData& operator= (const LecturerReadData&) = delete; //for singleton -> No obj assignment ~ no copy constructor
    ~LecturerReadData() = default;
    ifstream _fileIn;
public:
    static LecturerReadData& getInstance(){
        static LecturerReadData instance;
        return instance;
    };
    void readData(const string& filename); 
};

/**
 * @class StudentReadData
 * @brief Lớp đại diện cho máy đọc dữ liệu sinh viên
 * @details Lớp này kế thừa từ IReadData và triển khai phương thức readData để đọc dữ liệu sinh viên từ file.
 * @note Sử dụng Singleton để đảm bảo chỉ có một instance duy nhất của lớp này.
 */
class StudentReadData : public IReadData {
private:
    StudentReadData() = default;
    StudentReadData(const StudentReadData&) = delete;
    StudentReadData& operator= (const StudentReadData&) = delete;
    ~StudentReadData() = default;
    ifstream _fileIn;
public:
    static StudentReadData& getInstance(){
        static StudentReadData instance;
        return instance;
    };
    void readData(const string& filename);
};
#endif