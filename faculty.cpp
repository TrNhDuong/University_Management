/**
 * @file faculty.cpp
 * @brief Triển khai các lớp liên quan đến khoa.
 * @details Các lớp này bao gồm lớp Faculty và các phương thức liên quan đến khoa.
 */

#include "faculty.h"
#include "utils.h"

/**
 * @brief Hamh lấy kiểu dữ liệu của lớp Faculty.
 * @return Kiểu dữ liệu của lớp Faculty.
 */
string Faculty::getType() const{
    return "Faculty";
}

/**
 * @brief Hàm lấy mã email của khoa.
 * @return email của khoa.
 */
string Faculty::getMail() const{
    return _email;
}

/**
 * @brief Hàm đặt email của khoa.
 * @param mail email mới của khoa.
 */
void Faculty::setMail(const string& mail){
    _email = mail;
}

/**
 * @brief Hàm khởi tạo mặc định cho lớp Faculty.
 * @details Hàm này khởi tạo các thuộc tính của lớp Faculty với giá trị mặc định.
 */
Faculty::Faculty(){
    _name = "";
    _id = "";
    _email = "";
}

/**
 * @brief Hàm hủy của lớp Faculty.
 * @details Hàm này được gọi khi đối tượng Faculty bị hủy.
 */
Faculty::~Faculty(){
}

/**
 * @brief Hàm đặt trưởng khoa cho lớp Faculty.
 * @param dean Trưởng khoa mới.
 */
void Faculty::setDean(const Lecturer& dean){
    _dean = dean;
}

/**
 * @brief Hàm lấy trưởng khoa của lớp Faculty.
 * @return Trưởng khoa của lớp Faculty.
 */
Lecturer Faculty::getDean() const{
    return _dean;
}

/**
 * @brief Hàm in thông tin của khoa.
 * @param faculty Đối tượng khoa cần in thông tin.
 * @details Hàm này in ra thông tin của khoa bao gồm mã khoa, tên khoa, ngày sinh, email và trưởng khoa.
 */
void FacultyUI::print(Faculty& faculty){
    cout << faculty.getId() << "|" << faculty.getName() << "|"
     << faculty.getBirth().getDay() << "/" << faculty.getBirth().getMonth() << "/" << faculty.getBirth().getYear() << "|"
    << faculty.getMail() << "|" << faculty.getDean().getId() << '\n';
}