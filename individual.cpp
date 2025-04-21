#include "individual.h"

void Birth::setBirth(const int& d, const int& m, const int& y){
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