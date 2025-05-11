#ifndef COMMAND_H
#define COMMAND_H
#include "search.h"
#include "display.h"
#include "inputData.h"
#include <map>
#include <memory>
#include <string>
using std::string;
using std::map;
using std::unique_ptr;

class ICommand{
public:
    ICommand() = default;
    virtual string getCommandType() = 0;
    virtual void excute(map<string, IDatabase*>, string typeEntity, const string& typeOfSubCommand) = 0;
    virtual ~ICommand() = default;
};
//typeEntity: Student, Lecturer
//typeOfSubCommand: ex, Search has 2 type: Search by name or by ID

class SearchCommand: public ICommand{
private:
    unique_ptr<SearchStrategy> _strategy;
public:
    SearchCommand() = default;
    ~SearchCommand() = default;
    string getCommandType();
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand);
};

class DisplayCommand: public ICommand{
public:
    DisplayCommand() = default;
    ~DisplayCommand() = default;
    string getCommandType();
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand);
};
#endif