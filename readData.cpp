#include "readData.h"

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
        string name, id, birth, email, deanID; 
        //seperate - Lack of managing the invalid data 
        getline(ss, name,'|');
        getline(ss, id,'|');
        getline(ss, birth,'|');
        getline(ss, email,'|');
        getline(ss, deanID);
        //find the Lectuer base on the deanID above
          // dùng singleton
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
        f.setName(name);
        f.setId(id);
        f.setBirth(birth);       
        f.setMail(email);
        FacultyDatabase& facultyDB = FacultyDatabase::getInstance();
        facultyDB._data.push_back(f);
    } 
    
    _fileIn.close(); //close file
}


void LecturerReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file " << filename <<"\n";
        return;
    }
    //read file: name|id|birth|year_instruct|degree
    string line;
    LecturerDatabase& lecturerDB = LecturerDatabase::getInstance();
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

        Lecturer new_person;
        new_person.setName(name);
        new_person.setId(id);
        new_person.setBirth(birth);
        new_person.setInstructYear(stoi(year_instruct));
        new_person.setDeg(deg);
        //push into vector
        lecturerDB._data.push_back(new_person);
    }
    _fileIn.close();
}

void StudentReadData::readData(const string& filename){
    _fileIn.open(filename);
    if (_fileIn.is_open() == false){
        std::cout <<"Can't open file " << filename <<"\n";
        return;
    }
    //read file: name|id|birth|year|gpa|credit
    string line;
    StudentDatabase& studentDB = StudentDatabase::getInstance();
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

        Student new_person;
        new_person.setName(name);
        new_person.setId(id);
        new_person.setBirth(birth);
        new_person.setEnrollYear(stoi(year));
        new_person.setGPA(stof(gpa));
        new_person.setCredit(stoi(credit));
        studentDB._data.push_back(new_person);
    }
    _fileIn.close();
}



