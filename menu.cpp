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


MainMenu::MainMenu() {
    _options = {"Add", "Remove", "Replace", "Display", "Exit"};
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

EntityMenu::EntityMenu() {
    _options = {"Student", "Lecturer", "Faculty", "Exit"};
}

unique_ptr<Menu> MenuFactory::createMenu(const string& type) {
    if (type == "Main") {
        return make_unique<MainMenu>();
    } else if (type == "Entity") {
        return make_unique<EntityMenu>();
    } else {
        return nullptr;
    }
}