/**
 * @file faculty.h
 * @brief Định nghĩa lớp Faculty đại diện cho khoa trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ BaseEntity và chứa thông tin về trưởng khoa (dean).
 * @note Bao gồm các phương thức để lấy và thiết lập trưởng khoa, cũng như các thuộc tính cơ bản của khoa.
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
 * @brief Lớp đại diện cho khoa trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ BaseEntity và chứa thông tin về trưởng khoa (dean).
 * @note Bao gồm các phương thức để lấy và thiết lập trưởng khoa, cũng như các thuộc tính cơ bản của khoa.
 */
class Faculty : public BaseEntity{
protected:
    Lecturer _dean; // ID cua Truong khoa
public:
    string getType() const;
    Lecturer getDean() const;
    void setDean(const Lecturer& dean);

    Faculty();
    ~Faculty();
};


#endif