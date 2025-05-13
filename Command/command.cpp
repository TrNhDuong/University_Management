#include "command.h"


#pragma region getCommandType
string DisplayCommand::getCommandType(){
    return "Display";
}

string SearchCommand::getCommandType(){
    return "Search";
}

string AddCommand::getCommandType(){
    return "Add";
}

string RemoveCommand::getCommandType(){
    return "Delete";
}

string ReplaceCommand::getCommandType(){
    return "Replace";
}

#pragma endregion

#pragma region excute
void SearchCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    if ("Id" == typeOfSubCommand){
        string id;
        cin >> id; 
        _strategy = std::make_unique<IdSearch>();
        vector<BaseEntity*> v = _strategy->search(database, id);  
        IUI* printer = UIFactory::createUI(typeEntity);
        if (v.size() == 0){
            cout << "Khong co sinh vien nao co id giong voi " << id << '\n';
        } else {
            cout << "Sinh vien co Id giong voi " << id << ":\n";
            for (int i = 0; i < v.size(); i++)
                printer->print(v[i]);
        }
        delete printer;
    } else if ("Name" == typeOfSubCommand){
        string name;
        cin >> name;
        _strategy = std::make_unique<NameSearch>();
        vector<BaseEntity*> v = _strategy->search(database, name);
        IUI* printer = UIFactory::createUI(typeEntity);
        cout << "Sinh vien co ten giong voi " << name << ":\n";
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

void AddCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    // IDatabase* database = mappingDatabase[typeEntity];
    // IDataInput* inputMachine = InputFactory::create(typeEntity);
    // BaseEntity* object = inputMachine->input();
    // cout << "Successfully adding new university student\n";
}

void RemoveCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    cout << "Remove command\n";
}

void ReplaceCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    cout << "Replace command\n";
}

#pragma endregion