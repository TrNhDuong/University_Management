/**
 * @file menu.h
 * @brief Khai báo các lớp menu cho hệ thống quản lý sinh viên.
 * @details Các lớp này cung cấp các phương thức để hiển thị menu và xử lý lựa chọn của người dùng.
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
 * @brief Lớp cơ sở cho các menu trong hệ thống.
 * @details Lớp này cung cấp các phương thức để hiển thị menu và xử lý lựa chọn của người dùng.
 */
class Menu {
protected:
    /**
     * @brief Danh sách các tùy chọn trong menu.
     * @details Danh sách này chứa các chuỗi mô tả các tùy chọn trong menu.
     */
    vector<string> _options;
public:
    /**
     * @brief Hàm khởi tạo mặc định.
     * @details Hàm này khởi tạo danh sách các tùy chọn trong menu.
     */
    virtual ~Menu() = default;
    
    /**
     * @brief Hiển thị menu.
     * @details Hàm này in ra danh sách các tùy chọn trong menu.
     */
    void display(int selected = 0) const;

    /**
     * @brief Lấy lựa chọn của người dùng.
     * @return Lựa chọn của người dùng dưới dạng chuỗi.
     */
    string getChoice() const;

    virtual string type() const = 0;
};


/**
 * @class MainMenu
 * @brief Lớp menu chính trong hệ thống.
 * @details Lớp này cung cấp các phương thức để hiển thị menu chính và xử lý lựa chọn của người dùng.
 */
class MainMenu : public Menu {
public:
    /**
     * @brief Hàm khởi tạo mặc định cho menu chính.
     * @details Hàm này khởi tạo danh sách các tùy chọn trong menu chính.
     */
    MainMenu();
    /**
     * @brief Hiển thị menu chính.
     * @details Hàm này in ra danh sách các tùy chọn trong menu chính.
     */

     string type() const override;
};

/**
 * @class EntityMenu
 * @brief Lớp menu cho các thực thể trong hệ thống.
 * @details Lớp này cung cấp các phương thức để hiển thị menu cho các thực thể và xử lý lựa chọn của người dùng.
 */
class EntityMenu : public Menu {
public:
    /**
     * @brief Hàm khởi tạo mặc định cho menu thực thể.
     * @details Hàm này khởi tạo danh sách các tùy chọn trong menu thực thể.
     */
    EntityMenu();

    /**
     * @brief Hiển thị menu thực thể.
     * @details Hàm này in ra danh sách các tùy chọn trong menu thực thể.
     */

     string type() const override;

};

/**
 * @class MenuFactory
 * @brief Lớp factory để tạo các menu trong hệ thống.
 * @details Lớp này cung cấp các phương thức để tạo các menu khác nhau dựa trên loại menu được yêu cầu.
 */
class MenuFactory {
    public:
        /**
         * @brief Tạo một menu dựa trên loại menu được yêu cầu.
         * @param type Loại menu cần tạo.
         * @return Con trỏ thông minh đến đối tượng menu được tạo.
         * @details Hàm này sẽ tạo một menu mới dựa trên loại menu được yêu cầu.
         */
        static unique_ptr<Menu> createMenu(const string& type);
    };
    

#endif // MENU_H