/**
 * @file display.cpp
 * @brief Triển khai các lớp hiển thị cho cơ sở dữ liệu sinh viên, giảng viên và khoa.
 * @details Các lớp này cung cấp các phương thức để hiển thị dữ liệu từ cơ sở dữ liệu.
 */

#include "display.h"
#include <iostream>
#include <format>
using std::format;
using std::cout;

/**
 * @brief Hiển thị thông tin sinh viên.
 * @param student Đối tượng sinh viên cần hiển thị.
 * @details Hàm này in ra thông tin của sinh viên trên
 */
void StudentDatabaseDisplay::display(IDatabase* database){
    StudentDatabase* studentDTB = dynamic_cast<StudentDatabase*>(database);
    int size = studentDTB->_data.size();
    for (int i = 0; i < size; i++)
        StudentUI::print(studentDTB->_data[i]);
};

/**
 * @brief Hàm hủy của lớp StudentDatabaseDisplay.
 * @details Hàm này được gọi khi đối tượng StudentDatabaseDisplay bị hủy.
 */
StudentDatabaseDisplay::~StudentDatabaseDisplay(){

}

/**
 * @brief Hiển thị thông tin giảng viên.
 * @param lecturer Đối tượng giảng viên cần hiển thị.
 * @details Hàm này in ra thông tin của giảng viên trên
 */
void LecturerDatabaseDisplay::display(IDatabase* database){
    // dynamic_cast<LecturerDatabase*>(database);
    LecturerDatabase* lecturerDTB = dynamic_cast<LecturerDatabase*>(database);
    int size = lecturerDTB->_data.size();
    for (int i = 0; i < size; i++)
        LecturerUI::print(lecturerDTB->_data[i]);
}

/**
 * @brief Hàm hủy của lớp LecturerDatabaseDisplay.
 * @details Hàm này được gọi khi đối tượng LecturerDatabaseDisplay bị hủy.
 */
LecturerDatabaseDisplay::~LecturerDatabaseDisplay(){

}

/**
 * @brief Hiển thị thông tin khoa.
 * @param faculty Đối tượng khoa cần hiển thị.
 * @details Hàm này in ra thông tin của khoa trên
 */
void FacultyDatabaseDisplay::display(IDatabase* database){
    // dynamic_cast<FacultyDatabase*>(database);
    FacultyDatabase* facultyDTB = dynamic_cast<FacultyDatabase*>(database);
    int size = facultyDTB->_data.size();
    for (int i = 0; i < size; i++)
        FacultyUI::print(facultyDTB->_data[i]);
}

/**
 * @brief Hàm hủy của lớp FacultyDatabaseDisplay.
 * @details Hàm này được gọi khi đối tượng FacultyDatabaseDisplay bị hủy.
 */
FacultyDatabaseDisplay::~FacultyDatabaseDisplay(){

}

/**
 * @brief Tạo đối tượng hiển thị dựa trên loại cơ sở dữ liệu.
 * @param database Con trỏ đến cơ sở dữ liệu.
 * @return Con trỏ đến đối tượng hiển thị tương ứng với loại cơ sở dữ liệu.
 * @details Hàm này tạo ra một đối tượng hiển thị dựa trên loại cơ sở dữ liệu được truyền vào.
 */
IDisplay* DisplayFactory::createDisplay(IDatabase* database){

    if ("Student" == database->getDataType()){
        return new StudentDatabaseDisplay();
    } else if ("Lecturer" == database->getDataType()){
        return new LecturerDatabaseDisplay();
    } else if ("Faculty" == database->getDataType()){
        return new FacultyDatabaseDisplay();
    }
    return nullptr;
}
