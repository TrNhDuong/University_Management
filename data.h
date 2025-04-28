#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include "student.h"
#include "instructor.h"
#include "faculty.h"
#include <string>
using std::vector;
using std::string;

//Intention for the future:
/*The class Student db, Lecturer/Instructor db and Falcuty db
will be included into an abstract class: Database */

//for student 
class StudentDatabase{
protected:
    static vector<Student> _dataBase; //singleton
public:
    int getSize() const;
    Student& getData(const int& index) const;
    void add(const Student& value); // using push_back
    void delete_obj ( Student& value); //find the iterator/index of value and using erase
    
    friend class StudentDatabaseDisplay;
    friend class StudentDatabaseGetData;
};

class StudentDatabaseDisplay{
public:
    static void display(const StudentDatabase& studentDtb);
};

class StudentDatabaseGetData{
public:
    static Student readLine(const string& inputLine);
    static StudentDatabase read(const string& inputFile); //read file
};


//for Instructor/Lecturer

class InstructorDatabase {
protected:
    static vector<Instructor> _dataBase;
public:
    int getSize() const;
    Instructor& getData(const int& index) const;
    void add(const Instructor& value); // using push_back
    void delete_obj( Instructor& value); //find the iterator/index of value and using erase
    
    friend class InstructorDatabaseDisplay;
    friend class InstructorDatabaseGetData;
};

class InstructorDatabaseDisplay{
    public:
    static void display(const InstructorDatabase& inputLine);
};
class InstructorDatabaseGetData {
    public:
    static Instructor readLine(const string& inputLine); //read each line
    static InstructorDatabase read(const string& inputFile); //read fine
};

//for Falcuty

class FacultyDatabase {
protected:
    static vector<Faculty> _dataBase;
public:
    int getSize() const;
    Faculty& getData(const int& index) const;
    void add(const Faculty& value);
    void delete_obj(Faculty& value);
    
    friend class FacultytDatabaseDisplay;
    friend class FalcutyDatabaseGetData;
};

class FacultytDatabaseDisplay{
    public:
    static void display(const FacultyDatabase& inputLine);
};
class FacultytDatabaseGetData {
    public:
    static Faculty readLine(const string& inputLine); //read each line
    static FacultyDatabase read(const string& inputFile); //read fine to get database
};


#endif