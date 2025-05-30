/**
 * @file check.h
 * @brief Kiểm tra tính hợp lệ của dữ liệu nhập vào
 * @details Lớp checkValidWord và checkValidNum cung cấp các phương thức để kiểm tra tính hợp lệ của chuỗi ký tự và số.
 * @note Bao gồm các phương thức kiểm tra tính hợp lệ của tên, ID, email, ngày sinh, GPA, tín chỉ và năm nhập học.
 */

#ifndef _CHECK_H_
#define _CHECK_H_

#include "check.h"
#include "baseEntity.h"
#include <iostream>
#include<string>
#include<sstream>

using namespace std;



/**
 * @class checkValidWord
 * @brief Lớp để kiểm tra tính hợp lệ của chuỗi ký tự
 * @details Lớp này cung cấp các phương thức để kiểm tra tính hợp lệ của tên, ID, email.
 * @note Các phương thức sẽ trả về true nếu chuỗi hợp lệ, ngược lại sẽ trả về false và cung cấp thông báo lỗi.
 */
class checkValidWord {
public:
    //for name and degree: string-words
    static bool isValidStr(const string& str, string & errorMsg);

    static bool isValidID(const string& numbers, string & errorMsg);
    static bool isValidEmail(const string& email, string & errorMsg);

};

/**
 * @class checkValidNum
 * @brief Lớp để kiểm tra tính hợp lệ của các số
 * @details Lớp này cung cấp các phương thức để kiểm tra tính hợp lệ của ngày sinh, GPA, tín chỉ, năm giảng dạy và năm nhập học.
 * @note Các phương thức sẽ trả về true nếu số hợp lệ, ngược lại sẽ trả về false và cung cấp thông báo lỗi.
 */
class checkValidNum {
public:
    //Digit
    static bool isValidBirth(const Birth& bir);
    static bool isValidBirth(const string& bir, string & errorMsg);
    static bool isLeapYear(const int& year);
    //Tái sử dụng code: isValidDigitStr(); 
    static bool isValidDigitStr(const string& digit, string & errorMsg);

    static bool isValidGPA(const float& gpa);
    static bool isValidGPA(const string& gpa, string & errorMsg);

    static bool isValidCredit(const int& credit);
    static bool isValidCredit(const string& credit, string & errorMsg);

    static bool isValidInstructYear(const int& instructYear,  const int yearBirth = 2000 );
    static bool isValidInstructYear(const string& instructYear, string & errorMsg,  const int yearBirth = 2000);

    static bool isValidYearEnroll(const int& yearEnroll,  const int& yearBirth = 2000 );
    static bool isValidYearEnroll(const string& yearEnroll, string & errorMsg,  const int& yearBirth = 2000);
};


#endif 