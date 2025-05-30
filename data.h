/**
 * @file data.h
 * @brief Định nghĩa các lớp quản lý cơ sở dữ liệu cho sinh viên, giảng viên và khoa
 * @details Các lớp này sử dụng mẫu thiết kế Singleton để đảm bảo chỉ có một thể hiện duy nhất của mỗi cơ sở dữ liệu.
 * @note Bao gồm các phương thức để thêm, xóa, thay thế và truy xuất dữ liệu từ cơ sở dữ liệu.
 * @note Các lớp này kế thừa từ IDatabase, cung cấp các phương thức trừu tượng để tương tác với dữ liệu.
 */
#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"
#include <exception>
#include <string>
#include <fstream>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::fstream;

/**
 * @class IDatabase
 * @brief Lớp trừu tượng đại diện cho cơ sở dữ liệu
 * @details Lớp này định nghĩa các phương thức trừu tượng để tương tác với cơ sở dữ liệu, bao gồm thêm, xóa, thay thế và truy xuất dữ liệu.
 * @note Các lớp con sẽ kế thừa từ IDatabase và triển khai các phương thức cụ thể cho từng loại cơ sở dữ liệu.
 */
#pragma region IDatabase declaration
class IDatabase{
public:
    virtual string getDataType() const = 0;
    virtual int getSize() const = 0;

    virtual void Add(BaseEntity*) = 0;
    virtual bool Remove(BaseEntity*) = 0;
    virtual bool Remove(const string& id) = 0;
    virtual int find(const string& id) const = 0;
    virtual bool Replace(BaseEntity* des, BaseEntity* scr) = 0;
    virtual BaseEntity* getData(const int&) = 0;

    virtual ~IDatabase() = default;
};

#pragma endregion

//CRTP (Curiously Recurring Template Pattern) + IDatabase + Template ->Need Optimization

/**
 * @class StudentDatabase
 * @brief Lớp đại diện cho cơ sở dữ liệu sinh viên
 * @details Lớp này kế thừa từ IDatabase và sử dụng mẫu thiết kế Singleton để đảm bảo chỉ có một thể hiện duy nhất của cơ sở dữ liệu sinh viên.
 * @note Cung cấp các phương thức để thêm, xóa, thay thế và truy xuất dữ liệu sinh viên.
 * @note Lớp này sử dụng vector để lưu trữ dữ liệu sinh viên và cung cấp các phương thức để tương tác với dữ liệu.
 * @note Các phương thức này bao gồm getDataType, getSize, find, Add, Remove, Replace và getData.
 * @note Lớp này cũng định nghĩa một phương thức tĩnh getInstance để lấy thể hiện duy nhất của cơ sở dữ liệu sinh viên.
 */
#pragma region StudentDatabase declaration
class StudentDatabase: public IDatabase{
private:
    vector<Student> _data;
    StudentDatabase() = default; 
    ~StudentDatabase() override = default;
    StudentDatabase(const StudentDatabase&) = delete;
    Student& operator = (const StudentDatabase&) = delete;
public:
    static StudentDatabase& getInstance(){
        static StudentDatabase instance;
        return instance;
    }

    string getDataType() const override;
    int getSize() const override;
    int find(const string& id) const override;

    void Add(BaseEntity* obj) override;
    bool Remove(const string& ID) override; //return true if remove succesfully, return false if ID not found
    bool Remove(BaseEntity* obj) override; ///return true if remove succesfully, return false if ID not found
    bool Replace(BaseEntity* des, BaseEntity* src) override; //return true if remove succesfully, return false if des not found

    BaseEntity* getData(const int& index) override;
    
    friend class StudentReadData;
};
#pragma endregion



#pragma region LecturerDatabase declaration
/**
 * @class LecturerDatabase
 * @brief Lớp đại diện cho cơ sở dữ liệu giảng viên
 * @details Lớp này kế thừa từ IDatabase và sử dụng mẫu thiết kế Singleton để đảm bảo chỉ có một thể hiện duy nhất của cơ sở dữ liệu giảng viên.
 * @note Cung cấp các phương thức để thêm, xóa, thay thế và truy xuất dữ liệu giảng viên.
 * @note Lớp này sử dụng vector để lưu trữ dữ liệu giảng viên và cung cấp các phương thức để tương tác với dữ liệu.
 * @note Các phương thức này bao gồm getDataType, getSize, find, Add, Remove, Replace và getData.
 * @note Lớp này cũng định nghĩa một phương thức tĩnh getInstance để lấy thể hiện duy nhất của cơ sở dữ liệu giảng viên.
 */
class LecturerDatabase: public IDatabase{
private:
    vector<Lecturer> _data;
    LecturerDatabase() = default; 
    ~LecturerDatabase() = default;
    LecturerDatabase(const LecturerDatabase&) = delete;
    LecturerDatabase& operator = (const LecturerDatabase&) = delete;
public:
    static LecturerDatabase& getInstance(){
        static LecturerDatabase instance;
        return instance;
    }
    string getDataType() const override;
    int getSize() const override;
    int find(const string& id) const; //-1 if not exists

    void Add(BaseEntity* obj) override;
    bool Remove(const string& ID) override;
    bool Remove(BaseEntity* obj) override;
    bool Replace(BaseEntity* des, BaseEntity* src) override;

    BaseEntity* getData(const int& index) override;
    friend class LecturerReadData;
};

#pragma endregion


#pragma region FacultyDatabase declaration
/**
 * @class FacultyDatabase
 * @brief Lớp đại diện cho cơ sở dữ liệu khoa
 * @details Lớp này kế thừa từ IDatabase và sử dụng mẫu thiết kế Singleton để đảm bảo chỉ có một thể hiện duy nhất của cơ sở dữ liệu khoa.
 * @note Cung cấp các phương thức để thêm, xóa, thay thế và truy xuất dữ liệu khoa.
 * @note Lớp này sử dụng vector để lưu trữ dữ liệu khoa và cung cấp các phương thức để tương tác với dữ liệu.
 * @note Các phương thức này bao gồm getDataType, getSize, find, Add, Remove, Replace và getData.
 * @note Lớp này cũng định nghĩa một phương thức tĩnh getInstance để lấy thể hiện duy nhất của cơ sở dữ liệu khoa.
 */
class FacultyDatabase: public IDatabase{
private:
    vector<Faculty> _data;
    FacultyDatabase() = default;
    ~FacultyDatabase() = default;
    FacultyDatabase(const FacultyDatabase&) = delete;
    FacultyDatabase& operator = (const FacultyDatabase&) = delete;
public:
    static FacultyDatabase& getInstance(){
        static FacultyDatabase instance;
        return instance;
    }

    string getDataType() const override;
    int getSize() const override;
    int find(const string& id) const override;

    void Add(BaseEntity* object) override;
    bool Remove(const string& ID) override;
    bool Remove(BaseEntity* obj) override;
    bool Replace(BaseEntity* des, BaseEntity* src) override;

    BaseEntity* getData(const int& index) override;
    
    friend class FacultyReadData;
};

#pragma endregion

#endif