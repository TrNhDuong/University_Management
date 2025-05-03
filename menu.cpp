#include "menu.h"
#include <iostream>
#include <format>
using std::cout;
using std::cin;
using std::endl;
using std::format;

// Implementation of MainMenu
MainMenu::MainMenu() {
    _options = {"Thêm", "Xóa", "Sửa", "Thay Thế", "Hiển Thị", "Thoát"};
}

void MainMenu::display() const {
    cout << "======== Main Menu ====\n";
    for (size_t i = 0; i < _options.size(); ++i) {
        cout << format("{}. {}\n", i + 1, _options[i]);
    }
    cout << "=======================\n";
}

string Menu::getChoice() const {
    string choice;
    cout << "Nhập lựa chọn: ";
    cin >> choice;
    return choice;
}

// Implementation of EntityMenu
EntityMenu::EntityMenu() {
    _options = {"Student", "Lecturer", "Faculty", "Back", "Exit"};
}

void EntityMenu::display() const {
    cout << "======== Entity Menu ====\n";
    for (size_t i = 0; i < _options.size(); ++i) {
        cout << format("{}. {}\n", i + 1, _options[i]);
    }
    cout << "=========================\n";
}


// Implementation of MenuFactory
unique_ptr<Menu> MenuFactory::createMenu(const string& type) {
    if (type == "Main") {
        return make_unique<MainMenu>();
    } else if (type == "Entity") {
        return make_unique<EntityMenu>();
    } else {
        return nullptr;
    }
}