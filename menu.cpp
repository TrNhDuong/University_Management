/**
 * @file menu.cpp
 * @brief Triển khai các lớp menu cho hệ thống quản lý sinh viên.
 * @details Các lớp này bao gồm lớp Menu, MainMenu, EntityMenu và MenuFactory.
 */

#include "menu.h"
#include <iostream>
#include <format>
#include "utils.h"

using std::cout;
using std::cin;
using std::endl;
using std::format;
using std::to_string;


/**
 * @brief Hàm khởi tạo mặc định cho lớp Menu.
 * @details Hàm này khởi tạo danh sách các tùy chọn trong menu.
 */
MainMenu::MainMenu() {
    _options = {"Thêm", "Xóa", "Thay Thế", "Hiển Thị", "Thoát"};
}

string MainMenu::type() const {
    return "Main Menu";
}

string EntityMenu::type() const {
    return "Entity Menu";
}

void Menu::display(int selected) const {
    clearScreen(); // Thay thế system("cls")
    cout << "========" << type() << "========\n";
    for (size_t i = 0; i < _options.size(); ++i) {
        if (i == selected) {
            setColor(32); // Màu xanh lá (ANSI)
        } else {
            setColor(37); // Màu trắng (ANSI)
        }
        cout << "       " << _options[i] << "\n";
    }
    setColor(0); // Đặt lại màu mặc định
    cout << "=========================\n";
}

/**
 * @brief Hàm lấy lựa chọn của người dùng.
 * @return Lựa chọn của người dùng dưới dạng chuỗi.
 * @details Hàm này yêu cầu người dùng nhập lựa chọn và trả về lựa chọn đó.
 */
string Menu::getChoice() const {
    int selected = 0;
    char key;
    int  menuSize = _options.size();

    while (true) {
        display(selected);

        key = getch();
        if (key == '\033') { // Phím mũi tên
            getch(); // Bỏ qua ký tự '['
            key = getch();
            if (key == 'A') selected = (selected - 1 + menuSize) % menuSize; // Lên
            else if (key == 'B') selected = (selected + 1) % menuSize;       // Xuống
        } else if (key == '\n') { // Enter
            return to_string(selected + 1);
        }
    }
}

/**
 * @brief Hàm khởi tạo mặc định cho lớp EntityMenu.
 * @details Hàm này khởi tạo danh sách các tùy chọn trong menu thực thể.
 */
EntityMenu::EntityMenu() {
    _options = {"Student", "Lecturer", "Faculty", "Exit"};
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