#ifndef SAVE_DATA_H
#define SAVE_DATA_H
#include "data.h"
#include <fstream>

class ISaveData{
protected:
    IDatabase* database;
public:
    ISaveData() = default;
    virtual ~ISaveData() = default;

    virtual void excute() = 0;
};

class SaveStudentData: public ISaveData{
public:
    SaveStudentData() = default;
    SaveStudentData(IDatabase* db){
        database = db;
    }
    void excute() override;
};

class SaveLecturerData: public ISaveData{
public:
    SaveLecturerData() = default;
    SaveLecturerData(IDatabase* db){
        database = db;
    }
    void excute() override;
};

class SaveFacultyData: public ISaveData{
public:
    SaveFacultyData() = default;
    SaveFacultyData(IDatabase* db){
        database = db;
    }
    void excute() override;
};

class SaveDataFactory{
public:
    static ISaveData* create(const string& type);
};
#endif