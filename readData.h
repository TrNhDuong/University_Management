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
private://singleton
    static unique_ptr<FacultyReadData> _instance;  //using smart pointer -> auto free memory
    FacultyReadData() = default; 
    FacultyReadData(const FacultyReadData&) = delete; //for singleton -> No copy constructor
    FacultyReadData& operator= (const FacultyReadData&) = delete; //for singleton -> No obj assignment ~ no copy constructor
    ifstream _fileIn; 

public:
    static FacultyReadData* getInstance();
    void readData(const string& filename);
};

class LecturerReadData : public IReadData{
private: //singleton
    static unique_ptr<LecturerReadData> _instance;
    LecturerReadData() = default;
    LecturerReadData(const LecturerReadData&) = delete; 
    LecturerReadData& operator= (const LecturerReadData&) = delete; 
    ifstream _fileIn;
public:
    static LecturerReadData* getInstance();
    void readData(const string& filename); 
};

class StudentReadData : public IReadData {
private:
    static unique_ptr<StudentReadData> _instance;
    StudentReadData() = default;
    StudentReadData(const StudentReadData&) = delete;
    StudentReadData& operator= (const StudentReadData&) = delete;
    ifstream _fileIn;
public:
    static StudentReadData* getInstance();
    void readData(const string& filename);
};


#endif