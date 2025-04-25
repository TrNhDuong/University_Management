#include "individual.h"

Birth::Birth(){
    _d = _m = _y = 0;
}

Birth::~Birth(){
    
}

Individual::Individual(){
    _name = "";
    _id = "1111111";
}

Individual::~Individual(){
    
}

void Birth::setBirth(const int& d, const int& m, const int& y){
    _d = d;
    _m = m;
    _y = y;
}

void Birth::setBirth(const string& str){
    int n = str.size();
    int d = 0, m = 0, y = 0;
    int i = 0;
    _d = d;
    _m = m;
    _y = y;
}

int Birth::getDay() const{
    return _d;
}

int Birth::getMonth() const{
    return _m;
}

int Birth::getYear() const{
    return _y;
}

string Individual::getName() const{
    return _name;
}

string Individual::getId() const{
    return _id;
}

Birth Individual::getBirth() const{
    return _birthDay;
}

void Individual::setName(const string& name){
    _name = name;
}

void Individual::setId(const string& id){
    _id = id;
}

void Individual::setBirth(const Birth& birthDay){
    _birthDay.setBirth(birthDay.getDay(), birthDay.getMonth(), birthDay.getYear());
}

void Individual::setBirth(const string& s){
    _birthDay.setBirth(s);
}