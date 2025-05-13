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
    cout << "Nhap thong tin lien quan toi sinh vien:\n";
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap MSSV: ";
    getline(cin, id);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, birth);
    cout << "Nhap GPA: ";
    cin >> gpa;
    cout << "Nhap nam nhap hoc: ";
    cin >> enrollYear;
    cout << "Nhap so tin chi da hoan thanh: ";
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
    cout << "Nhap thong tin lien quan toi giang vien:\n";
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap MSGV: ";
    getline(cin, id);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, birth);
    cout << "Nhap nam bat dau giang day: ";
    cin >> structYear;
    cout << "Nhap hoc ham: ";
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
    Faculty s;
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
    ans = &s;
    return ans;
}

#pragma endregion

IDataInput* InputFactory::create(const string& typeEntity){
    if ("Student" == typeEntity){
        return new StudentInput();
    } else if ("Lecturer" == typeEntity){
        return new LecturerInput();
    } else if ("Faculty" == typeEntity)
        return new FacultyInput();
    return nullptr;
}

