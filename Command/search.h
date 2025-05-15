#ifndef SEARCH_H
#define SEARCH_H
#include "../Entity/baseEntity.h"
#include "../data.h"
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
    IdSearch() = default;
    ~IdSearch() = default;
    vector<BaseEntity*> search(IDatabase* database, const string& id) override;
};

class NameSearch: public SearchStrategy{
public:
    NameSearch() = default;
    ~NameSearch() = default;
    vector<BaseEntity*> search(IDatabase* database, const string& name) override;
};

#endif