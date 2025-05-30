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
    StudentDatabase& DB = StudentDatabase::getInstance();
    BaseEntity* ans = nullptr;
    Student* s = new Student();

    string name, id, birth, errorMsg, mail; 
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
    // int index = DB.find(id);
    while (!checkValidWord::isValidID(id, errorMsg) || DB.find(id) != -1){
        if (errorMsg != "")
            cout << errorMsg << '\n';
        if (DB.find(id) != -1)
            cout << "Id da ton tai\n";
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

    //lấy index của năm sinh trong birth
    int index = 0;
    bool isMeet = false;
    for (index = 0; index < birth.length(); ++index){
        if (birth[index] == '/' && isMeet){
            break;
        }
        else if (birth[index] == '/'){
            isMeet = true;
        }
    }
    int yearBirth = stoi(birth.substr(index+1,birth.length()-1)); //Lấy năm sinh từ chuỗi birth
   
    cout << "Nhap nam nhap hoc: ";
    string tempEnrollYear = "";
    getline(cin, tempEnrollYear);
    int cnt = 0;
    while (!checkValidNum::isValidYearEnroll(tempEnrollYear, errorMsg, yearBirth) && cnt < 6){
        cout << errorMsg << '\n';
        cout << "Nhap lai nam nhap hoc: ";
        tempEnrollYear ="";
        getline(cin, tempEnrollYear);
        errorMsg.clear();
        cnt++;
    }
    if (cnt == 3){
        cout << "Ban da nhap sai qua 3 lan\n";
        getch();
        return nullptr;
    }
    //Avoid being inf loop when birth year >= 2011
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

    cout << "Nhap mail: ";
    getline(cin, mail);
    cnt = 0;
    while (!checkValidWord::isValidEmail(mail, errorMsg) && cnt < 3){
        cout << errorMsg << '\n';
        cout << "Nhap lai mail: ";
        getline(cin, mail);
        errorMsg.clear();
        cnt++;
    }
    if (cnt == 3){
        cout << "Ban da nhap sai qua 3 lan\n";
        getch();
        return nullptr;
    }

    //set data for Student
    s->setName(name);
    s->setBirth(birth);
    s->setId(id);
    s->setEnrollYear(enrollYear);
    s->setGPA(gpa);
    s->setCredit(credit);
    s->setMail(mail);
    ans = s;
    return ans;

}

#pragma endregion

#pragma region LecturerInput

BaseEntity* LecturerInput::input(){
    LecturerDatabase& DB = LecturerDatabase::getInstance();
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
    // int index = DB.find(id);
    while (!checkValidWord::isValidID(id, errorMsg) || DB.find(id) != -1){
        if (errorMsg != "")
            cout << errorMsg << '\n';
        if (DB.find(id) != -1)
            cout << "Id da ton tai\n";
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


    //lấy index của năm sinh trong birth
    int index = 0;
    bool isMeet = false;
    for (index = 0; index < birth.length(); ++index){
        if (birth[index] == '/' && isMeet){
            break;
        }
        else if (birth[index] == '/'){
            isMeet = true;
        }
    }
    int yearBirth = stoi(birth.substr(index+1,birth.length()-1)); //Lấy năm sinh từ chuỗi birth
   // cout <<yearBirth <<" - year birth " << std::endl;
    cout << "Nhap nam bat dau giang day: ";
    getline(cin, structYear);
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
    string mail;
    cout << "Nhap mail: ";
    getline(cin, mail);
    while (!checkValidWord::isValidEmail(mail, errorMsg)){
        cout << errorMsg << '\n';
        cout << "Nhap lai mail: ";
        getline(cin, mail);
        errorMsg.clear();
    }

    cin.ignore();
    s->setName(name);
    s->setBirth(birth);
    s->setId(id);
    s->setInstructYear(stoi(structYear));
    s->setDeg(degree);
    s->setMail(mail);
    ans = s;
    return ans;
}

#pragma endregion

#pragma region FacultyInput

BaseEntity* FacultyInput::input(){
    FacultyDatabase& DB = FacultyDatabase::getInstance();
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
    //int index = DB.find(id);
    while (!checkValidWord::isValidID(id, errorMsg) || DB.find(id) != -1){
        if (errorMsg != "")
            cout << errorMsg << '\n';
        if (DB.find(id) != -1)
            cout << "Id da ton tai\n";
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

