#ifndef _SEARCH_H_
#define _SEARCH_H_
#include "Entity/baseEntity.h"
#include "data.h"
#include "../manageSystem.h"
#include <vector>
#include <unordered_map>
#include <memory>
using std::unordered_map;
using std::vector;

class ISearch{
public:
    virtual BaseEntity* search(IDatabase* database, const string& id) = 0;
    virtual ~ISearch() = default;
};

class SearchStudent: public ISearch{
public:
    BaseEntity* search(IDatabase* database, const string& id) override;
};

class SearchLecturer: public ISearch{
public:
    BaseEntity* search(IDatabase* database, const string& id) override;
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