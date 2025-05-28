/**
 * @file student.h
 * @brief Định nghĩa lớp Student đại diện cho sinh viên trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ BaseEntity và chứa thông tin về năm nhập học, GPA và tín chỉ đã hoàn thành của sinh viên.
 * @note Bao gồm các phương thức để lấy và thiết lập năm nhập học, GPA, tín chỉ đã hoàn thành, cũng như các thuộc tính cơ bản của sinh viên.
 */
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "baseEntity.h"

/**
 * @class Student
 * @brief Lớp đại diện cho sinh viên trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ BaseEntity và chứa thông tin về năm nhập học, GPA và tín chỉ đã hoàn thành của sinh viên.
 * @note Bao gồm các phương thức để lấy và thiết lập năm nhập học, GPA, tín chỉ đã hoàn thành, cũng như các thuộc tính cơ bản của sinh viên.
 */
class Student: public BaseEntity{
private:
    int _enrollYear;
    float _gpa;
    int _completedCredit;
public:
    string getType();
    void setGPA(const float& gpa);
    void setCredit(const int& credit);
    void setEnrollYear(const int& year);
    float getGPA() const;
    int getCompletedCredit() const;
    int getEnrollYear() const;
    
    Student();
    ~Student();
};

#endif