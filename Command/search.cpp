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