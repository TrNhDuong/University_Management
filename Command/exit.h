#ifndef SAVE_DATA_H
#define SAVE_DATA_H
#include "../data.h"
#include <fstream>
#include <map>
using std::map;

class ISaveData{
protected:
    IDatabase* database;
public:
    ISaveData() = default;
    virtual ~ISaveData() = default;

    virtual void execute() = 0;
};

class SaveStudentData: public ISaveData{
public:
    SaveStudentData() = default;
    SaveStudentData(IDatabase* db){
        database = db;
    }
    void execute() override;
};

class SaveLecturerData: public ISaveData{
public:
    SaveLecturerData() = default;
    SaveLecturerData(IDatabase* db){
        database = db;
    }
    void execute() override;
};

class SaveFacultyData: public ISaveData{
public:
    SaveFacultyData() = default;
    SaveFacultyData(IDatabase* db){
        database = db;
    }
    void execute() override;
};

class SaveDataFactory{
public:
    static ISaveData* create(const string& type, map<string, IDatabase*> DB);
};
#endif