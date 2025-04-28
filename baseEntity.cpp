#include "baseEntity.h"

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

void Birth::setBirth(const string& str){
    int n = str.size();
    int d = 0, m = 0, y = 0;
    int i = 0;
    _day = d;
    _month = m;
    _year = y;
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