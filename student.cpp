/**
 * @file student.cpp
 * @brief Triển khai các lớp liên quan đến sinh viên.
 * @details Các lớp này bao gồm lớp Student và các phương thức liên quan đến sinh viên.
 */

#include "student.h"
#include <format>
#include <iostream>
using std::cout, std::cin;
using std::format;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Student.
 * @details Hàm này khởi tạo các thuộc tính của lớp Student với giá trị mặc định.
 */
Student::Student(){
    _name = "";
    _gpa = 0;
    _id = "";
    _completedCredit = 0;
}

/**
 * @brief Hàm hủy của lớp Student.
 * @details Hàm này được gọi khi đối tượng Student bị hủy.
 */
Student::~Student(){
    
}

/**
 * @brief Hàm lấy kiểu dữ liệu của lớp Student.
 * @return Kiểu dữ liệu của lớp Student.
 */
string Student::getType(){
    return "Student";
}

/**
 * @brief Hàm lấy điểm trung bình của lớp Student.
 * @return Điểm trung bình của lớp Student.
 */
float Student::getGPA() const{
    return _gpa;
}

/**
 * @brief Hàm lấy số tín chỉ đã hoàn thành của lớp Student.
 * @return Số tín chỉ đã hoàn thành của lớp Student.
 */
int Student::getCompletedCredit() const{
    return _completedCredit;
}

/**
 * @brief Hàm lấy năm nhập học của lớp Student.
 * @return Năm nhập học của lớp Student.
 */
int Student:: getEnrollYear() const{
    return _enrollYear;
}

/**
 * @brief Hàm đặt điểm trung bình cho lớp Student.
 * @param gpa Điểm trung bình mới.
 * @details Hàm này cập nhật điểm trung bình của sinh viên.
 */
void Student::setGPA(const float& gpa){
    _gpa = gpa;
}

/**
 * @brief Hàm đặt số tín chỉ đã hoàn thành cho lớp Student.
 * @param credit Số tín chỉ mới.
 * @details Hàm này cập nhật số tín chỉ đã hoàn thành của sinh viên.
 */
void Student::setCredit(const int& credit){
    _completedCredit = credit;
}

/**
 * @brief Hàm đặt năm nhập học cho lớp Student.
 * @param year Năm nhập học mới.
 * @details Hàm này cập nhật năm nhập học của sinh viên.
 */
void Student::setEnrollYear(const int& year){
    _enrollYear = year;
}

/**
 * @brief Hàm in thông tin của sinh viên.
 * @param st Đối tượng sinh viên cần in thông tin.
 * @details Hàm này in ra thông tin của sinh viên trên */
void StudentUI::print(const Student& st){
    cout << format(
        "{:10}|{:25}|{:2}/{:2}/{:4}|{:5}|{:4}\n",
        st.getId(),st.getName(), 
        st.getBirth().getDay(), st.getBirth().getMonth(), st.getBirth().getYear(), 
        st.getGPA(), st.getCompletedCredit()
        );
}

