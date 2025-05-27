#include "inputData.h"
#include "display.h"

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

    string name, id, birth, errorMsg;
    float gpa;
    int enrollYear, credit;
    cout << "Nhap thong tin lien quan toi sinh vien:\n";
    cout << "Nhap ten: ";
    getline(cin, name);
    while (!checkValidWord::isValidStr(name, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ten: ";
        getline(cin, name);
        errorMsg.clear();
    }

    cout << "Nhap MSSV: ";
    getline(cin, id);
    while (!checkValidWord::isValidID(id, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai MSSV: ";
        getline(cin, id);
        errorMsg.clear();
    }

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, birth);
    while (!checkValidNum::isValidBirth(birth, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ngay sinh: ";
        getline(cin, birth);
        errorMsg.clear();
    }

    cout << "Nhap GPA: ";
    string tempGPA ="";
    getline(cin,tempGPA);
     //lỗi gpa nhập vào chữ thì chạy liên tục
    while (!checkValidNum::isValidGPA(tempGPA, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai GPA: ";
        getline(cin,tempGPA);
        errorMsg.clear();
    }
    gpa =stof(tempGPA);

    cout << "Nhap nam nhap hoc: ";
    string tempEnrollYear = "";
    getline(cin, tempEnrollYear);
    int yearBirth = stoi(birth.substr(birth.length() - 4)); //Lấy năm sinh từ chuỗi birth
    while (!checkValidNum::isValidYearEnroll(tempEnrollYear, errorMsg, yearBirth)){
        cout << errorMsg << '\n';
        cout << "Nhap lai nam nhap hoc: ";
        getline(cin, tempEnrollYear);
        errorMsg.clear();
    }
    enrollYear = stoi(tempEnrollYear);

    cout << "Nhap so tin chi da hoan thanh: ";
    string tempCredit = "";
    getline(cin, tempCredit);
    while (!checkValidNum::isValidCredit(tempCredit, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai so tin chi da hoan thanh: ";
        getline(cin, tempCredit);
        errorMsg.clear();
    }
    credit = stoi(tempCredit);

    //set data for Student
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
    string name, id, birth, errorMsg;
    string structYear;
    string  degree;

    cout << "Nhap thong tin lien quan toi giang vien:\n";
    cout << "Nhap ten: ";
    getline(cin, name);
    while (!checkValidWord::isValidStr(name, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ten: ";
        getline(cin, name);
        errorMsg.clear();
    }

    cout << "Nhap MSGV: ";
    getline(cin, id);
    while (!checkValidWord::isValidID(id, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai MSGV: ";
        getline(cin, id);
        errorMsg.clear();
    }

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, birth);
    while (!checkValidNum::isValidBirth(birth, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ngay sinh: ";
        getline(cin, birth);
        errorMsg.clear();
    }

    cout << "Nhap nam bat dau giang day: ";
    getline(cin, structYear);
    int yearBirth = stoi(birth.substr(birth.length() - 4)); //Lấy năm sinh từ chuỗi birth
    while (!checkValidNum::isValidInstructYear(structYear, errorMsg, yearBirth)){
        cout << errorMsg << '\n';
        cout << "Nhap lai nam bat dau giang day: ";
        getline(cin, structYear);
        errorMsg.clear();
    }

    cout << "Nhap hoc ham: ";
    getline(cin,degree);
    while (!checkValidWord::isValidStr(degree, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai hoc ham: ";
        getline(cin,degree);
        errorMsg.clear();
    }

    cin.ignore();
    s->setName(name);
    s->setBirth(birth);
    s->setId(id);
    s->setInstructYear(stoi(structYear));
    s->setDeg(degree);
    ans = s;
    return ans;
}

#pragma endregion

#pragma region FacultyInput

BaseEntity* FacultyInput::input(){
    BaseEntity* ans = nullptr;
    Faculty* s = new Faculty();
    string name, id, birth, errorMsg;
    string mail;
    string idDean;
    cout << "Nhap thong tin lien quan toi khoa:\n";
    cout << "Nhap ten: ";
    getline(cin, name);
    while (!checkValidWord::isValidStr(name, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ten: ";
        getline(cin, name);
        errorMsg.clear();
    }
    cout << "Nhap ID: ";
    getline(cin, id);
    while (!checkValidWord::isValidID(id, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ID: ";
        getline(cin, id);
        errorMsg.clear();
    }
    cout << "Nhap ngay thanh lap (dd/mm/yyyy): ";
    getline(cin, birth);
    while (!checkValidNum::isValidBirth(birth, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ngay thanh lap: ";
        getline(cin, birth);
        errorMsg.clear();
    }
    cout << "Nhap email: ";
    getline(cin, mail);
    while (!checkValidWord::isValidEmail(mail, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai email: ";
        getline(cin, mail);
        errorMsg.clear();
    }
    cout << "Nhap ID truong khoa: ";
    getline(cin, idDean);
    while (!checkValidWord::isValidID(idDean, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai ID truong khoa: ";
        getline(cin, idDean);
        errorMsg.clear();
    }
    s->setName(name);
    s->setBirth(birth);
    s->setId(id);
    s->setMail(mail);
    
    LecturerDatabase& lecDB = LecturerDatabase::getInstance();
    int index = lecDB.find(idDean);
    BaseEntity* deanPtr = nullptr;
    Faculty f; 

    if (index >= 0){
        deanPtr = lecDB.getData(index);
        s->setDean(*dynamic_cast<Lecturer*>(deanPtr));
    }
    else {
        //Truong khoa not found => Set NULL for truong khoa
        Lecturer zombie;
        zombie.setId("NULL");
        zombie.setName("NULL");
        zombie.setBirth("01/01/01");
        s->setDean(zombie);
    }
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

