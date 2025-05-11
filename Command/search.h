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

class SearchStrategy{
public:
    SearchStrategy() = default;
    virtual ~SearchStrategy() = default;

    virtual vector<BaseEntity*> search(IDatabase* database, const string& keySearch) = 0;
};

class IdSearch: public SearchStrategy{
public:
    vector<BaseEntity*> search(IDatabase* database, const string& id);
};

class NameSearch: public SearchStrategy{
    vector<BaseEntity*> search(IDatabase* database, const string& name);
};






#endif