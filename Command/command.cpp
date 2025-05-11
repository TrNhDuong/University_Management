#include "command.h"

void SearchFunction::searchObjectById(IDatabase* database, const string& id){
    string type = database->getDataType();
    std::unique_ptr<ISearch> searchMachine(SearchFactory::createSearch(type));
    std::unique_ptr<IUI> printer(UIFactory::createUI(type));

    if (!searchMachine || !printer) return;

    BaseEntity* object = searchMachine->search(database, id);
    if (object)
        printer->print(object);
}

void SearchFunction::searchObjectByName(IDatabase* database, const string& name){
    string type = database->getDataType();
    std::unique_ptr<ISearch> searchMachine(SearchFactory::createSearch(type));
    std::unique_ptr<IUI> printer(UIFactory::createUI(type));

    if (!searchMachine || !printer)  return;

    vector<BaseEntity*> listObject = searchMachine->searchName(database, name);
    int size = listObject.size();
    for (int i = 0; i < size; i++)
        printer->print(listObject[i]);
}

string SearchCommand::getCommandType(){
    return "Search";
}

void SearchCommand::excute(map<string, IDatabase*> mappingDatabase, string type){
    IDatabase* database = mappingDatabase[type];
    if (_searchType == "ID"){
        SearchFunction::searchObjectById(database, _searchObject);
    } else if (_searchType == "Name"){
        SearchFunction::searchObjectByName(database, _searchObject);
    }
}

string DisplayCommand::getCommandType(){
    return "Display";
}

void DisplayCommand::excute(map<string, IDatabase*> mappingDatabase, string type){
    IDatabase* database = mappingDatabase[type];
    IDisplay* displayMachine = DisplayFactory::createDisplay(type);
    displayMachine->display(database);
}