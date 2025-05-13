/**
 * @file lecturer.cpp
 * @brief Triển khai các lớp liên quan đến giảng viên.
 * @details Các lớp này bao gồm lớp Lecturer và các phương thức liên quan đến giảng viên.
 */

#include "lecturer.h"
#include <iostream>
#include <format>
using std::format;
using std::cout;

/**
 * @brief Hàm khơi tạo mặc định cho lớp Lecturer.
 * @details Hàm này khởi tạo các thuộc tính của lớp Lecturer với giá trị mặc định.
 */
Lecturer::Lecturer(){
    _name = "";
    _id = "";
}

/**
 * @brief Hàm đặt năm giảng dạy cho lớp Lecturer.
 * @param year Năm giảng dạy mới.
 */
void Lecturer::setInstructYear(const int& year){
    _instructYear = year;
}

/**
 * @brief Hàm đặt học vị cho lớp Lecturer.
 * @param deg Học vị mới.
 */
void Lecturer::setDeg(const string& deg){
    _academicDegree = deg;
}

/**
 * @brief Hàm hủy của lớp Lecturer.
 * @details Hàm này được gọi khi đối tượng Lecturer bị hủy.
 */
Lecturer::~Lecturer(){
    
}

/**
 * @brief Hàm lấy kiểu dữ liệu của lớp Lecturer.
 * @return Kiểu dữ liệu của lớp Lecturer.
 */
string Lecturer::getType(){
    return "Lecturer";
}

/**
 * @brief Hàm lấy năm giảng dạy của lớp Lecturer.
 * @return Năm giảng dạy của lớp Lecturer.
 */
int Lecturer::getInstructYear() const {
    return _instructYear;
}

/**
 * @brief Hàm lấy học vị của lớp Lecturer.
 * @return Học vị của lớp Lecturer.
 */
string Lecturer::getDegree() const {
    return _academicDegree;
}
