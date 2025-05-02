#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include "student.h"
#include "lecturer.h"
#include"faculty.h"
//#include"readData.h" ////getdata from database
#include <string>
using std::vector;
using std::string;


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
    int find_obj(const string& id) const; //return the index in vector _data, it is necessary (can't use friend to lecturer => invalid action harm to capsulation)
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