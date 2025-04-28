#include "faculty.h"
using std::cout, std::endl;

string Faculty::getType() const{
    return "Faculty";
}

string Faculty::getMail() const{
    return _email;
}

void Faculty::setMail(const string& mail){
    _email = mail;
}

Faculty::Faculty(){
    _name = "";
    _id = "";
    _email = "";
}

Faculty::~Faculty(){
}

void Faculty::prinInfo(){
    cout << "Faculty Name: " << getName() << endl;
    cout << "Faculty ID: " << getId() << endl;
    cout << "Faculty Mail: " << getMail() << endl;
    cout << "Dean Name: " << getDean().getName() << endl;
    cout << "Dean ID: " << getDean().getId() << endl;
}

void Faculty::setDean(const Instructor& dean){
    _dean = dean;
}

Instructor Faculty::getDean(){
    return _dean;
}
