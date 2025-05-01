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
    //virtual int find_obj(const string& id);

};
//Make all the subclass Database becomes singleton
class StudentDatabase: public IDatabase{
private:
    static vector<Student> _data;
public:
    string getDataType() const override;
    ~StudentDatabase() override = default; // may be "override" doesn't needed, but this help more virtual
    friend class StudentDatabaseDisplay;
    friend class StudentReadData;
};


class LecturerDatabase: public IDatabase{
private:
    static vector<Lecturer> _data;
    LecturerDatabase() = default; 
public:
    static LecturerDatabase& getInstance(){
        static LecturerDatabase instance;
        return instance;
    }
    
    string getDataType() const override;
    Lecturer& getData(const int& index) const;
    int find_obj(const string& id) const; //return the index in vector _data, it is necessary (can't use friend to lecturer => invalid action harm to capsulation)
    friend class LecturerDatabaseDisplay;
    friend class LecturerReadData;
};


class FacultyDatabase: public IDatabase{
private:
    static vector<Faculty> _data;
public:
    string getDataType() const override;
    friend class FacultyReadData; //it is "getData" from file 
    friend class FacultyDatabaseDisplay;
};


#endif