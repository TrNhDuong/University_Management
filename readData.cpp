#include"readData.h"
#include"faculty.h"
#include<iostream>

using std::getline;

//For Lecturer: need to read comments carefully since the content of using smart pointer
unique_ptr<LecturerReadData> LecturerReadData::_instance = nullptr; //LecturerReadData::getInstance(); //declare the smart pointer
 LecturerReadData* LecturerReadData:: getInstance() {
    if (!_instance) {
        _instance = unique_ptr<LecturerReadData>(new LecturerReadData());
    }
    return _instance.get(); //return the base pointer: LecturerReadData*
}

/*                  HOW TO USE
    auto* reader1 = LecturerReadData::getInstance(); //to "create" an object base on smart pointer
    auto* reader2 = LecturerReadData::getInstance();
    
    //to read file
    reader1->readData("data.txt");
*/

void LecturerReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file " << filename <<"\n";
        return;
    }
    //read file: name|id|birth|year_instruct|degree
    string line;
    while(getline(_fileIn,line)){
        stringstream ss(line); //builder pattern
        string name, id, birth, year_instruct, deg;
        //seperate - Lack of managing the invalid data
        getline(ss,name,'|');
        getline(ss,id,'|'); 
        getline(ss,birth,'|'); 
        getline(ss,year_instruct,'|'); 
        getline(ss,deg); 
        //managing the invalid data ?

        //builder pattern
        Lecturer new_person ;
        new_person.setName(name);
        new_person.setId(id);
        new_person.setBirth(birth);
        new_person.setInstructYear(year_instruct);
        new_person.setDeg(deg);
        //push into vector
        LecturerDatabase::_data.push_back(new_person);
    }
    _fileIn.close();
}


//For Faculty
unique_ptr<FacultyReadData> FacultyReadData::_instance = nullptr; //declare the smart pointer 
FacultyReadData* FacultyReadData:: getInstance(){ //return the single obj
    if (!_instance) {
        _instance = unique_ptr<FacultyReadData>(new FacultyReadData());
    }
    return _instance.get(); 
}

void FacultyReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file "<< filename <<"\n";
        return;
    }
    //read file
    string line;
    while(getline(_fileIn,line)){
        stringstream ss(line);
        string name, id, birth, email, deanID; 
        //seperate - Lack of managing the invalid data 
        getline(ss, name,'|');
        getline(ss, id,'|');
        getline(ss, birth,'|');
        getline(ss, email,'|');
        getline(ss, deanID);

        //find the Lectuer base on the deanID above
        LecturerDatabase& lecDB = LecturerDatabase::getInstance();  // dùng singleton
        int index = lecDB.LecturerDatabase::find_obj(deanID); //finding base on ID
        Lecturer* deanPtr = nullptr;
        Faculty f; 
        if (index >= 0){
            deanPtr = &lecDB.getData(index); 
            f.setDean(*deanPtr);
        }
        else {
            //Truong khoa not found => Set NULL for truong khoa
            Lecturer zombie;
            zombie.setId("NULL");
            zombie.setName("NULL");
            zombie.setBirth("01/01/01");
            f.setDean(zombie);
        }
        f.setName(name); f.setId(id); f.setBirth(birth); f.setMail(email);
        FacultyDatabase::_data.push_back(f);
    } 
    
    _fileIn.close(); //close file
}




//For Student
unique_ptr<StudentReadData> StudentReadData::_instance = nullptr; //declare the smart pointer 
StudentReadData* StudentReadData:: getInstance(){ 
    if (!_instance) {
        _instance = unique_ptr<StudentReadData>(new StudentReadData());
    }
    return _instance.get(); 
}

void StudentReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file " << filename <<"\n";
        return;
    }
    //read file: name|id|birth|year|gpa|credit
    string line;
    while(getline(_fileIn,line)){
        stringstream ss(line); //builder pattern
        string name, id, birth, year, gpa,credit;
        //seperate - Lack of managing the invalid data
        getline(ss,name,'|');
        getline(ss,id,'|'); 
        getline(ss,birth,'|'); 
        getline(ss,year,'|');
        getline(ss,gpa,'|');  
        getline(ss,credit); 
        //managing the invalid data ?

        //push into vector
        Student new_person;
        new_person.setName(name);
        new_person.setId(id);
        new_person.setBirth(birth);
        //Lacking setter function for student
        //new_person.setYearEroll(stoi(year));
        //new_person.setGPA(stof(gpa));
        //new_person.setCredit(stoi(credit));
        StudentDatabase::_data.push_back(new_person);
    }
    _fileIn.close();
}



