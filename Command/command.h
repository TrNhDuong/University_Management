#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "search.h"
#include "display.h"

class SearchCommand{
public:
    SearchCommand() = default;
    void SearchObject(IDatabase* database, const string& id){
        string type = database->getDataType();
        std::unique_ptr<ISearch> searchMachine(SearchFactory::createSearch(type));
        std::unique_ptr<IUI> printer(UIFactory::createUI(type));

        if (!searchMachine || !printer) return;

        BaseEntity* object = searchMachine->search(database, id);
        if (object)
            printer->print(object);
    }
};

class DisplayCommand{
public:
    DisplayCommand() = default;
    void displayDatabase(IDatabase* database){
        string type = database->getDataType();
        std::unique_ptr<IDisplay> displayMachine(DisplayFactory::createDisplay(type));
        displayMachine->display(database);
    }
};
#endif