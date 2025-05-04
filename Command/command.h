#ifndef COMMAND_H
#define COMMAND_H
#include "search.h"
#include "display.h"
#include <memory>
#include <string>
using std::string;

class SearchCommand{
public:
    SearchCommand() = default;
    void searchObject(IDatabase* database, const string& id);
};

class DisplayCommand{
public:
    DisplayCommand() = default;
    void displayDatabase(IDatabase* database);
};
#endif