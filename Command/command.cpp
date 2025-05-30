#include "command.h"
#include "exit.h"
#include "../utils.h"


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

string Notification::getCommandType(){
    return "Notification";
}

string ICommand::inputString(ostream& os, istream& is,const string& prompt){
    string s;
    os << prompt;
    is >> s;
    return s;
}

#pragma endregion

#pragma region execute
void SearchCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    if ("Id" == typeOfSubCommand){
        string id;
        id = inputString(cout, cin, "Enter search ID:");
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
        name = inputString(cout, cin, "Enter search name: ");
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
    if (object == nullptr){
        return;
    }
    database->Add(object);
    cout << "Adding new " << typeEntity << " successfully\n";
    getch();
}

void RemoveCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    string id;
    id = inputString(cout, cin, "Enter remove ID: ");
    int index = database->find(id);
    bool isRemove = false;
    if (index < 0){
        cout << "No " << typeEntity << " exists in database \n";
        cin.ignore();
        cin.get();
    } else {
        cout << "The " << typeEntity << " that is going to be removed is: \n";
        IUI* printer = UIFactory::createUI(typeEntity);
        BaseEntity* object = database->getData(index);
        printer->print(object);
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
    }
    getch();
}

void ReplaceCommand::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    string id;
    id = inputString(cout, cin, "Enter ID: ");
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
        cin.ignore();
        BaseEntity* scr = inputMachine->input();
        database->Replace(des, scr);
        cout << "Replace/Update successfully\n";
    }
    cout << "Press any keyboard to continue";
    getch();
}

void TurnOffProgram::execute(map<string, IDatabase*> mappingDatabase){
    vector<string> type = {"Student", "Lecturer", "Faculty"};
    for (int i = 0; i < type.size(); i++){
        ISaveData* savingMachine = SaveDataFactory::create(type[i], mappingDatabase);
        savingMachine->execute();
        delete savingMachine;
    }
    //Luu thong tin du lieu o DB vao file txt, xa hon la DB o SQL sau khi nhan ket thuc chuong trinh
}

void Notification::execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){

    MailCommand mailMachine;
    mailMachine.excute(mappingDatabase, typeEntity, typeOfSubCommand);
    cout << "Da gui thong bao thanh cong\n";
    cout << "Nhan phim bat ki de tro ve\n";
    getch();
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
    } else if ("Notification" == typeCommand){
        return new Notification();
    }
    return nullptr;
}

#pragma endregion