#include "lecturer.h"

Lecturer::Lecturer(){
    _name = "";
    _id = "";
}

void Lecturer::setInstructYear(const int& year){
    _instructYear = year;
}
void Lecturer::setDeg(const string& deg){
    _academicDegree = deg;
}

Lecturer::~Lecturer(){
    
}

string Lecturer::getType(){
    return "Lecturer";
}

int Lecturer::getInstructYear() const {
    return _instructYear;
}

string Lecturer::getDegree() const {
    return _academicDegree;
}

// ----- LECTURER BUILDER ----- builder pattern
class LecturerBuilder {
    Lecturer l;

public:
    LecturerBuilder& setName(const std::string& name) {
        l._name = name;
        return *this;
    }

    LecturerBuilder& setID(const std::string& id) {
        l._id = id;
        return *this;
    }

    LecturerBuilder& setInstructYear(int year) {
        l._instructYear = year;
        return *this;
    }

    LecturerBuilder& setDegree(const std::string& degree) {
        l._academicDegree = degree;
        return *this;
    }

    Lecturer build() {
        return l;
    }
};