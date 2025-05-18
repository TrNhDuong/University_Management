#include "exit.h"

void SaveStudentData::execute(){
    std::fstream file("Data/StudentData.txt", std::ios::out);
    if (!file.is_open()){
        cout << "Khong ton tai file\n";
        return;
    }
    int n = database->getSize();
    for (int i = 0; i < n; i++){
        BaseEntity* object = database->getData(i);
        Student* stu = dynamic_cast<Student*>(object);
        file << stu->getName() << "|" << stu->getId() << "|" << stu->getBirth().getDay() << "/" << stu->getBirth().getMonth() 
        << "/" << stu->getBirth().getYear() << "|" << stu->getEnrollYear() << "|" << stu->getGPA() << "|" << stu->getCompletedCredit() << "|" << stu->getMail() << "\n";
    }
    file.close();
}

void SaveLecturerData::execute(){
    std::fstream file("Data/LecturerData.txt", std::ios::out);
    if (!file.is_open()){
        cout << "Khong ton tai file\n";
        return;
    }
    int n = database->getSize();
    for (int i = 0; i < n; i++){
        BaseEntity* object = database->getData(i);
        Lecturer* stu = dynamic_cast<Lecturer*>(object);
        file << stu->getName() << "|" << stu->getId() << "|" << stu->getBirth().getDay() << "/" << stu->getBirth().getMonth() 
        << "/" << stu->getBirth().getYear() << "|" << stu->getInstructYear() << "|" << stu->getDegree() << "|" << stu->getMail() << "\n";
    }
    file.close();
}

void SaveFacultyData::execute(){
    std::fstream file("Data/FacultyData.txt", std::ios::out);
    if (!file.is_open()){
        cout << "Khong ton tai file\n";
        return;
    }
    int n = database->getSize();
    for (int i = 0; i < n; i++){
        BaseEntity* object = database->getData(i);
        Faculty* stu = dynamic_cast<Faculty*>(object);
        file << stu->getName() << "|" << stu->getId() << "|" << stu->getBirth().getDay() << "/" << stu->getBirth().getMonth() 
        << "/" << stu->getBirth().getYear() << "|" << stu->getMail() << "|" << stu->getDean().getId() << "\n";
    }
    file.close();
}

ISaveData* SaveDataFactory::create(const string& type, map<string, IDatabase*> DB){
    if ("Student" == type){
        return new SaveStudentData(DB[type]);
    } else if ("Lecturer" == type){
        return new SaveLecturerData(DB[type]);
    } else if ("Faculty" == type){
        return new SaveFacultyData(DB[type]);
    }
    return nullptr;
}