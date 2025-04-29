#ifndef _FACULTY_H_
#define _FACULTY_H_
#include "baseEntity.h"
#include "instructor.h"
#include <string>
#include <iostream>
#include <vector>

using std::string, std::vector;

class Faculty : public BaseEntity{
protected:
    string _email;
    Instructor _dean;
public:
    string getType() const;
    string getMail() const;
    Instructor getDean() const;
    void setMail(const string& mail);
    void setDean(const Instructor& dean);

    Faculty();
    ~Faculty();
};

class FacultyInfo{
    public:
        static void printFacultyInfo(const Faculty& faculty);
        static Faculty getInfo();
};

class FacultyData{
    public:
        static vector<Faculty> _data;
    public:
        static void addFaculty(Faculty& faculty);
        static void removeFaculty(Faculty& faculty);
        static void replaceFaculty(Faculty& oldFaculty, Faculty& newFaculty);
};

template <class T>
void addData(vector<T>& data, T& newData){
    data.push_back(newData);
}

template <class T>
void removeData(vector<T>& data, T& remove){
    vector<T> newList;
    for (const T&x: data){
        if (x.getId() != remove.getId()){
            newList.push_back(x);
        }
    }
    data = newList;
}

template <class T>
void replaceData(vector<T>& data, T& oldData, T& newData){
    vector<T> newList;
    for (const T&x: data){
        if (x.getId() != oldData.getId()){
            newList.push_back(x);
        }else{
            newList.push_back(newData);
        }
    }
    data = newList;
}

#endif