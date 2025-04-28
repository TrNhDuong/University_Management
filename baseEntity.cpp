#include "baseEntity.h"
#include <sstream>
#include <iostream>

Birth::Birth(){
    _day = _month = _year = 0;
}

Birth::~Birth(){
    
}

BaseEntity::BaseEntity(){
    _name = "";
    _id = "";
}

BaseEntity::~BaseEntity(){
    
}

void Birth::setBirth(const int& d, const int& m, const int& y){
    _day = d;
    _month = m;
    _year = y;
}

void Birth::setBirth(const std::string& str) {
    // Khai báo một stringstream từ chuỗi cần tách
    std::stringstream ss(str);
    
    // Tách ngày, tháng, năm theo dấu '/'
    std::string day, month, year;
    
    std::getline(ss, day, '/');
    std::getline(ss, month, '/');
    std::getline(ss, year);
    
    try {
        // Chuyển các phần vừa tách sang kiểu int và gán vào các biến thành viên
        _day = std::stoi(day);
        _month = std::stoi(month);
        _year = std::stoi(year);
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid input for date: " << str << std::endl;
    }
}

int Birth::getDay() const{
    return _day;
}

int Birth::getMonth() const{
    return _month;
}

int Birth::getYear() const{
    return _year;
}

string BaseEntity::getName() const{
    return _name;
}

string BaseEntity::getId() const{
    return _id;
}

Birth BaseEntity::getBirth() const{
    return _birthDay;
}

void BaseEntity::setName(const string& name){
    _name = name;
}

void BaseEntity::setId(const string& id){
    _id = id;
}

void BaseEntity::setBirth(const Birth& birthDay){
    _birthDay.setBirth(birthDay.getDay(), birthDay.getMonth(), birthDay.getYear());
}

void BaseEntity::setBirth(const string& s){
    _birthDay.setBirth(s);
}