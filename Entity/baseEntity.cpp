#include "baseEntity.h"
#include <iostream>

 #include "baseEntity.h"
 #include <sstream>
 #include <iostream>cpp
 
 /**
  * @class Birth
  * @brief Đại diện cho ngày sinh.
  */
 Birth::Birth() {
     _day = _month = _year = 0;
 }
 
 /**
  * @brief Hàm hủy của lớp Birth.
  */
 Birth::~Birth() {
 }
 
 /**
  * @brief Thiết lập ngày sinh bằng ngày, tháng, năm.
  * @param d Ngày sinh.
  * @param m Tháng sinh.
  * @param y Năm sinh.
  */
 void Birth::setBirth(const int& d, const int& m, const int& y) {
     _day = d;
     _month = m;
     _year = y;
 }
 
 /**
  * @brief Thiết lập ngày sinh bằng chuỗi định dạng "dd/mm/yyyy".
  * @param str Chuỗi ngày sinh.
  */
 void Birth::setBirth(const string& str) {
     int n = str.size();
     int d = 0, m = 0, y = 0;
     int i = 0;
     while (str[i] != '/')
         d = d * 10 + str[i++] - '0';
     i++;
     while (str[i] != '/')
         m = m * 10 + str[i++] - '0';
     i++;
     while (i < n)
         y = y * 10 + str[i++] - '0';
     _day = d;
     _month = m;
     _year = y;
 }
 
 /**
  * @brief Lấy ngày sinh.
  * @return Ngày sinh.
  */
 int Birth::getDay() const {
     return _day;
 }
 
 /**
  * @brief Lấy tháng sinh.
  * @return Tháng sinh.
  */
 int Birth::getMonth() const {
     return _month;
 }
 
 /**
  * @brief Lấy năm sinh.
  * @return Năm sinh.
  */
 int Birth::getYear() const {
     return _year;
 }
 
 /**
  * @class BaseEntity
  * @brief Đại diện cho một thực thể cơ bản với tên, mã định danh và ngày sinh.
  */
 BaseEntity::BaseEntity() {
     _name = "";
     _id = "";
 }
 
 /**
  * @brief Hàm hủy của lớp BaseEntity.
  */
 BaseEntity::~BaseEntity() {
 }
 
 /**
  * @brief Lấy tên của thực thể.
  * @return Tên của thực thể.
  */
 string BaseEntity::getName() const {
     return _name;
 }
 
 /**
  * @brief Lấy mã định danh của thực thể.
  * @return Mã định danh của thực thể.
  */
 string BaseEntity::getId() const {
     return _id;
 }
 
 /**
  * @brief Lấy ngày sinh của thực thể.
  * @return Ngày sinh dưới dạng đối tượng Birth.
  */
 Birth BaseEntity::getBirth() const {
     return _birthDay;
 }
 
 /**
  * @brief Thiết lập tên của thực thể.
  * @param name Tên cần thiết lập.
  */
 void BaseEntity::setName(const string& name) {
     _name = name;
 }
 
 /**
  * @brief Thiết lập mã định danh của thực thể.
  * @param id Mã định danh cần thiết lập.
  */
 void BaseEntity::setId(const string& id) {
     _id = id;
 }
 
 /**
  * @brief Thiết lập ngày sinh của thực thể bằng đối tượng Birth.
  * @param birthDay Đối tượng Birth đại diện cho ngày sinh.
  */
 void BaseEntity::setBirth(const Birth& birthDay) {
     _birthDay.setBirth(birthDay.getDay(), birthDay.getMonth(), birthDay.getYear());
 }
 
 /**
  * @brief Thiết lập ngày sinh của thực thể bằng chuỗi định dạng "dd/mm/yyyy".
  * @param s Chuỗi ngày sinh.
  */
 void BaseEntity::setBirth(const string& s) {
     _birthDay.setBirth(s);
 }