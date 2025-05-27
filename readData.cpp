#include "readData.h"

#pragma region readFacultyData
void FacultyReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file "<< filename <<"\n";
        return;
    }
    //read file
    string line;
    LecturerDatabase& lecDB = LecturerDatabase::getInstance();
    while(getline(_fileIn,line)){
        stringstream ss(line);
        string name = "", id = "", birth = "", email = "", deanID = ""; 
        //Managing the invalid data
        string ignore = "";

        //FORMAT Falcuty data:
                    // name|id|birth|email|deanID
        getline(ss, name,'|');
        if (checkValidWord::isValidStr(name,ignore) == false){
            //Invalid name
            throw runtime_error("Nội dung của file Falcuty, tên không đúng định dạng");
        }
        getline(ss, id,'|');
        if (checkValidWord::isValidID(id,ignore) == false){
            //Invalid ID
            throw runtime_error("Nội dung của file Falcuty, ID không đúng định dạng");
        }
        getline(ss, birth,'|');
        if (checkValidNum::isValidBirth(birth,ignore)==false){
            //Invalid birth
            throw runtime_error("Nội dung của file Falcuty, ngày thành lập không đúng định dạng");
        }

        getline(ss, email,'|');
        if (checkValidWord::isValidEmail(email,ignore) == false){
            //Invalid email
            throw runtime_error("Nội dung của file Falcuty, email không đúng định dạng");
        }

        getline(ss, deanID,'|');
       if (checkValidWord::isValidID(deanID,ignore) == false){
        //Invalid deanID
            throw runtime_error("Nội dung của file Falcuty, ID trưởng khoa không đúng định dạng");
        }

        //find the Lectuer base on the deanID above
          // dùng singleton
        int index = lecDB.find(deanID);
        BaseEntity* deanPtr = nullptr;
        Faculty f; 
   
        if (index >= 0){
            deanPtr = lecDB.getData(index);
            f.setDean(*dynamic_cast<Lecturer*>(deanPtr));
        }
        else {
            //Truong khoa not found => Set NULL for truong khoa
            Lecturer zombie;
            zombie.setId("NULL");
            zombie.setName("NULL");
            zombie.setBirth("01/01/01");
            f.setDean(zombie);
        }
        f.setName(name);
        f.setId(id);
        f.setBirth(birth);       
        f.setMail(email);
        FacultyDatabase& facultyDB = FacultyDatabase::getInstance();
        facultyDB._data.push_back(f);
    } 
    
    _fileIn.close(); //close file
}

#pragma endregion 

#pragma region readLecturerData
void LecturerReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file " << filename <<"\n";
        return;
    }
    string line;
    LecturerDatabase& lecturerDB = LecturerDatabase::getInstance();
    while(getline(_fileIn,line)){
        stringstream ss(line); //builder pattern
        string name = "", id = "", birth = "", year_instruct = "", deg = "", mail ="";
      
        //Format Lecturer file: name|id|birth|year_instruct|degree
        //Managing the invalid data
        string ignore = "";
        getline(ss,name,'|');
        if (checkValidWord::isValidStr(name,ignore) == false){
            //Invalid name
            throw runtime_error("Nội dung của file Lecturer tên không đúng định dạng");
        }
        getline(ss,id,'|'); 
        if (checkValidWord::isValidID(id,ignore) == false){
            //Invalid ID
            throw runtime_error("Nội dung của file Lecturer, ID không đúng định dạng");
        }
        getline(ss,birth,'|'); 
        if( checkValidNum::isValidBirth(birth,ignore) == false){
            //Invalid birth
            throw runtime_error("Nội dung của file Lecturer, ngày sinh không đúng định dạng");
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
   
        getline(ss,year_instruct,'|'); ; 
        if( checkValidNum::isValidInstructYear(year_instruct,ignore, yearBirth) == false){
            //Invalid year instruct
           // std::cout << "\n" << year_instruct << "\n";
            throw runtime_error("Nội dung của file Lecturer, năm hướng dẫn/Year instruct không đúng định dạng");
        }
        getline(ss,deg, '|'); 
        if (checkValidWord::isValidStr(deg,ignore) == false){
            //Invalid degree
            throw runtime_error("Nội dung của file Lecturer, Bằng cấp không đúng định dạng");
        }
        getline(ss,mail);
        if( checkValidWord::isValidEmail(mail,ignore) == false){
            //Invalid email
            throw runtime_error("Nội dung của file Lecturer, email không đúng định dạng");
        }

        Lecturer new_person;
        new_person.setName(name);
        new_person.setId(id);
        new_person.setBirth(birth);
        new_person.setInstructYear(stoi(year_instruct));
        new_person.setDeg(deg);
        new_person.setMail(mail);
        //push into vector
        lecturerDB._data.push_back(new_person);
    }
    _fileIn.close();
}
#pragma endregion

#pragma region readStudentData

void StudentReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file " << filename <<"\n";
        return;
    }
    //Format Student file: name|id|birth|year|gpa|credit|mail
    string line;
    StudentDatabase& studentDB = StudentDatabase::getInstance();
    while(getline(_fileIn,line)){
        stringstream ss(line); //builder pattern
        string name = "", id, birth = "", year = "", gpa = "",credit = "", mail = "";
        
        //FORMAT Student data: Name|ID|Birth|Year|GPA|Credit|Mail
        //Managing the invalid data
        string ignore = "";
        getline(ss,name,'|');
        if (checkValidWord::isValidStr(name,ignore) == false){
            //Invalid name
            throw runtime_error("Nội dung của file Student, tên không đúng định dạng");
        }
        getline(ss,id,'|'); 
        if (checkValidWord::isValidID(id,ignore) == false){
            //Invalid ID
            throw runtime_error("Nội dung của file Student, ID không đúng định dạng");
        }
        getline(ss,birth,'|'); 
        if (checkValidNum::isValidBirth(birth,ignore) == false){
            //Invalid birth
            throw runtime_error("Nội dung của file Student, ngày sinh không đúng định dạng");
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
        getline(ss,year,'|');
        if (checkValidNum::isValidYearEnroll(year,ignore, yearBirth) == false){
            //Invalid year'
          //  std::cout <<"\n\n" << year << endl << endl;
            throw runtime_error("Nội dung của file Student, năm nhập học không đúng định dạng");
        }
        getline(ss,gpa,'|');  
        if (checkValidNum::isValidGPA(gpa,ignore) == false){
            //Invalid GPA
            throw runtime_error("Nội dung của file Student, GPA không đúng định dạng");
        }
        getline(ss,credit,'|');
        if (checkValidNum::isValidCredit(credit,ignore) == false){
            //Invalid credit
            throw runtime_error("Nội dung của file Student, số tín chỉ không đúng định dạng");
        }

        getline(ss,mail,'|'); //dont't have email in Student file yet
        if (checkValidWord::isValidEmail(mail,ignore) == false){
            //Invalid email
            throw runtime_error("Nội dung của file Student, email không đúng định dạng");
        }
        Student new_person;
        new_person.setName(name);
        new_person.setId(id);
        new_person.setBirth(birth);
        new_person.setEnrollYear(stoi(year));
        new_person.setGPA(stof(gpa));
        new_person.setCredit(stoi(credit));
        new_person.setMail(mail);
        studentDB._data.push_back(new_person);
    }
    _fileIn.close();
}
#pragma endregion

