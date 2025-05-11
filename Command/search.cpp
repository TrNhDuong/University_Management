#include "search.h"


BaseEntity* SearchStudent::search(IDatabase* database, const string& id){
    BaseEntity* object = nullptr;
    StudentDatabase* studentDB = dynamic_cast<StudentDatabase*>(database);
    int n = studentDB->getSize();
    for (int i = 0; i < n; i++)
        if (studentDB->getData(i)->getId() == id){
            object = studentDB->getData(i);
            break;
        }
    return object;
}

vector<BaseEntity*> SearchStudent::searchName(IDatabase* database, const string& name){
    vector<BaseEntity*> ans;
    StudentDatabase* studentDB = dynamic_cast<StudentDatabase*>(database);
    int n = studentDB->getSize();
    for (int i = 0; i < n; i++)
        if (studentDB->getData(i)->getName().find(name) != std::string::npos){
            ans.push_back(studentDB->getData(i));
        }
    return ans;
}

BaseEntity* SearchLecturer::search(IDatabase* database, const string& id){
    BaseEntity* object = nullptr;
    LecturerDatabase* lecturerDB = dynamic_cast<LecturerDatabase*>(database);
    int n = lecturerDB->getSize();
    for (int i = 0; i < n; i++)
        if (lecturerDB->getData(i)->getId() == id){
            object = lecturerDB->getData(i);
            break;
        }
    return object;
}

vector<BaseEntity*> SearchLecturer::searchName(IDatabase* database, const string& name){
    vector<BaseEntity*> ans;
    LecturerDatabase* studentDB = dynamic_cast<LecturerDatabase*>(database);
    int n = studentDB->getSize();
    for (int i = 0; i < n; i++)
        if (studentDB->getData(i)->getName().find(name) != std::string::npos){
            ans.push_back(studentDB->getData(i));
        }
    return ans;
}