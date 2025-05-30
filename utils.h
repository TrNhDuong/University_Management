/**
 * @file utils.h
 * @brief Các hàm tiện ích và lớp hỗ trợ cho hệ thống quản lý cơ sở dữ liệu
 * @details Bao gồm các hàm để thêm, xóa, thay thế dữ liệu trong vector, hiển thị danh sách, kiểm tra lựa chọn hợp lệ và các hàm hỗ trợ khác.
 * @note Bao gồm các hàm để thiết lập màu sắc, x
 */

#ifndef _UTILS_H_
#define _UTILS_H_
#include <vector>
#include <string>
#include <iostream>
#include <format>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
using namespace std;


/**
 * @brief Thêm dữ liệu mới vào vector
 * @param data Vector chứa dữ liệu
 * @param newData Dữ liệu mới cần thêm
 */
template <class T>
void addData(vector<T>& data, T& newData){
    data.push_back(newData);
}

/**
 * @brief Xóa dữ liệu khỏi vector dựa trên ID
 * @param data Vector chứa dữ liệu
 * @param remove Dữ liệu cần xóa
 */
template <class T>
void removeData(vector<T>& data, T& remove){
    vector<T> newList;
    for (const T&x: data){
        if (x.getId() != remove.getId()){
            newList.push_back(x);
        }
    }
    data = newList;
}

/**
 * @brief Thay thế dữ liệu trong vector
 * @param data Vector chứa dữ liệu
 * @param oldData Dữ liệu cũ cần thay thế
 * @param newData Dữ liệu mới thay thế vào
 */
template <class T>
void replaceData(vector<T>& data, T& oldData, T& newData){
    vector<T> newList;
    for (const T&x: data){
        if (x.getId() != oldData.getId()){
            newList.push_back(x);
        }else{
            newList.push_back(newData);
        }
    }
    data = newList;
}

/**
 * @class displayAList
 * @brief Lớp để hiển thị danh sách các thực thể
 * @details Cung cấp phương thức để hiển thị danh sách các thực thể trong vector.
 * @note Sử dụng std::cout để in thông tin của từng thực thể trong vector.
 */
class displayAList{
    public:
        static void displayList(vector<string>&);
};

/**
 * @class ValidChoice
 * @brief Lớp để kiểm tra lựa chọn hợp lệ
 * @details Cung cấp phương thức để kiểm tra xem lựa chọn của người dùng có hợp lệ hay không.
 * @note Sử dụng vector<string> để lưu trữ các lựa chọn hợp lệ và kiểm tra xem lựa chọn của người dùng có nằm trong danh sách đó hay không.
 */
class ValidChoice{
    public:
        static bool checkValidChoice(vector<string>&, string&);
};

/**
 * @brief Thiết lập màu sắc cho đầu ra
 * @param color Mã màu cần thiết lập
 */
void setColor(int color);
void clearScreen();
char getch();
std::string toUpper(const std::string& str);

#endif