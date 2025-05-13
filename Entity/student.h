/**
 * @file student.h
 * @brief Khai báo lớp Student và các phương thức liên quan đến sinh viên.
 * @details Lớp này bao gồm các thuộc tính và phương thức để quản lý thông tin của sinh viên.
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "baseEntity.h"

/**
 * @class Student
 * @brief Lớp đại diện cho sinh viên.
 * @details Lớp này bao gồm các thuộc tính và phương thức để quản lý thông tin của sinh viên.
 */
class Student: public BaseEntity{
private:
    /**
     * @brief Năm nhập học của sinh viên.
     * @details Năm này được sử dụng để xác định thời gian học tập của sinh viên.
     */
    int _enrollYear;

    /**
     * @brief Điểm trung bình của sinh viên.
     * @details Điểm này được sử dụng để đánh giá kết quả học tập của sinh viên.
     */
    float _gpa;

    /**
     * @brief Số tín chỉ đã hoàn thành của sinh viên.
     * @details Số tín chỉ này được sử dụng để xác định tiến độ học tập của sinh viên.
     */
    int _completedCredit;
public:
    /**
     * @brief Hàm lấy loại dữ liệu của lớp Student.
     * @return Kiểu dữ liệu của lớp Student.
     */
    string getType();

    /**
     * @brief Hàm đặt điểm trung bình cho lớp Student.
     * @param gpa Điểm trung bình mới.
     */
    void setGPA(const float& gpa);

    /**
     * @brief Hàm đặt số tín chỉ đã hoàn thành cho lớp Student.
     * @param credit Số tín chỉ mới.
     */
    void setCredit(const int& credit);

    /**
     * @brief Hàm đặt năm nhập học cho lớp Student.
     * @param year Năm nhập học mới.
     */
    void setEnrollYear(const int& year);

    /**
     * @brief Hàm lấy điểm trung bình của lớp Student.
     * @return Điểm trung bình của lớp Student.
     */
    float getGPA() const;

    /**
     * @brief Hàm lấy số tín chỉ đã hoàn thành của lớp Student.
     * @return Số tín chỉ đã hoàn thành của lớp Student.
     */
    int getCompletedCredit() const;

    /**
     * @brief Hàm lấy năm nhập học của lớp Student.
     * @return Năm nhập học của lớp Student.
     */
    int getEnrollYear() const;
    
    /**
     * @brief Hàm khởi tạo mặc định cho lớp Student.
     * @details Hàm này khởi tạo các thuộc tính của lớp Student với giá trị mặc định.
     */
    Student();

    /**
     * @brief Hàm hủy của lớp Student.
     * @details Hàm này được gọi khi đối tượng Student bị hủy.
     */
    ~Student();
};

#endif
