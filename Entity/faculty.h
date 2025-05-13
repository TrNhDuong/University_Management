/**
 * @file faculty.h
 * @brief Khai báo lớp Faculty và các phương thức liên quan đến khoa.
 * @details Lớp này bao gồm các thuộc tính và phương thức để quản lý thông tin của khoa.
 */

#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "baseEntity.h"
#include "lecturer.h"
#include <vector>
#include <iostream>
#include <format>
using std::format;
using std::cout;
using std::string, std::vector;

/**
 * @class Faculty
 * @brief Lớp đại diện cho khoa.
 * @details Lớp này bao gồm các thuộc tính và phương thức để quản lý thông tin của khoa.
 */
class Faculty : public BaseEntity{
protected:
    /**
     * @brief Địa chỉ email của khoa.
     * @details Địa chỉ email này được sử dụng để liên lạc với khoa.
     */
    string _email;

    /**
     * @brief Trưởng khoa.
     * @details Trưởng khoa là người quản lý và điều hành các hoạt động của khoa.
     */
    Lecturer _dean; // ID cua Truong khoa
public:
    /**
     * @brief Hàm lấy kiểu dữ liệu của lớp Faculty.
     * @return Kiểu dữ liệu của lớp Faculty.
     */
    string getType() const;

    /**
     * @brief Hàm lấy mã email của khoa.
     * @return email của khoa.
     */
    string getMail() const;

    /**
     * @brief Hàm lấy trưởng khoa của lớp Faculty.
     * @return Trưởng khoa của lớp Faculty.
     */
    Lecturer getDean() const;

    /**
     * @brief Hàm đặt mã email của khoa.
     * @param mail email mới của khoa.
     */
    void setMail(const string& mail);

    /**
     * @brief Hàm đặt trưởng khoa cho lớp Faculty.
     * @param dean Trưởng khoa mới.
     */
    void setDean(const Lecturer& dean);

    /**
     * @brief Hàm khởi tạo mặc định cho lớp Faculty.
     * @details Hàm này khởi tạo các thuộc tính của lớp Faculty với giá trị mặc định.
     */
    Faculty();

    /**
     * @brief Hàm hủy của lớp Faculty.
     * @details Hàm này được gọi khi đối tượng Faculty bị hủy.
     */
    ~Faculty();
};


#endif // _FACULTY_H_