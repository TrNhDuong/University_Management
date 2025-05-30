/**
 * @file display.h
 * @brief Các lớp đại diện cho các lệnh hiển thị trong hệ thống quản lý cơ sở dữ liệu
 * @details Các lớp này bao gồm DisplayCommand, SearchCommand, AddCommand, RemoveCommand, ReplaceCommand và Notification.
 * Mỗi lớp thực hiện một chức năng cụ thể trong việc quản lý dữ liệu, bao gồm hiển thị, tìm kiếm, thêm mới, xóa và thay thế các thực thể trong cơ sở dữ liệu.
 * Các lớp này sử dụng các máy hiển thị và máy nhập dữ liệu để thực hiện các thao tác trên cơ sở dữ liệu.
 */

#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "../data.h"
#include "../Entity/student.h"
#include "../Entity/lecturer.h"
#include "../Entity/faculty.h"
#include "../Entity/baseEntity.h"
#include "../utils.h"
#include <iostream>
#include <format>
#include <string>

using std::string;
using std::format;
using std::cout;

/**
 * @class PrintMenuNewFormat
 * @brief Lớp để in menu với định dạng mới
 * @details Lớp này cung cấp phương thức để in menu với tiêu đề và loại dữ liệu cụ thể.
 */
class PrintMenuNewFormat{
    public:
        static void printMenu(vector<BaseEntity*>& data,const string& title, string type);
};

/**
 * @class IUI
 * @brief Lớp trừu tượng đại diện cho giao diện người dùng
 * @details Các lớp con sẽ triển khai phương thức print để hiển thị thông tin của các thực thể.
 */
class IUI{
public:
    virtual void print(BaseEntity*) = 0;
    virtual ~IUI() = default;
};


/**
 * @class LecturerUI
 * @brief Lớp đại diện cho giao diện người dùng hiển thị thông tin giảng viên
 * @details Lớp này kế thừa từ IUI và triển khai phương thức print để hiển thị thông tin của giảng viên.
 */
class LecturerUI: public IUI{
public:
    void print(BaseEntity* lecturer) override;
};

/**
 * @class StudentUI
 * @brief Lớp đại diện cho giao diện người dùng hiển thị thông tin sinh viên
 * @details Lớp này kế thừa từ IUI và triển khai phương thức print để hiển thị thông tin của sinh viên.
 */
class StudentUI: public IUI{
public:
    void print(BaseEntity* student) override;
};

/**
 * @class FacultyUI
 * @brief Lớp đại diện cho giao diện người dùng hiển thị thông tin khoa
 * @details Lớp này kế thừa từ IUI và triển khai phương thức print để hiển thị thông tin của khoa.
 */
class FacultyUI: public IUI{
public:
    void print(BaseEntity* student) override;
};

/**
 * @class UIFactory
 * @brief Lớp factory để tạo các giao diện người dùng dựa trên loại thực thể
 * @details Lớp này cung cấp phương thức để tạo các giao diện người dùng cụ thể dựa trên chuỗi loại thực thể.
 * @note Các loại thực thể bao gồm: Student, Lecturer, Faculty.
 * @details Lớp này sử dụng phương thức tĩnh createUI để tạo các đối tượng IUI tương ứng với loại thực thể.
 * @note Nếu loại thực thể không hợp lệ, phương thức sẽ trả về nullptr.
 */
class UIFactory {
public:
    static IUI* createUI(const string& type) {
        if (type == "Student")
            return new StudentUI();
        else if (type == "Lecturer")
            return new LecturerUI();
        else if (type == "Faculty")
            return new FacultyUI();
        return nullptr;
    }
};

/**
 * @class IDisplay
 * @brief Lớp trừu tượng đại diện cho máy hiển thị dữ liệu
 * @details Các lớp con sẽ triển khai phương thức display để hiển thị dữ liệu từ cơ sở dữ liệu.
 */
class IDisplay{
public:
    virtual void display(IDatabase* data) = 0;
    virtual ~IDisplay() = default;
};

/**
 * @class StudentDatabaseDisplay
 * @brief Lớp đại diện cho máy hiển thị dữ liệu sinh viên
 * @details Lớp này kế thừa từ IDisplay và triển khai phương thức display để hiển thị dữ liệu sinh viên từ cơ sở dữ liệu.
 */
class StudentDatabaseDisplay: public IDisplay{
public:
    void display(IDatabase* studentDTB);
    ~StudentDatabaseDisplay();
};

/**
 * @class LecturerDatabaseDisplay
 * @brief Lớp đại diện cho máy hiển thị dữ liệu giảng viên
 * @details Lớp này kế thừa từ IDisplay và triển khai phương thức display để hiển thị dữ liệu giảng viên từ cơ sở dữ liệu.
 */
class LecturerDatabaseDisplay: public IDisplay{
public:
    void display(IDatabase* lecturerDTB);
    ~LecturerDatabaseDisplay();
};

/**
 * @class FacultyDatabaseDisplay
 * @brief Lớp đại diện cho máy hiển thị dữ liệu khoa
 * @details Lớp này kế thừa từ IDisplay và triển khai phương thức display để hiển thị dữ liệu khoa từ cơ sở dữ liệu.
 */
class FacultyDatabaseDisplay: public IDisplay{
public:
    void display(IDatabase* facultyDTB);
    ~FacultyDatabaseDisplay();
};

/**
 * @class DisplayFactory
 * @brief Lớp factory để tạo các máy hiển thị dữ liệu dựa trên loại thực thể
 * @details Lớp này cung cấp phương thức để tạo các máy hiển thị dữ liệu cụ thể dựa trên chuỗi loại thực thể.
 * @note Các loại thực thể bao gồm: Student, Lecturer, Faculty.
 */
class DisplayFactory{
public:
    static IDisplay* createDisplay(const string& type);
};


#endif