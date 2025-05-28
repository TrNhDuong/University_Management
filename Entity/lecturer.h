/**
 * @file lecturer.h
 * @brief Định nghĩa lớp Lecturer đại diện cho giảng viên trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ BaseEntity và chứa thông tin về năm giảng dạy và học vị của giảng viên.
 * @note Bao gồm các phương thức để lấy và thiết lập năm giảng dạy, học vị, cũng như các thuộc tính cơ bản của giảng viên.
 */

#ifndef _LECTURER_H_
#define _LECTURER_H_
#include "baseEntity.h"
using std::string;

/**
 * @class Lecturer
 * @brief Lớp đại diện cho giảng viên trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ BaseEntity và chứa thông tin về năm giảng dạy và học vị của giảng viên.
 * @note Bao gồm các phương thức để lấy và thiết lập năm giảng dạy, học vị, cũng như các thuộc tính cơ bản của giảng viên.
 */
class Lecturer:public BaseEntity{
private:
    int _instructYear;
    string _academicDegree;
public:
    string getType();
    int getInstructYear() const;
    string getDegree() const;
    void setInstructYear(const int& year);
    void setDeg(const string& deg);
    Lecturer();
    ~Lecturer();
};



#endif