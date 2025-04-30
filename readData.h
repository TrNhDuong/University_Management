#ifndef _READDATA_H
#define _READDATA_H
#include"data.h"
#include<string> 
#include<sstream>
#include<fstream>

using std::ifstream, std::ofstream;
using std::string, std::stringstream;

class IGetData{
public:
    virtual ~IGetData() = default;
};

class FacultyReadData: public IGetData {
private://singleton, create only 1 object
    FacultyReadData() = default; 
    FacultyReadData(const FacultyReadData&) = delete; //for singleton
    FacultyReadData& operator= (const FacultyReadData&) = delete; //for singleton
    ifstream _fileIn;

public:
    static FacultyReadData& getInstance();
    void readData(const string& filename);
};



class StudentGetData : public IGetData {

};

class InstructorGetData : public IGetData{

};

#endif