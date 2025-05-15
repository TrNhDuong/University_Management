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

#pragma region IDatabase declaration
class IDatabase{
public:
    virtual string getDataType() const = 0;
    virtual int getSize() const = 0;

    virtual void Add(BaseEntity*) = 0;
    virtual bool Remove(BaseEntity*) = 0;
    virtual bool Remove(const string& id) = 0;
    virtual int find(const string& id) const = 0;
    virtual bool Replace(BaseEntity* des, BaseEntity* scr) = 0;
    virtual BaseEntity* getData(const int&) = 0;

    virtual ~IDatabase() = default;
};

#pragma endregion

//CRTP (Curiously Recurring Template Pattern) + IDatabase + Template ->Need Optimization

#pragma region StudentDatabase declaration
class StudentDatabase: public IDatabase{
private:
    vector<Student> _data;
    StudentDatabase() = default; 
    ~StudentDatabase() override = default;
    StudentDatabase(const StudentDatabase&) = delete;
    Student& operator = (const StudentDatabase&) = delete;
public:
    static StudentDatabase& getInstance(){
        static StudentDatabase instance;
        return instance;
    }

    string getDataType() const override;
    int getSize() const override;
    int find(const string& id) const override;

    void Add(BaseEntity* obj) override;
    bool Remove(const string& ID) override; //return true if remove succesfully, return false if ID not found
    bool Remove(BaseEntity* obj) override; ///return true if remove succesfully, return false if ID not found
    bool Replace(BaseEntity* des, BaseEntity* src) override; //return true if remove succesfully, return false if des not found

    BaseEntity* getData(const int& index) override;
    
    friend class StudentReadData;
};
#pragma endregion



#pragma region LecturerDatabase declaration

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
    int getSize() const override;
    int find(const string& id) const; //-1 if not exists

    void Add(BaseEntity* obj) override;
    bool Remove(const string& ID) override;
    bool Remove(BaseEntity* obj) override;
    bool Replace(BaseEntity* des, BaseEntity* src) override;

    BaseEntity* getData(const int& index) override;
    friend class LecturerReadData;
};

#pragma endregion


#pragma region FacultyDatabase declaration

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
    int getSize() const override;
    int find(const string& id) const override;

    void Add(BaseEntity* object) override;
    bool Remove(const string& ID) override;
    bool Remove(BaseEntity* obj) override;
    bool Replace(BaseEntity* des, BaseEntity* src) override;

    BaseEntity* getData(const int& index) override;
    
    friend class FacultyReadData;
};

#pragma endregion

#endif