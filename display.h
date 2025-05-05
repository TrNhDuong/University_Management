/**
 * @file display.h
 * @brief Khai báo các lớp hiển thị cho cơ sở dữ liệu sinh viên, giảng viên và khoa.
 * @details Các lớp này cung cấp các phương thức để hiển thị thông tin của sinh viên, giảng viên và khoa.
 */

#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "data.h"

/**
 * @class IDisplay
 * @brief Lớp cơ sở cho các lớp hiển thị.
 * @details Các lớp này cung cấp các phương thức để hiển thị thông tin của sinh viên, giảng viên và khoa.
 */
class IDisplay{
public:
    /**
     * @brief Hiển thị thông tin của cơ sở dữ liệu.
     * @param data Con trỏ đến cơ sở dữ liệu cần hiển thị.
     * @details Hàm này sẽ được triển khai trong các lớp con để hiển thị thông tin cụ thể.
     */
    virtual void display(IDatabase* data) = 0;

    /**
     * @brief Hàm hủy ảo.
     * @details Hàm này được gọi khi đối tượng IDisplay bị hủy.
     */
    virtual ~IDisplay() = default;
};

/**
 * @class StudentDatabaseDisplay
 * @brief Lớp hiển thị thông tin sinh viên.
 * @details Lớp này cung cấp các phương thức để hiển thị thông tin của sinh viên.
 */
class StudentDatabaseDisplay: public IDisplay{
public:
    /**
     * @brief Hiển thị thông tin sinh viên.
     * @param studentDTB Con trỏ đến cơ sở dữ liệu sinh viên cần hiển thị.
     * @details Hàm này in ra thông tin của sinh viên trên
     */
    void display(IDatabase* studentDTB);
    /**
     * @brief Hàm hủy của lớp StudentDatabaseDisplay.
     * @details Hàm này được gọi khi đối tượng StudentDatabaseDisplay bị hủy.
     */
    ~StudentDatabaseDisplay();
};

/**
 * @class LecturerDatabaseDisplay
 * @brief Lớp hiển thị thông tin giảng viên.
 * @details Lớp này cung cấp các phương thức để hiển thị thông tin của giảng viên.
 */
class LecturerDatabaseDisplay: public IDisplay{
public:
    /**
     * @brief Hiển thị thông tin giảng viên.
     * @param lecturerDTB Con trỏ đến cơ sở dữ liệu giảng viên cần hiển thị.
     * @details Hàm này in ra thông tin của giảng viên trên
     */
    void display(IDatabase* lecturerDTB);
    /**
     * @brief Hàm hủy của lớp LecturerDatabaseDisplay.
     * @details Hàm này được gọi khi đối tượng LecturerDatabaseDisplay bị hủy.
     */
    ~LecturerDatabaseDisplay();
};

/**
 * @class FacultyDatabaseDisplay
 * @brief Lớp hiển thị thông tin khoa.
 * @details Lớp này cung cấp các phương thức để hiển thị thông tin của khoa.
 */
class FacultyDatabaseDisplay: public IDisplay{
public:
    /**
     * @brief Hiển thị thông tin khoa.
     * @param facultyDTB Con trỏ đến cơ sở dữ liệu khoa cần hiển thị.
     * @details Hàm này in ra thông tin của khoa trên
     */
    void display(IDatabase* facultyDTB);
    /**
     * @brief Hàm hủy của lớp FacultyDatabaseDisplay.
     * @details Hàm này được gọi khi đối tượng FacultyDatabaseDisplay bị hủy.
     */
    ~FacultyDatabaseDisplay();
};

/**
 * @class DisplayFactory
 * @brief Lớp factory để tạo đối tượng hiển thị.
 * @details Lớp này cung cấp phương thức để tạo đối tượng hiển thị dựa trên loại cơ sở dữ liệu.
 */
class DisplayFactory{
public:
    /**
     * @brief Tạo đối tượng hiển thị dựa trên loại cơ sở dữ liệu.
     * @param database Con trỏ đến cơ sở dữ liệu.
     * @return Con trỏ đến đối tượng hiển thị tương ứng với loại cơ sở dữ liệu.
     * @details Hàm này tạo ra một đối tượng hiển thị dựa trên loại cơ sở dữ liệu được truyền vào.
     */
    static IDisplay* createDisplay(IDatabase* database);
};
#endif