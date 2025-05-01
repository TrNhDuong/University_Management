#ifndef _READDATA_H
#define _READDATA_H
#include"data.h"
#include<string> 
#include<sstream>
#include<fstream>

using std::ifstream, std::ofstream;
using std::string, std::stringstream;

class IReadData{
public:
    virtual ~IReadData() = default;
};

class FacultyReadData: public IReadData {
private://singleton, create only 1 object
    FacultyReadData() = default; 
    FacultyReadData(const FacultyReadData&) = delete; //for singleton
    FacultyReadData& operator= (const FacultyReadData&) = delete; //for singleton
    ifstream _fileIn; //There is a possibility that programm read multiple of files, so i wont create a class to singleton the ifstream. 

public:
    static FacultyReadData& getInstance();
    void readData(const string& filename);
};

<<<<<<< HEAD
class LecturerReadData : public IReadData{
private: //singleton
    LecturerReadData() = default;
    LecturerReadData(const LecturerReadData&) = delete; //for singleton -> No copy constructor
    LecturerReadData& operator= (const LecturerReadData&) = delete; //for singleton -> No obj assignment ~ no copy constructor
    ifstream _fileIn;
public:
    static LecturerReadData& getInstance();
    void readData(const string& filename); 
};

class StudentReadData : public IReadData {
private:
    StudentReadData() = default;
    StudentReadData(const StudentReadData&) = delete;
    StudentReadData& operator= (const StudentReadData&) = delete;
    ifstream _fileIn;
public:
    static StudentReadData& getInstance();
    void readData(const string& filename);
};


#endif