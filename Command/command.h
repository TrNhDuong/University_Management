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
class SearchStrategy;

class SearchCommand: public ICommand{
private:
    unique_ptr<SearchStrategy> _strategy;
public:
    SearchCommand() = default;
    ~SearchCommand() = default;
    string getCommandType() override;
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

class DisplayCommand: public ICommand{
public:
    DisplayCommand() = default;
    ~DisplayCommand() = default;
    string getCommandType() override;
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

class AddCommand: public ICommand{
public:
    AddCommand() = default;
    ~AddCommand() = default;
    string getCommandType() override;
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

class RemoveCommand: public ICommand{
public:
    RemoveCommand() = default;
    ~RemoveCommand() = default;

    string getCommandType() override;
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

class ReplaceCommand: public ICommand{
public:
    ReplaceCommand() = default;
    ~ReplaceCommand() = default;

    string getCommandType() override;
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

class TurnOffProgram{
private:
    IDatabase* studentDB;
    IDatabase* lecturerDB;
    IDatabase* facultyDB;
public:
    TurnOffProgram() = default;
    TurnOffProgram(IDatabase* student, IDatabase* lecturer, IDatabase* faculty){
        studentDB = student;
        lecturerDB = lecturer;
        facultyDB = faculty;
    }
    ~TurnOffProgram() = default;

    static void excute();
};

class CommandFactory{
public:
    static ICommand* create(const string& typeCommand);
};

#endif