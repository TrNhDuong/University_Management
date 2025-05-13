#include "faculty.h"

string Faculty::getType() const{
    return "Faculty";
}





Faculty::Faculty(){
}

Faculty::~Faculty(){
}


void Faculty::setDean(const Lecturer& dean){
    _dean = dean;
}

Lecturer Faculty::getDean() const{
    return _dean;
}
