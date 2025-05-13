#include "command.h"

void SearchCommand::searchObject(IDatabase* database, const string& id){
    string type = database->getDataType();
    std::unique_ptr<ISearch> searchMachine(SearchFactory::createSearch(type));
    std::unique_ptr<IUI> printer(UIFactory::createUI(type));

    if (!searchMachine || !printer) return;

    BaseEntity* object = searchMachine->search(database, id);
    if (object)
        printer->print(object);
}

void DisplayCommand::displayDatabase(IDatabase* database){
    string type = database->getDataType();
    std::unique_ptr<IDisplay> displayMachine(DisplayFactory::createDisplay(type));
    displayMachine->display(database);
}