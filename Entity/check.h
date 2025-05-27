#ifndef _CHECK_H_
#define _CHECK_H_

#include "check.h"
#include "baseEntity.h"
#include <iostream>
#include<string>
#include<sstream>

using namespace std;



//Chỉ copy các hàm/method liên quan đến kiểm lỗi, còn lại không cần copy nếu ko có ghi chú riêng cho nó

/*                      READ ME
        Logic của class checkValid sẽ bao gồm các bước ktra phù hợp
        cho cả đọc file và đọc dữ liệu từ bàn phím.
        Ở định nghĩa của mỗi method sẽ có mô tả logic mà hàm sẽ kiểm tra
*/
class checkValidWord {
public:
    //for name and degree: string-words
    static bool isValidStr(const string& str, string & errorMsg);

    static bool isValidID(const string& numbers, string & errorMsg);
    static bool isValidEmail(const string& email, string & errorMsg);

};
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

    static bool isValidInstructYear(const int& instructYear, const int& yearBirth = 2000);
    static bool isValidInstructYear(const string& instructYear, string & errorMsg, const int& yearBirth = 2000);

    static bool isValidYearEnroll(const int& yearEnroll, const int& yearBirth = 2000);
    static bool isValidYearEnroll(const string& yearEnroll, string & errorMsg, const int& yearBirth = 2000);
};


#endif 