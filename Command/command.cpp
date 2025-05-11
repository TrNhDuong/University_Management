#include "command.h"


string DisplayCommand::getCommandType(){
    return "Display";
}

string SearchCommand::getCommandType(){
    return "Search";
}

void SearchCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    if ("Id" == typeOfSubCommand){
        string id;
        cin >> id; 
        _strategy = std::make_unique<IdSearch>();
        vector<BaseEntity*> v = _strategy->search(database, id);  
        IUI* printer = UIFactory::createUI(typeEntity);
        for (int i = 0; i < v.size(); i++)
            printer->print(v[i]);
        delete printer;
    } else if ("Name" == typeOfSubCommand){
        string name;
        cin >> name;
        _strategy = std::make_unique<NameSearch>();
        vector<BaseEntity*> v = _strategy->search(database, name);
        IUI* printer = UIFactory::createUI(typeEntity);
        for (int i = 0; i < v.size(); i++)
            printer->print(v[i]);
        delete printer;
    }
}

void DisplayCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    IDisplay* displayMachine = DisplayFactory::createDisplay(typeEntity);
    displayMachine->display(database);
}