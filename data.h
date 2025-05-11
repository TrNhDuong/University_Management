#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"
#include <exception>
#include <string>
#include <fstream>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::fstream;

class IDatabase{
public:
    virtual string getDataType() const = 0;
    virtual ~IDatabase() = default;
};

//CRTP (Curiously Recurring Template Pattern) + IDatabase + Template ->Need Optimization

class StudentDatabase: public IDatabase{
private:
    vector<Student> _data;
    StudentDatabase() = default; 
    ~StudentDatabase() override = default;
    StudentDatabase(const StudentDatabase&) = delete;
    Student& operator = (const StudentDatabase&) = delete;
public:
    string getDataType() const override;
    static StudentDatabase& getInstance(){
        static StudentDatabase instance;
        return instance;
    }

    

    //need CRTL
    int find(const string& id) const;
    void Add(const Student& obj);
    bool Remove(const string& ID); //return true if remove succesfully, return false if ID not found
    bool Remove(Student& obj); ///return true if remove succesfully, return false if ID not found
    bool Replace(Student& des, Student& src); //return true if remove succesfully, return false if des not found

    int getSize() const;
    Student* getData(const int& index);
    
    friend class StudentReadData;
};

class LecturerDatabase: public IDatabase{
private:
    vector<Lecturer> _data;
    LecturerDatabase() = default; 
    ~LecturerDatabase() = default;
    LecturerDatabase(const LecturerDatabase&) = delete;
    LecturerDatabase& operator = (const LecturerDatabase&) = delete;
public:
    static LecturerDatabase& getInstance(){
        static LecturerDatabase instance;
        return instance;
    }
    string getDataType() const override;
    
    Lecturer* getData(const int& index);
    int find(const string& id) const; //return the index in vector _data, it is necessary (can't use friend to lecturer => invalid action harm to capsulation)
    
    void Add(const Lecturer& obj);
    bool Remove(const string& ID);
    bool Remove(Lecturer& obj);
    bool Replace(Lecturer& des, Lecturer& src);
    int getSize() const;

    friend class LecturerReadData;
};


class FacultyDatabase: public IDatabase{
private:
    vector<Faculty> _data;
    FacultyDatabase() = default;
    ~FacultyDatabase() = default;
    FacultyDatabase(const FacultyDatabase&) = delete;
    FacultyDatabase& operator = (const FacultyDatabase&) = delete;
public:
    static FacultyDatabase& getInstance(){
        static FacultyDatabase instance;
        return instance;
    }
    string getDataType() const override;

    Faculty* getData(const int& index);
    int find(const string& id) const;
    int getSize() const;
    void Add(const Faculty& obj);
    bool Remove(const string& ID);
    bool Remove(Faculty& obj);
    bool Replace(Faculty& des, Faculty& src);
    
    friend class FacultyReadData;
};


#endif