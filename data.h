/**
 * @file data.h
 * @brief Khai báo các lớp cơ sở dữ liệu cho sinh viên, giảng viên và khoa.
 * @details Các lớp này quản lý danh sách sinh viên, giảng viên và khoa trong hệ thống.
 */

#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
<<<<<<< HEAD
#include "student.h"
#include "lecturer.h"
#include "faculty.h"
#include "baseEntity.h"
=======
#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"
>>>>>>> NDuong_branch
#include <exception>
#include <string>
#include <fstream>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::fstream;

class IDatabase{
public:
    /**
     * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
     * @return Kiểu dữ liệu của cơ sở dữ liệu.
     * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
     */
    virtual string getDataType() const = 0;

    virtual ~IDatabase() = default;
};

/**
 * @class StudentDatabase
 * @brief Lớp cơ sở dữ liệu cho sinh viên.
 * @details Lớp này quản lý danh sách sinh viên trong hệ thống.
 */
class StudentDatabase: public IDatabase{
private:
    /**
     * @brief Danh sách sinh viên.
     */
    vector<Student> _data;

    /**
     * @brief Hàm khởi tạo mặc định.
     */
    StudentDatabase() = default; 

    /**
     * @brief Hàm hủy.
     */
    ~StudentDatabase() override = default;

    /**
     * @brief Hàm sao chép và gán không được phép.
     */
    StudentDatabase(const StudentDatabase&) = delete;

    /**
     * @brief Hàm gán không được phép.
     */
    Student& operator = (const StudentDatabase&) = delete;
public:
    /**
     * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
     * @return Kiểu dữ liệu của cơ sở dữ liệu.
     * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
     */
    string getDataType() const override;

    /**
     * @brief Lấy thể hiện duy nhất của lớp StudentDatabase.
     * @return Tham chiếu đến thể hiện duy nhất của lớp StudentDatabase.
     */
    static StudentDatabase& getInstance(){
        static StudentDatabase instance;
        return instance;
    }
    int getSize() const;
    Student* getData(const int&);
    friend class StudentReadData;
};

class LecturerDatabase: public IDatabase{
private:
    /**
     * @brief Danh sách giảng viên.
     */
    vector<Lecturer> _data;
    /**
     * @brief Hàm khởi tạo mặc định.
     */
    LecturerDatabase() = default; 
    /**
     * @brief Hàm hủy.
     */
    ~LecturerDatabase() = default;
    /**
     * @brief Hàm sao chép và gán không được phép.
     */
    LecturerDatabase(const LecturerDatabase&) = delete;
    /**
     * @brief Hàm gán không được phép.
     */
    LecturerDatabase& operator = (const LecturerDatabase&) = delete;
public:
    /**
     * @brief Lấy thể hiện duy nhất của lớp LecturerDatabase.
     * @return Tham chiếu đến thể hiện duy nhất của lớp LecturerDatabase.
     */
    static LecturerDatabase& getInstance(){
        /**
         * @brief Thể hiện duy nhất của lớp LecturerDatabase.
         */
        static LecturerDatabase instance;
        return instance;
    }

    /**
     * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
     * @return Kiểu dữ liệu của cơ sở dữ liệu.
     * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
     */
    string getDataType() const override;
    Lecturer* getData(const int& index);
    int getSize() const;
    friend class LecturerReadData;
};

/**
 * @class FacultyDatabase
 * @brief Lớp cơ sở dữ liệu cho khoa.
 * @details Lớp này quản lý danh sách khoa trong hệ thống.
 */
class FacultyDatabase: public IDatabase{
private:
    /**
     * @brief Danh sách khoa.
     */
    vector<Faculty> _data;

    /**
     * @brief Hàm khởi tạo mặc định.
     */
    FacultyDatabase() = default;
    /**
     * @brief Hàm hủy.
     */
    ~FacultyDatabase() = default;
    /**
     * @brief Hàm sao chép và gán không được phép.
     */
    FacultyDatabase(const FacultyDatabase&) = delete;
    /**
     * @brief Hàm gán không được phép.
     */
    FacultyDatabase& operator = (const FacultyDatabase&) = delete;
public:
    /**
     * @brief Lấy thể hiện duy nhất của lớp FacultyDatabase.
     * @return Tham chiếu đến thể hiện duy nhất của lớp FacultyDatabase.
     */
    static FacultyDatabase& getInstance(){
        /**
         * @brief Thể hiện duy nhất của lớp FacultyDatabase.
         */
        static FacultyDatabase instance;
        return instance;
    }
    /**
     * @brief Lấy kích thước của cơ sở dữ liệu.
     * @return Kích thước của cơ sở dữ liệu.
     * @details Hàm này trả về số lượng đối tượng trong cơ sở dữ liệu.
     */
    string getDataType() const override;
    int getSize() const;
    Faculty* getData(const int& index);
    friend class FacultyReadData;
};


/**
 * @class StudentGetData
 * @brief Lớp nhập dữ liệu cho sinh viên.
 * @details Lớp này cung cấp các phương thức để nhập dữ liệu cho sinh viên từ bàn phím.
 */
class StudentGetData{
    public:
        /**
         * @brief Nhập dữ liệu cho sinh viên từ bàn phím.
         * @param student Đối tượng sinh viên cần nhập dữ liệu.
         * @details Hàm này yêu cầu người dùng nhập thông tin cho sinh viên và lưu vào đối tượng sinh viên.
         */
        static void InputData(Student& student);
    };

/**
 * @class LecturerGetData
 * @brief Lớp nhập dữ liệu cho giảng viên.
 * @details Lớp này cung cấp các phương thức để nhập dữ liệu cho giảng viên từ bàn phím.
 */
class LecturerGetData{
    public:
        /**
         * @brief Nhập dữ liệu cho giảng viên từ bàn phím.
         * @param lecturer Đối tượng giảng viên cần nhập dữ liệu.
         * @details Hàm này yêu cầu người dùng nhập thông tin cho giảng viên và lưu vào đối tượng giảng viên.
         */
        static void InputData(Lecturer& lecturer);
    };

/**
 * @class FacultyGetData
 * @brief Lớp nhập dữ liệu cho khoa.
 * @details Lớp này cung cấp các phương thức để nhập dữ liệu cho khoa từ bàn phím.
 */
class FacultyGetData{
    public:
        /**
         * @brief Nhập dữ liệu cho khoa từ bàn phím.
         * @param faculty Đối tượng khoa cần nhập dữ liệu.
         * @details Hàm này yêu cầu người dùng nhập thông tin cho khoa và lưu vào đối tượng khoa.
         */
        static void InputData(Faculty& faculty);
};    

#endif // _DATA_H_
/**
 * @brief Kết thúc tệp data.h
 * @details Tệp này chứa các lớp cơ sở dữ liệu cho sinh viên, giảng viên và khoa,
 * cũng như các lớp nhập dữ liệu từ bàn phím.
 */