#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include "student.h"
#include "lecturer.h"
#include "faculty.h"
#include "baseEntity.h"
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
    int getSize() const;
    Student* getData(const int&);
    friend class StudentDatabaseDisplay;
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
    Lecturer& getData(const int& index);
    int find_obj(const string& id) const;
    friend class LecturerDatabaseDisplay;
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
    };
    string getDataType() const override;

    friend class FacultyReadData;
    friend class FacultyDatabaseDisplay;
};


#endif