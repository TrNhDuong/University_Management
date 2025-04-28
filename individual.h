#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_
#include <string>
using std::string;

class Birth{
private:
    int _day, _month, _year;
public:
    Birth();
    ~Birth();
    void setBirth(const int& d, const int& m, const int& y);
    void setBirth(const string&);
    int getDay() const;
    int getMonth() const;
    int getYear() const ;
};

class Individual{
protected:
    string _name;
    string _id;
    Birth _birthDay;
public:
    string getName() const;
    string getId() const;
    Birth getBirth() const;
    void setName(const string& name);
    void setId(const string& id);
    void setBirth(const Birth& birthDay);
    void setBirth(const string&);
    Individual();
    virtual ~Individual();
};
#endif