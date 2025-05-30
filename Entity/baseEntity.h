/**
 * @file baseEntity.h
 * @brief Định nghĩa lớp cơ sở cho các thực thể trong hệ thống
 * @details Lớp BaseEntity đại diện cho các thực thể cơ bản trong hệ thống, bao gồm thông tin về tên, ID, ngày sinh và email.
 * @note Lớp Birth đại diện cho ngày sinh của thực thể.
 * @note Lớp BaseEntity cung cấp các phương thức để thiết lập và truy xuất thông tin của thực thể.
 * @note Lớp Birth cung cấp các phương thức để thiết lập và truy xuất ngày sinh.
 * @note Các lớp con sẽ kế thừa từ BaseEntity để mở rộng chức năng cho các loại thực thể cụ thể như Student, Lecturer, Faculty.
 */

#ifndef _BASE_ENTITY_H_
#define _BASE_ENTITY_H_
#include <string>
using std::string;
using std::ostream;

/**
 * @class Birth
 * @brief Lớp đại diện cho ngày sinh của thực thể
 * @details Lớp này cung cấp các phương thức để thiết lập và truy xuất ngày, tháng, năm sinh.
 * @note Ngày sinh được lưu trữ dưới dạng ba thành phần: ngày, tháng, năm.
 */
class Birth{
private:
    int _day, _month, _year;
public:
    Birth();
    ~Birth();
    void setBirth(const int& d, const int& m, const int& y);
    void setBirth(const string&);
    int getDay() const;
    int getMonth() const;
    int getYear() const ;
};

/**
 * @class BaseEntity
 * @brief Lớp cơ sở đại diện cho các thực thể trong hệ thống
 * @details Lớp này cung cấp các phương thức để thiết lập và truy xuất thông tin cơ bản của thực thể như tên, ID, ngày sinh và email.
 * @note Các lớp con sẽ kế thừa từ BaseEntity để mở rộng chức năng cho các loại thực thể cụ thể như Student, Lecturer, Faculty.
 */
class BaseEntity{
protected:
    string _name;
    string _id;
    Birth _birthDay;
    string _mail;
public:
    string getName() const;
    string getId() const;
    string getMail() const;
    Birth getBirth() const;
    void setName(const string& name);
    void setId(const string& id);
    void setMail(const string& mail);
    void setBirth(const Birth& birthDay);
    void setBirth(const string&);
    BaseEntity();
    virtual ~BaseEntity();
};
#endif