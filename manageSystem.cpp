/**
 * @file manageSystem.cpp
 * @brief Triển khai lớp UniversitySystem cho hệ thống quản lý sinh viên.
 * @details
 * Lớp này chứa các phương thức để khởi động hệ thống quản lý sinh viên, bao gồm việc đọc dữ liệu từ file,
 * tạo các menu và thực hiện các lệnh tương ứng với lựa chọn của người dùng.
 */

#include "menu.h"
#include "manageSystem.h"
#include "faculty.h"
#include "display.h"
#include "data.h"
#include "command.h"
#include <map>

/**
 * @brief Hàm khởi động hệ thống quản lý sinh viên.
 * @details Hàm này sẽ đọc dữ liệu từ các file, tạo các menu và thực hiện các lệnh tương ứng với lựa chọn của người dùng.
 * @return Không có giá trị trả về.
 * @note Hàm này sử dụng các đối tượng MenuFactory, StudentReadData, LecturerReadData và FacultyReadData để thực hiện các tác vụ.
 */
void UniversitySystem::Run() {
    studentDB = &StudentDatabase::getInstance();
    lecturerDB = &LecturerDatabase::getInstance();
    facultyDB = &FacultyDatabase::getInstance();
    StudentReadData& studentReader = StudentReadData::getInstance();
    LecturerReadData& lecturerReader = LecturerReadData::getInstance();
    FacultyReadData& facultyReader = FacultyReadData::getInstance();
    studentReader.readData("Data/StudentData.txt");
    lecturerReader.readData("Data/LecturerData.txt");
    facultyReader.readData("Data/FacultyData.txt");

    MenuFactory menuFactory;
    unique_ptr<Menu> mainMenu = menuFactory.createMenu("Main");
    unique_ptr<Menu> entityMenu = menuFactory.createMenu("Entity");

    // Khởi tạo các đối tượng lệnh
    AddCommand addCommand(entityMenu.get(), studentDB, lecturerDB, facultyDB);
    RemoveCommand removeCommand(entityMenu.get(), studentDB, lecturerDB, facultyDB);
    ReplaceCommand replaceCommand(entityMenu.get(), studentDB, lecturerDB, facultyDB);
    DisplayCommand displayCommand(entityMenu.get(), studentDB, lecturerDB, facultyDB);
    ExitCommand exitCommand;

    // Ánh xạ các lựa chọn với các lệnh
    std::map<string, Command*> commandMap = {
        {"1", &addCommand},
        {"2", &removeCommand},
        {"3", &replaceCommand},
        {"4", &displayCommand},
        {"5", &exitCommand}
    };

    // Vòng lặp chính
    while (true) {
        mainMenu->display();
        string choice = mainMenu->getChoice();

        auto it = commandMap.find(choice);
        if (it != commandMap.end()) {
            it->second->execute(); // Thực thi lệnh tương ứng
        } else {
            std::cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
        }
    }
}