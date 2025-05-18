#include "inputData.h"

#pragma region getInputType
string StudentInput::getInputType() const {
    return "Student";
}

string LecturerInput::getInputType() const {
    return "Lecturer";
}

string FacultyInput::getInputType() const {
    return "Faculty";
}

#pragma endregion


#pragma region StudentInput

BaseEntity* StudentInput::input(){
    BaseEntity* ans = nullptr;
    Student* s = new Student();
    string name, id, birth;
    float gpa;
    int enrollYear, credit;
    cout << "Inpu student information:\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "ID: ";
    getline(cin, id);
    cout << "Date of birth (dd/mm/yyyy): ";
    getline(cin, birth);
    cout << "GPA: ";
    cin >> gpa;
    cout << "Enroll year: ";
    cin >> enrollYear;
    cout << "Completed credit: ";
    cin >> credit;
    s->setName(name);
    s->setBirth(birth);
    s->setId(id);
    s->setEnrollYear(enrollYear);
    s->setGPA(gpa);
    s->setCredit(credit);
    ans = s;
    return ans;
}

#pragma endregion

#pragma region LecturerInput

BaseEntity* LecturerInput::input(){
    BaseEntity* ans = nullptr;
    Lecturer* s = new Lecturer();
    string name, id, birth;
    int structYear;
    string  degree;
    cout << "Input lecturer information:\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "ID: ";
    getline(cin, id);
    cout << "Date of birth (dd/mm/yyyy): ";
    getline(cin, birth);
    cout << "First year of teaching: ";
    cin >> structYear;
    cout << "Degree: ";
    cin >> degree;
    s->setName(name);
    s->setBirth(birth);
    s->setId(id);
    s->setInstructYear(structYear);
    s->setDeg(degree);
    ans = s;
    return ans;
}

#pragma endregion

#pragma region FacultyInput

BaseEntity* FacultyInput::input(){
    BaseEntity* ans = nullptr;
    Faculty* s = new Faculty();
    string name, id, birth;
    string mail;
    string idDean;
    // cout << "Nhap thong tin lien quan toi khoa:\n";
    // cout << "Nhap ten: ";
    // cin >> name;
    // cout << "Nhap ma khoa: ";
    // cin >> id;
    // cout << "Nhap ngay thanh lap (dd/mm/yyyy): ";
    // cin >> birth;
    // cout << "Nhap mail: ";
    // cin >> enrollYear;
    // cout << "Nhap MSGV truong khoa: ";
    // cin >> idDean;
    // s.setName(name);
    // s.setBirth(birth);
    // s.setId(id);
    // s.setEnrollYear(enrollYear);
    // s.setGPA(gpa);
    // s.setCredit(credit);
    ans = s;
    return ans;
}

#pragma endregion

IDataInput* InputFactory::create(const string& typeEntity){
    if ("Student" == typeEntity){
        return new StudentInput();
    } else if ("Lecturer" == typeEntity){
        return new LecturerInput();
    } else if ("Faculty" == typeEntity){
        return new FacultyInput();
    }
    return nullptr;
}

