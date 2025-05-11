#ifndef COMMAND_H
#define COMMAND_H
#include "search.h"
#include "display.h"
#include <map>
#include <memory>
#include <string>
using std::string;
using std::map;

class ICommand{
public:
    ICommand() = default;
    virtual string getCommandType() = 0;
    virtual void excute(map<string, IDatabase*>, string type) = 0;
    virtual ~ICommand();
};


class SearchFunction{
public:
    SearchFunction() = default;
    static void searchObjectById(IDatabase* database, const string& id);
    static void searchObjectByName(IDatabase* database, const string& name);
};

class SearchCommand: public ICommand{
    string _searchType;
    string _searchObject;
public:
    SearchCommand() = default;
    void setSearchData(const string& typeSearch, const  string& object){
        _searchType = typeSearch;
        _searchObject = object;
    }
    string getCommandType();
    void excute(map<string, IDatabase*>, string type);
};

class DisplayCommand: public ICommand{
public:
    DisplayCommand() = default;
    string getCommandType();

    void excute(map<string, IDatabase*>, string type);
};
#endif