/**
 * @file menu.h
 * @brief Định nghĩa các lớp Menu cho hệ thống quản lý cơ sở dữ liệu
 * @details Các lớp này định nghĩa các menu khác nhau cho hệ thống, bao gồm MainMenu, EntityMenu và SubMenu.
 * @note Bao gồm các phương thức để hiển thị menu, lấy lựa chọn của người dùng và tạo các menu khác nhau thông qua MenuFactory.
 * @note Các lớp này sử dụng vector để lưu trữ các tùy chọn menu và cung cấp các phương thức để hiển thị và xử lý lựa chọn của người dùng.
 * @note Các lớp này kế thừa từ lớp Menu trừu tượng, cung cấp các phương thức cụ thể cho từng loại menu.
 * @note MenuFactory cung cấp phương thức tĩnh để tạo các menu dựa trên loại menu được yêu cầu.
 */

#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;

/**
 * @class Menu
 * @brief Lớp trừu tượng đại diện cho menu trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này định nghĩa các phương thức để hiển thị menu, lấy lựa chọn của người dùng và cung cấp các phương thức trừu tượng để các lớp con triển khai.
 * @note Các lớp con sẽ kế thừa từ Menu và triển khai phương thức type để xác định loại menu cụ thể.
 * @note Lớp này sử dụng vector để lưu trữ các tùy chọn menu và cung cấp phương thức display để hiển thị các tùy chọn đó.
 * @note Phương thức getChoice cho phép người dùng chọn một tùy chọn từ menu.
 * @note Lớp này có một phương thức trừu tượng type để các lớp con xác định loại menu của chúng.
 */
class Menu {
protected:
    vector<string> _options;
public:
    virtual ~Menu() = default;
    void display(int selected = 0) const;

    string getChoice() const;

    virtual string type() const = 0;
};

/**
 * @class MainMenu
 * @brief Lớp đại diện cho menu chính trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ Menu và cung cấp các tùy chọn cụ thể cho menu chính, bao gồm các thao tác trên cơ sở dữ liệu.
 * @note Phương thức type sẽ trả về chuỗi "MainMenu" để xác định loại menu này.
 */
class MainMenu : public Menu {
public:
    MainMenu();
    string type() const override;
};

/**
 * @class EntityMenu
 * @brief Lớp đại diện cho menu thực thể trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ Menu và cung cấp các tùy chọn cụ thể cho các thao tác trên thực thể, bao gồm sinh viên, giảng viên và khoa.
 * @note Phương thức type sẽ trả về chuỗi "EntityMenu" để xác định loại menu này.
 */
class EntityMenu : public Menu {
public:
    EntityMenu();
    string type() const override;

};

/**
 * @class SubMenu
 * @brief Lớp đại diện cho menu con trong hệ thống quản lý cơ sở dữ liệu
 * @details Lớp này kế thừa từ Menu và cung cấp các tùy chọn cụ thể cho các thao tác con của thực thể, như thêm, xóa, thay thế.
 * @note Phương thức type sẽ trả về chuỗi "SubMenu" để xác định loại menu này.
 */
class SubMenu: public Menu{
public:
    SubMenu();
    string type() const override;
};

/**
 * @class MenuFactory
 * @brief Lớp factory để tạo các menu dựa trên loại menu
 * @details Lớp này cung cấp phương thức tĩnh để tạo các menu cụ thể dựa trên chuỗi loại menu.
 * @note Các loại menu bao gồm: MainMenu, EntityMenu, SubMenu.
 * @note Nếu loại menu không hợp lệ, phương thức sẽ trả về nullptr.
 */
class MenuFactory {
public:
    static unique_ptr<Menu> createMenu(const string& type);
};
    

#endif