/**
 * @file menu.cpp
 * @brief Triển khai các lớp menu cho hệ thống quản lý sinh viên.
 * @details Các lớp này bao gồm lớp Menu, MainMenu, EntityMenu và MenuFactory.
 */

#include "menu.h"
#include <iostream>
#include <format>
using std::cout;
using std::cin;
using std::endl;
using std::format;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Menu.
 * @details Hàm này khởi tạo danh sách các tùy chọn trong menu.
 */
MainMenu::MainMenu() {
    _options = {"Thêm", "Xóa", "Thay Thế", "Hiển Thị", "Thoát"};
}

/**
 * @brief Hàm hiển thị menu chính.
 * @details Hàm này in ra danh sách các tùy chọn trong menu chính.
 */
void MainMenu::display() const {
    cout << "======== Main Menu ====\n";
    for (size_t i = 0; i < _options.size(); ++i) {
        cout << format("{}. {}\n", i + 1, _options[i]);
    }
    cout << "=======================\n";
}

/**
 * @brief Hàm lấy lựa chọn của người dùng.
 * @return Lựa chọn của người dùng dưới dạng chuỗi.
 * @details Hàm này yêu cầu người dùng nhập lựa chọn và trả về lựa chọn đó.
 */
string Menu::getChoice() const {
    string choice;
    cout << "Nhập lựa chọn: ";
    cin >> choice;
    return choice;
}

/**
 * @brief Hàm khởi tạo mặc định cho lớp EntityMenu.
 * @details Hàm này khởi tạo danh sách các tùy chọn trong menu thực thể.
 */
EntityMenu::EntityMenu() {
    _options = {"Student", "Lecturer", "Faculty", "Exit"};
}

/**
 * @brief Hàm hiển thị menu thực thể.
 * @details Hàm này in ra danh sách các tùy chọn trong menu thực thể.
 */
void EntityMenu::display() const {
    cout << "======== Entity Menu ====\n";
    for (size_t i = 0; i < _options.size(); ++i) {
        cout << format("{}. {}\n", i + 1, _options[i]);
    }
    cout << "=========================\n";
}


/**
 * @brief Tạo một menu dựa trên loại menu được yêu cầu.
 * @param type Loại menu cần tạo.
 * @return Con trỏ thông minh đến đối tượng menu được tạo.
 * @details Hàm này sẽ tạo một menu mới dựa trên loại menu được yêu cầu.
 */
unique_ptr<Menu> MenuFactory::createMenu(const string& type) {
    if (type == "Main") {
        return make_unique<MainMenu>();
    } else if (type == "Entity") {
        return make_unique<EntityMenu>();
    } else {
        return nullptr;
    }
}