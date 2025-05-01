#include"readData.h"
#include"faculty.h"
#include<iostream>

using std::getline;

//For Faculty

FacultyReadData& FacultyReadData:: getInstance(){ //return the single obj
    static FacultyReadData instance;
    return instance;
    /* How to use 
    FacultyReadData& f = FacultyReadData::getInstance(); 
    f.readData("faculty.txt");*/
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

//For Lecturer
LecturerReadData& LecturerReadData::getInstance(){
    static LecturerReadData instance;
    return instance;
}

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
        getline(ss,deg,'|'); 
        //managing the invalid data ?

        //builder pattern
        Lecturer new_person = LecturerBuilder()
                                .setName(name)
                                .setID(id)
                                .setInstructYear(year_instruct)
                                .setDegree(deg)
                                .build();
        //push into vector
        LecturerDatabase::_data.push_back(new_person);
    }
    _fileIn.close();
}

//For Student
StudentReadData& StudentReadData::getInstance(){
    static StudentReadData instance;
    return instance;
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
        getline(ss,credit,'|'); 
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



