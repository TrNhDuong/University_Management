/**
 * @file lecturer.h
 * @brief Khai báo lớp Lecturer và các phương thức liên quan đến giảng viên.
 * @details Lớp này bao gồm các thuộc tính và phương thức để quản lý thông tin của giảng viên.
 */
#ifndef _LECTURER_H_
#define _LECTURER_H_
#include "baseEntity.h"
using std::string;

/**
 * @class Lecturer
 * @brief Lớp đại diện cho giảng viên.
 * @details Lớp này bao gồm các thuộc tính và phương thức để quản lý thông tin của giảng viên.
 */
class Lecturer:public BaseEntity{
private:
    /**
     * @brief Năm giảng dạy của giảng viên.
     * @details Năm này được sử dụng để xác định thời gian giảng dạy của giảng viên.
     */
    int _instructYear;

    /**
     * @brief Học vị của giảng viên.
     * @details Học vị này được sử dụng để xác định trình độ học vấn của giảng viên.
     */
    string _academicDegree;
public:

    /**
     * @brief Hàm lấy loại dữ liệu của lớp Lecturer.
     * @return Kiểu dữ liệu của lớp Lecturer.
     */
    string getType();

    /**
     * @brief Hàm lấy năm giảng dạy của lớp Lecturer.
     * @return Năm giảng dạy của lớp Lecturer.
     */
    int getInstructYear() const;

    /**
     * @brief Hàm lấy học vị của lớp Lecturer.
     * @return Học vị của lớp Lecturer.
     */
    string getDegree() const;

    /**
     * @brief Hàm đặt năm giảng dạy cho lớp Lecturer.
     * @param year Năm giảng dạy mới.
     */
    void setInstructYear(const int& year);

    /**
     * @brief Hàm đặt học vị cho lớp Lecturer.
     * @param deg Học vị mới.
     */
    void setDeg(const string& deg);

    /**
     * @brief Hàm khởi tạo mặc định cho lớp Lecturer.
     * @details Hàm này khởi tạo các thuộc tính của lớp Lecturer với giá trị mặc định.
     */
    Lecturer();

    /**
     * @brief Hàm hủy của lớp Lecturer.
     * @details Hàm này được gọi khi đối tượng Lecturer bị hủy.
     */
    ~Lecturer();
};

/**
 * @class LecturerUI
 * @brief Lớp hiển thị thông tin giảng viên.
 * @details Lớp này cung cấp các phương thức để hiển thị thông tin của giảng viên.
 */
class LecturerUI{
public:

    /**
     * @brief Hiển thị thông tin giảng viên.
     * @param lecturer Đối tượng giảng viên cần hiển thị.
     * @details Hàm này in ra thông tin của giảng viên trên */
    static void print(const Lecturer& lecturer);
};


#endif