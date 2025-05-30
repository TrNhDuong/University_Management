/**
 * @file exit.h
 * @brief Lưu trữ dữ liệu vào file
 * 
 */

#ifndef SAVE_DATA_H
#define SAVE_DATA_H
#include "../data.h"
#include <fstream>
#include <map>
using std::map;

/**
 * @class ISaveData
 * @brief Lớp trừu tượng đại diện cho máy lưu dữ liệu
 * @details Các lớp con sẽ triển khai phương thức execute để lưu dữ liệu vào cơ sở dữ liệu.
 */
class ISaveData{
protected:
    IDatabase* database;
public:
    ISaveData() = default;
    virtual ~ISaveData() = default;

    virtual void execute() = 0;
};

/**
 * @class SaveStudentData
 * @brief Lớp đại diện cho máy lưu dữ liệu sinh viên
 * @details Lớp này kế thừa từ ISaveData và triển khai phương thức execute để lưu dữ liệu sinh viên vào cơ sở dữ liệu.
 * @note Lớp này sử dụng cơ sở dữ liệu đã được cung cấp để lưu trữ dữ liệu sinh viên.
 * @note Dữ liệu sẽ được lưu vào file "student.txt" trong thư mục hiện tại.
 * @note Dữ liệu sẽ được lưu theo định dạng: ID, Name, Birth, Mail, Class.
 * @note Nếu file không tồn tại, nó sẽ được tạo mới. Nếu đã tồn tại, dữ liệu sẽ được ghi đè.
 *
 * 
 */
class SaveStudentData: public ISaveData{
public:
    SaveStudentData() = default;
    SaveStudentData(IDatabase* db){
        database = db;
    }
    void execute() override;
};

/**
 * @class SaveLecturerData
 * @brief Lớp đại diện cho máy lưu dữ liệu giảng viên
 * @details Lớp này kế thừa từ ISaveData và triển khai phương thức execute để lưu dữ liệu giảng viên vào cơ sở dữ liệu.
 */
class SaveLecturerData: public ISaveData{
public:
    SaveLecturerData() = default;
    SaveLecturerData(IDatabase* db){
        database = db;
    }
    void execute() override;
};

/**
 * @class SaveFacultyData
 * @brief Lớp đại diện cho máy lưu dữ liệu khoa
 * @details Lớp này kế thừa từ ISaveData và triển khai phương thức execute để lưu dữ liệu khoa vào cơ sở dữ liệu.
 */
class SaveFacultyData: public ISaveData{
public:
    SaveFacultyData() = default;
    SaveFacultyData(IDatabase* db){
        database = db;
    }
    void execute() override;
};

/**
 * @class SaveDataFactory
 * @brief Lớp factory để tạo các máy lưu dữ liệu dựa trên loại thực thể
 * @details Lớp này cung cấp phương thức create để tạo các máy lưu dữ liệu tương ứng với loại thực thể.
 */
class SaveDataFactory{
public:
    static ISaveData* create(const string& type, map<string, IDatabase*> DB);
};
#endif