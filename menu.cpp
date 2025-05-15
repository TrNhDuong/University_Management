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
    _options = {"Add", "Search", "Remove", "Replace", "Display", "Exit"};
}

EntityMenu::EntityMenu() {
    _options = {"Student", "Lecturer", "Faculty", "Exit"};
}

SubMenu::SubMenu(){
    _options = {"Id", "Name"};
}

string MainMenu::type() const {
    return "Main Menu";
}

string EntityMenu::type() const {
    return "Entity Menu";
}

string SubMenu::type() const {
    return "Sub Menu";
}



void Menu::display(int selected) const {
    clearScreen(); // Xoá màn hình (thay thế system("cls"))

    cout << "╔══════════════════════╗\n";
    std::string title = toUpper(type());
    size_t leftPad = (22 - title.length()) / 2;
    size_t rightPad = 22 - title.length() - leftPad;
    cout << "║"
        << std::string(leftPad, ' ') << title << std::string(rightPad, ' ')
        << "║\n";
    cout << "╠══════════════════════╣\n";

    for (size_t i = 0; i < _options.size(); ++i) {
        cout << "║ ";
        if (i == selected) {
            setColor(32); // Màu xanh lá cây (dòng được chọn)
            cout << "▶ ";
        } else {
            setColor(37); // Màu trắng
            cout << "  ";
        }

        cout << _options[i];

        size_t spaceCount = 18- _options[i].length();
        for (size_t j = 0; j < spaceCount; ++j) cout << ' ';

        setColor(37); // Màu trắng
        cout << " ║\n";
    }

    setColor(0); // Đặt lại màu terminal về mặc định
    cout << "╚══════════════════════╝\n"; 
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
            return _options[selected];
        }
    }
}



unique_ptr<Menu> MenuFactory::createMenu(const string& type) {
    if (type == "Main") {
        return make_unique<MainMenu>();
    } else if (type == "Entity") {
        return make_unique<EntityMenu>();
    } else if (type == "Sub"){
        return make_unique<SubMenu>();
    } else {
        return nullptr;
    }
}