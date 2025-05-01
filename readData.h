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
    ifstream _fileIn;

public:
    static FacultyReadData& getInstance();
    void readData(const string& filename);
};



class StudentGetData : public IReadData {

};

class InstructorGetData : public IReadData{

};

#endif