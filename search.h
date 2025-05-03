#ifndef _SEARCH_H_
#define _SEARCH_H_
#include "Entity/baseEntity.h"
#include "data.h"


//Chưa xong
class Command{
public:
    virtual string getCommand() const = 0;
    virtual ~Command() = default;
};

class SearchCommand: public Command{
public:
    string getCommand() const override{
        return "Search";
    }
    void SearchObject(const string& type, const string& id){

    }
};

class AddCommand: public Command{
public:
    string getCommand() const override{
        return "Add";
    }
};

class RemoveCommand: public Command{
public:
    string getCommand() const override{
        return "Remove";
    }
};

#endif