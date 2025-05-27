#include "check.h"
// int main() {
//     checkValidWord wordChecker;
//     checkValidNum numChecker;

//     // === Test cho isValidStr ===
//     std::cout << "Test isValidStr:\n";
//     std::cout << wordChecker.isValidStr("Nguyen Van A") << " (Expected: 1)\n";
//     std::cout << wordChecker.isValidStr("Nguyen123") << " (Expected: 0)\n";
//     std::cout << wordChecker.isValidStr("") << " (Expected: 0)\n";

//     // === Test cho isValidID ===
//     std::cout << "\nTest isValidID:\n";
//     std::cout << wordChecker.isValidID("12345678") << " (Expected: 1)\n";
//     std::cout << wordChecker.isValidID("1234abc") << " (Expected: 0)\n";
//     std::cout << wordChecker.isValidID("") << " (Expected: 0)\n";

//     // === Test cho isValidEmail ===
//     std::cout << "\nTest isValidEmail:\n";
//     std::cout << wordChecker.isValidEmail("abc@gmail.com") << " (Expected: 1)\n";
//     std::cout << wordChecker.isValidEmail("abc@.com") << " (Expected: 0)\n";
//     std::cout << wordChecker.isValidEmail("@gmail.com") << " (Expected: 0)\n";
//     std::cout << wordChecker.isValidEmail("abc@gmail.") << " (Expected: 0)\n";

//     // === Test cho isValidBirth ===
//     std::cout << "\nTest isValidBirth (string):\n";
//     std::cout << numChecker.isValidBirth("29/02/2020") << " (Expected: 1)\n"; // Leap year
//     std::cout << numChecker.isValidBirth("31/04/2020") << " (Expected: 0)\n"; // April has 30 days
//     std::cout << numChecker.isValidBirth("01/13/2020") << " (Expected: 0)\n"; // Invalid month
//     std::cout << numChecker.isValidBirth("abc") << " (Expected: 0)\n"; // Invalid format

//     // === Test cho isValidGPA ===
//     std::cout << "\nTest isValidGPA:\n";
//     std::cout << numChecker.isValidGPA("9.5") << " (Expected: 1)\n";
//     std::cout << numChecker.isValidGPA("10.1") << " (Expected: 0)\n";
//     std::cout << numChecker.isValidGPA("-1") << " (Expected: 0)\n";
//     std::cout << numChecker.isValidGPA("abc") << " (Expected: 0)\n";

//     // === Test cho isValidCredit ===
//     std::cout << "\nTest isValidCredit:\n";
//     std::cout << numChecker.isValidCredit("100") << " (Expected: 1)\n";
//     std::cout << numChecker.isValidCredit("10000") << " (Expected: 0)\n";
//     std::cout << numChecker.isValidCredit("-50") << " (Expected: 0)\n";
//     std::cout << numChecker.isValidCredit("abc") << " (Expected: 0)\n";

//     // === Test cho isValidInstructYear ===
//     std::cout << "\nTest isValidInstructYear:\n";
//     std::cout << numChecker.isValidInstructYear("30") << " (Expected: 1)\n";
//     std::cout << numChecker.isValidInstructYear("65") << " (Expected: 0)\n";
//     std::cout << numChecker.isValidInstructYear("-5") << " (Expected: 0)\n";

//     // === Test cho isValidYearEnroll ===
//     std::cout << "\nTest isValidYearEnroll:\n";
//     std::cout << numChecker.isValidYearEnroll("2024") << " (Expected: 1)\n";
//     std::cout << numChecker.isValidYearEnroll("2027") << " (Expected: 0)\n";
//     std::cout << numChecker.isValidYearEnroll("-2000") << " (Expected: 0)\n";

//     return 0;
// }


// Hàm kiểm tra năm nhuận
bool checkValidNum::isLeapYear(const int& year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


//Definition for the <class>                        checkValidWord

//For name and degree // (only include <words>)
bool checkValidWord::isValidStr(const string& str, string & errorMsg) {
    int n = str.length();
    if (n == 0) {
        errorMsg = "Chuỗi rỗng";
        return false; // "Chuỗi rỗng"
    }
    bool hasLetter = false; // Track if at least one letter exists
    bool prevWasSpace = false; // Track if previous character was a space
    
    for (int i = 0; i < n; ++i) {
       
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            hasLetter = true; 
            prevWasSpace = false; // Reset space tracker

        } else if (str[i] == ' ') {
            // kiểm tra có nhiều space ' ' liên tiếp không ?
            if (prevWasSpace) {
                errorMsg = "Tên có chứa nhiều khoảng trắng liên tiếp";
                return false; 
            }
            prevWasSpace = true; 
        } else {
            errorMsg = "Tên có chứa ký tự không là chữ cái hoặc không là space";
            return false; // Lỗi: "Tên có chứa ký tự không là chữ cái hoặc space"
        }
    if (!hasLetter) {
        errorMsg = "Tên không có chữ cái";
        return false; // Lỗi "Tên không có chữ cái" (all character are space)
        }
    }
    //end for loop
    return true;
}

// (only include <number>), len <= 8
bool checkValidWord::isValidID(const string& numbers, string & errorMsg) {
    int n = numbers.length();

    if (n == 0){
        errorMsg = "ID nhập vào là rỗng";
        return false; // Lỗi: "ID nhập vào là rỗng"
    }

    for (int i = 0; i < n; ++i) {
        if (
            numbers[i] > '9'
            || numbers[i] < '0'
            )
        {   
            errorMsg = "ID chỉ được phép chứa ký tự số";
            return false; //Lỗi: ID chỉ được phép chứa ký tự số
        }
    }
    return true;
}

//Email: 
/*
1. Chuỗi chứa ít nhất một ký tự trước ký tự '@'
2. Có ít nhất một ký tự '@'
3. Sau '@', phải có ít nhất một dấu chấm '.'
4. Dấu '.' không nằm ở cuối và không ngay sau '@'
5. Email không được bắt đầu bằng '@', không được kết thúc bằng dấu .
*/
bool checkValidWord::isValidEmail(const string& email, string & errorMsg) {
    int atPos = email.find('@');

    // 1. Phải có ít nhất một '@' và không nằm ở đầu
    if (atPos == std::string::npos || atPos == 0) {
        errorMsg = "Email không hợp lệ: Không có '@' hoặc '@' ở đầu chuỗi";
        return false;
    }

    // 2. Phần sau '@' phải có ít nhất một '.'
    int dotPos = email.find('.', atPos + 1);

    if (dotPos == std::string::npos) {
        errorMsg = "Email không hợp lệ: Không có '.' sau '@'";
        return false;
    }

    // 3. Dấu '.' không được là ký tự cuối cùng
    if (dotPos == email.length() - 1) {
        errorMsg = "Email không hợp lệ: '.' ở cuối chuỗi";
        return false;
    }

    // 4. Dấu '.' không được nằm ngay sau '@'
    if (dotPos == atPos + 1) {
        errorMsg = "Email không hợp lệ: '.' ngay sau '@'";
        return false;
    }

    return true;
}



//          Definition:                  CLASS: checkValidNum


 // format: dd//mm/yyyy & is valid date 
 // Nếu như a muốn đơn giản thì chỉ cần trả về 1 trong 2 messenge là :
 //       "Ngày tháng năm chưa đúng định dạng"               (VD: 01/0a/2*0`: ko đúng định dạng) 
 //  hoặc "Ngày tháng năm đúng định dạng nhưng chưa hợp lệ"  (VD: 59/13/2200: chưa hợp lệ)

bool checkValidNum::isValidBirth(const Birth& bir) {  // - Cần chuyển chuỗi về birth trước khi kiểm tra
    int day = bir.getDay();
    int month = bir.getMonth();
    int year = bir.getYear();

    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    int daysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    // Nếu là tháng 2 và năm nhuận
    if (month == 2 && isLeapYear(year)) {
        if (day >= 1 && day <= 29) return true;
        else return false;
    }

    // Các tháng khác
    if (day >= 1 && day <= daysInMonth[month]) return true;

    return false;
}
//Với tham số là string, hàm này sẽ kiểm tra định dạng của date
bool checkValidNum::isValidBirth(const string& bir, string & errorMsg) {
    int n = bir.length();
    if (n > 10) {
        errorMsg = "Chuỗi nhập vào không đung định dạng dd/mm/yyyy";
        return false;
    } //chuỗi ko đúng địng dạng dd/mm//yyyy
    if (n < 5) {
        errorMsg = "Chuỗi nhập vào quá ngắn";
        return false; 
    }// chuỗi ko đủ ký tự, cần ít nhất là "1/1/1"; 

    string day = "", mon = "", year = "";
    stringstream ss(bir);
    getline(ss, day, '/');
    getline(ss, mon, '/');
    getline(ss, year);
    if (day == "" || mon == "" || year == ""){ 
        errorMsg = "Chuỗi nhập vào không có dấu '/' nào hoặc không đúng định dạng";
        return false;
    } //Nếu chuỗi bir ko có dấu '/' nào || đọc dữ liệu ko thành công

    //kiểm tra các biến có đúng định dạng ?
    for (int i = 0; i < day.length(); ++i) {
        if (day[i] < '0' || day[i] > '9') {
            errorMsg = "Ngày chứa ký tự không phải là số";
            return false;
        } //not a number
    }
    for (int i = 0; i < mon.length(); ++i) {
        if (mon[i] < '0' || mon[i] > '9') {
            errorMsg = "Thang chứa ký tự không phải là số";
            return false;
        } //not a number
    }
    for (int i = 0; i < year.length(); ++i) {
        if (year[i] < '0' || year[i] > '9') {
            errorMsg = "Năm chứa ký tự không phải là số";
            return false;
        } //not a number
    }
    int y = stoi(year);
    if (y < 1900) {
        errorMsg = "Năm được nhập lập phải lớn hơn 1900";
        return false; //Lỗi: "Năm được nhập lập phải lớn hơn 1900 và nhỏ hơn 2100"
    }
    else if (y > 2100){
        errorMsg = "Năm được nhập lập phải nhỏ hơn 2100";
        return false; //Lỗi: "Năm được nhập lập phải lớn hơn 1900 và nhỏ hơn 2100"
    }
    //kiểm tra date là hợp lệ
    Birth temp; temp.setBirth(stoi(day), stoi(mon), y);
    return isValidBirth(temp);
}


bool checkValidNum::isValidDigitStr(const string& digit, string & errorMsg) {
    //kiểm tra trong chuỗi digit có toàn là chữ số ko ?
    int n = digit.length();
    if (n == 0) {
        errorMsg = "Chuỗi nhập vào là rỗng";
        return false;
    } //"Chuỗi nhập vào là rỗng"
    for (int i = 0; i < n; ++i) {
        if (digit[i] > '9' || digit[i] < '0') {
            errorMsg = "Chuỗi không đúng định dạng, chứa các ký tự khác số";
            return false;
        }
    }
    return true;
}

//GPA (<10)
bool checkValidNum::isValidGPA(const float& gpa) {
    if (gpa > 10) return false; //Lỗi: "GPA được nhập vượt quá 10"
    if (gpa < 0) return false; // Lỗi: "GPA được nhập là số âm" 
    return true;

}
bool checkValidNum::isValidGPA(const string& gpa, string & errorMsg) {
    int n = gpa.length();
    if (n == 0) {
        errorMsg = "Chuỗi nhập vào là rỗng";
        return false;
    }
    bool dot = false;
    for (int i = 0; i < n; ++i) {
        if (gpa[i] == '.') {
            if (dot) {
                errorMsg = "Chuỗi không đúng định dạng, chứa nhiều dấu '.'";
                return false; //đã có 1 dấu . trước đó xuất hiện, => Xuất hiện 2 dấu . -> Chuỗi sai
            }
            dot = true; 
        }
        else {
            if (gpa[i] > '9' || gpa[i] < '0') {
                errorMsg = "Chuỗi không đúng định dạng, chứa các ký tự khác số và dấu .";
                return false;
            } // "Chuỗi không đúng định dạng, chứa các ký tự khác số và dấu ."
        }
    }
    float temp = stof(gpa);
    return isValidGPA(temp);
}

bool checkValidNum::isValidCredit(const int& credit) {  // >= 0 & < 10000
    if (credit >= 10000) return false; // "Số tín chỉ quá lớn"
    if (credit < 0) return false; // "Số tín chỉ được nhập là số âm"
    return true;

}

bool checkValidNum::isValidCredit(const string& credit, string & errorMsg) {

    if (isValidDigitStr(credit, errorMsg)) {
        return isValidCredit(stoi(credit));
    }

    return false;
}


bool checkValidNum::isValidInstructYear(const int& instructYear,  const int yearBirth) { 
    if (instructYear < (yearBirth + 18)) return false;// "Năm đầu tiên giảng dạy phải lớn hơn năm sinh ít nhất 18 tuổi"
    if (instructYear > 2030) return false; // "Năm đầu tiên giảng dạy quá lớn"
    return true;

}
bool checkValidNum::isValidInstructYear(const string& instructYear, string & errorMsg,  const int yearBirth) {
    if (isValidDigitStr(instructYear, errorMsg)) {
        int temp = stoi(instructYear);
        return isValidInstructYear(temp, yearBirth);
    }
    return false;
}

//Năm nhập học/khóa nhập học của sinh viên >= 2000
bool checkValidNum::isValidYearEnroll(const int& yearEnroll,  const int& yearBirth) {
    if (yearEnroll < (yearBirth + 16)) {
        return false;// "Năm nhập học phải lớn hơn năm sinh ít nhất 16 tuổi" //sẽ có một số ngoại lệ nên ta để yearBirth + 10
    }
    std::cout << yearEnroll << " - " << yearBirth << std::endl;

    if (yearEnroll > 2026) return false; // "Số năm nhập học lớn hơn 2026"
    return true;
}
bool checkValidNum::isValidYearEnroll(const string& yearEnroll, string & errorMsg,  const int& yearBirth ) {
    if (isValidDigitStr(yearEnroll, errorMsg)) {
        int temp = stoi(yearEnroll);
        
        return isValidYearEnroll(temp, yearBirth);
    }
    return false;
}


