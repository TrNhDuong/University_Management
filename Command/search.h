#ifndef SEARCH_H
#define SEARCH_H
#include "../Entity/baseEntity.h"
#include "../data.h"
#include "../manageSystem.h"
#include <vector>
#include <memory>
#include <string>
using std::vector;
using std::string;

class ISearch{
public:
    virtual BaseEntity* search(IDatabase* database, const string& id) = 0;
    virtual vector<BaseEntity*> searchName(IDatabase* database, const string& id) = 0;
    virtual ~ISearch() = default;
};

class SearchStudent: public ISearch{
public:
    BaseEntity* search(IDatabase* database, const string& id) override;
    vector<BaseEntity*> searchName(IDatabase* database, const string& name) override;
};


class SearchLecturer: public ISearch{
public:
    BaseEntity* search(IDatabase* database, const string& id) override;
    vector<BaseEntity*> searchName(IDatabase* database, const string& name) override;
};

class SearchFactory{
public:
    static ISearch* createSearch(const string& type){
        if ("Student" == type)
            return new SearchStudent();
        else if ("Lecturer" == type)
            return new SearchLecturer();
        return nullptr;
    }
};


#endif