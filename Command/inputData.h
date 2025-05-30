/**
 * @file inputData.h
 * @brief Nhập dữ liệu từ người dùng
 * @details Lớp này định nghĩa các máy nhập dữ liệu cho các thực thể khác nhau như Sinh viên, Giảng viên và Khoa.
 * Các lớp con sẽ triển khai phương thức input để nhận dữ liệu từ người dùng và trả về một đối tượng BaseEntity tương ứng.
 * @note Các lớp con bao gồm StudentInput, LecturerInput và FacultyInput.
 * @note Lớp InputFactory được sử dụng để tạo các máy nhập dữ liệu dựa trên loại thực thể.
 */
#ifndef INPUT_H
#define INPUT_H
#include "../Entity/baseEntity.h"
#include "../Entity/student.h"
#include "../Entity/lecturer.h"
#include "../Entity/faculty.h"
#include "../Entity/check.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cin;
using std::cout;

/**
 * @class IDataInput
 * @brief Lớp trừu tượng đại diện cho máy nhập dữ liệu
 * @details Các lớp con sẽ triển khai phương thức input để nhận dữ liệu từ người dùng và trả về một đối tượng BaseEntity tương ứng.
 * @note Các lớp con bao gồm StudentInput, LecturerInput và FacultyInput.
 */
class IDataInput{
public:
    virtual  string getInputType() const = 0;
    virtual BaseEntity* input() = 0;
    virtual ~IDataInput() = default;
    IDataInput() = default;
};

/**
 * @class StudentInput
 * @brief Lớp đại diện cho máy nhập dữ liệu sinh viên
 * @details Lớp này kế thừa từ IDataInput và triển khai phương thức input để nhận dữ liệu từ người dùng và trả về một đối tượng Student.
 */
class StudentInput: public IDataInput{
public:
    string getInputType() const override;
    BaseEntity* input() override;
    StudentInput() = default;
    ~StudentInput() = default;
};

/**
 * @class LecturerInput
 * @brief Lớp đại diện cho máy nhập dữ liệu giảng viên
 * @details Lớp này kế thừa từ IDataInput và triển khai phương thức input để nhận dữ liệu từ người dùng và trả về một đối tượng Lecturer.
 */
class LecturerInput: public IDataInput{
public:
    string getInputType() const override;
    BaseEntity* input() override;
    LecturerInput() = default;
    ~LecturerInput() = default;
};

/**
 * @class FacultyInput
 * @brief Lớp đại diện cho máy nhập dữ liệu khoa
 * @details Lớp này kế thừa từ IDataInput và triển khai phương thức input để nhận dữ liệu từ người dùng và trả về một đối tượng Faculty.
 */
class FacultyInput: public IDataInput{
public:
    string getInputType() const override;
    BaseEntity* input() override;
    FacultyInput() = default;
    ~FacultyInput() = default;
};

/**
 * @class InputFactory
 * @brief Lớp factory để tạo các máy nhập dữ liệu dựa trên loại thực thể
 * @details Lớp này cung cấp phương thức để tạo các máy nhập dữ liệu cụ thể dựa trên chuỗi loại thực thể.
 * @note Các loại thực thể bao gồm: Student, Lecturer, Faculty.
 */
class InputFactory{
public:
    static IDataInput* create(const string& typeEntity);
};
#endif