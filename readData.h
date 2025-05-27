#ifndef _READDATA_H
#define _READDATA_H
#include <string> 
#include <sstream>
#include <fstream>
#include "data.h"
#include "Entity/student.h"
#include "Entity/lecturer.h"
#include "Entity/faculty.h"
#include "Entity/baseEntity.h"
#include "Entity/check.h" //kiểm lỗi dữ liệu
#include<exception> //kiểm lỗi dữ liệu
#include<stdexcept> //kiểm lỗi: sử dụng throw runtime_error
#include <iostream>
using std::getline;
using std::exception, std::runtime_error;
using std::ifstream, std::ofstream;
using std::string, std::stringstream;

class IReadData{
public:
    virtual ~IReadData() = default;
};

// All concrete implementations of IReadData are designed following the Singleton design pattern.
class FacultyReadData: public IReadData {
private:
    FacultyReadData() = default; 
    FacultyReadData(const FacultyReadData&) = delete;
    FacultyReadData& operator= (const FacultyReadData&) = delete; 
    ~FacultyReadData() = default;
    ifstream _fileIn; //There is a possibility that program read multiple of files each, so i wont create a class to singleton the ifstream. 
public:
    static FacultyReadData& getInstance(){
        static FacultyReadData instance;
        return instance;
    };
    void readData(const string& filename);
};


class LecturerReadData : public IReadData{
private:
    LecturerReadData() = default;
    LecturerReadData(const LecturerReadData&) = delete;
    LecturerReadData& operator= (const LecturerReadData&) = delete; //for singleton -> No obj assignment ~ no copy constructor
    ~LecturerReadData() = default;
    ifstream _fileIn;
public:
    static LecturerReadData& getInstance(){
        static LecturerReadData instance;
        return instance;
    };
    void readData(const string& filename); 
};

class StudentReadData : public IReadData {
private:
    StudentReadData() = default;
    StudentReadData(const StudentReadData&) = delete;
    StudentReadData& operator= (const StudentReadData&) = delete;
    ~StudentReadData() = default;
    ifstream _fileIn;
public:
    static StudentReadData& getInstance(){
        static StudentReadData instance;
        return instance;
    };
    void readData(const string& filename);
};
#endif