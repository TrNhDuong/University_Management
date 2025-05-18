#include "command.h"
#include "exit.h"



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

#pragma region execute
void SearchCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    if ("Id" == typeOfSubCommand){
        string id;
        cout << "Enter search ID: ";
        cin >> id; 
        _strategy = std::make_unique<IdSearch>();
        vector<BaseEntity*> v = _strategy->search(database, id);  
        IUI* printer = UIFactory::createUI(typeEntity);
        if (v.size() == 0){
            cout << "No " << typeEntity << " exists with the same ID:" << id << '\n';
        } else {
            cout << "List of " << typeEntity << " has the same ID as " << id << ":\n";
            for (int i = 0; i < v.size(); i++)
                printer->print(v[i]);
        }
        delete printer;
    } else if ("Name" == typeOfSubCommand){
        string name;
        cout << "Input search namw: ";
        cin >> name;
        _strategy = std::make_unique<NameSearch>();
        vector<BaseEntity*> v = _strategy->search(database, name);
        IUI* printer = UIFactory::createUI(typeEntity);
        if (v.size() == 0){
            cout << "No " << typeEntity << " exists with the same name:" << name << '\n';
        } else {
            cout << "List of " << typeEntity << " has the same name as " << name << ":\n";
            for (int i = 0; i < v.size(); i++)
                printer->print(v[i]);
        }
        delete printer;
    }
    cin.ignore();
    cin.get();
}

void DisplayCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    IDisplay* displayMachine = DisplayFactory::createDisplay(typeEntity);
    displayMachine->display(database);
}

void AddCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    IDataInput* inputMachine = InputFactory::create(typeEntity);
    BaseEntity* object = inputMachine->input();
    database->Add(object);
    cout << "Adding new student successfully\n";
}

void RemoveCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    cout << "Input remove ID: ";
    string id;
    cin >> id;
    int index = database->find(id);
    bool isRemove = false;
    if (index < 0){
        cout << "No " << typeEntity << " exists in database \n";
        cin.ignore();
        cin.get();
    } else {
        cout << "The " << typeEntity << " that is going to be removed is: \n";
        IUI* printer = UIFactory::createUI(typeEntity);
        printer->print(database->getData(index));
        cout << "Are you sure you want to remove: (Y/N): ";
        string ans;
        cin >> ans;
        if (ans == "Y"){
            database->Remove(id);
            isRemove = true;
        }
    }
    if (isRemove){
        cout << "Remove successfully\n";
        cin.get();
    }
}

void ReplaceCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    cout << "Enter ID:";
    string id;
    cin >> id;
    int index = database->find(id);
    bool isRemove = false;
    if (index < 0){
        cout << "No " << typeEntity << " exists in database \n";
    } else {
        cout << typeEntity << " you want to update/replace infomation is: ";
        IUI* printer = UIFactory::createUI(typeEntity);
        BaseEntity* des = database->getData(index);
        printer->print(des);
        IDataInput* inputMachine = InputFactory::create(typeEntity);
        BaseEntity* scr = inputMachine->input();
        database->Replace(des, scr);
    }
}

void TurnOffProgram::execute(map<string, IDatabase*> mappingDatabase){
    cout << "Exit";
    system("clear");
    cout << "Chao cac cau, ";
    cin.get();
    vector<string> type = {"Student", "Lecturer", "Faculty"};
    for (int i = 0; i < type.size(); i++){
        ISaveData* savingMachine = SaveDataFactory::create(type[i], mappingDatabase);
        savingMachine->execute();
        delete savingMachine;
    }
    //Luu thong tin du lieu o DB vao file txt, xa hon la DB o SQL sau khi nhan ket thuc chuong trinh
}

ICommand* CommandFactory::create(const string& typeCommand){
    if ("Display" == typeCommand){
        return new DisplayCommand();
    } else if ("Search" == typeCommand){
        return new SearchCommand();
    } else if ("Remove" == typeCommand){
        return new RemoveCommand();
    } else if ("Replace" == typeCommand){
        return new ReplaceCommand();
    } else if ("Add" == typeCommand){
        return new AddCommand();
    }
    return nullptr;
}

#pragma endregion