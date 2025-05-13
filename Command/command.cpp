#include "command.h"
#include "../saveDataToFile.h"


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
        cout << "Nhap id muon tim kiem: ";
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
        cout << "Nhap ten sinh vien muon tim kiem: ";
        cin >> name;
        _strategy = std::make_unique<NameSearch>();
        vector<BaseEntity*> v = _strategy->search(database, name);
        IUI* printer = UIFactory::createUI(typeEntity);
        if (v.size() == 0){
            cout << "Khong ton tai sinh vien nao ten tuong tu " << name << '\n';
        } else {
            cout << "Sinh vien co ten tuong tu voi " << name << ":\n";
            for (int i = 0; i < v.size(); i++)
                printer->print(v[i]);
        }
        delete printer;
    }
}

void DisplayCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    IDisplay* displayMachine = DisplayFactory::createDisplay(typeEntity);
    displayMachine->display(database);
    cin.get();
}

void AddCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    IDataInput* inputMachine = InputFactory::create(typeEntity);
    BaseEntity* object = inputMachine->input();
    database->Add(object);
    cout << "Adding new student successfully\n";
}

void RemoveCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    cout << "Nhap id sinh vien muon loai bo: ";
    string id;
    cin >> id;
    int index = database->find(id);
    bool isRemove = false;
    if (index < 0){
        cout << "Khong ton tai sinh vien trong he thong\n";
    } else {
        cout << "Sinh vien ban muon xoa la: \n";
        IUI* printer = UIFactory::createUI(typeEntity);
        printer->print(database->getData(index));
        cout << "Ban chac chan muon xoa sinh vien nay chu: (Y/N): ";
        string ans;
        cin >> ans;
        if (ans == "Y"){
            database->Remove(id);
            isRemove = true;
        }
    }
    if (isRemove)
        cout << "Remove student successfully\n";
}

void ReplaceCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* database = mappingDatabase[typeEntity];
    cout << "Nhap id sinh vien muon cap nhat: ";
    string id;
    cin >> id;
    int index = database->find(id);
    bool isRemove = false;
    if (index < 0){
        cout << "Khong ton tai sinh vien trong he thong\n";
    } else {
        cout << "Sinh vien ban muon cap nhat thong tin la: \n";
        IUI* printer = UIFactory::createUI(typeEntity);
        BaseEntity* des = database->getData(index);
        printer->print(des);
        cout << "Nhap thong tin thay doi: ";
        IDataInput* inputMachine = InputFactory::create(typeEntity);
        BaseEntity* scr = inputMachine->input();
        database->Replace(des, scr);
    }
    if (isRemove)
        cout << "Remove student successfully\n";
}

void TurnOffProgram::excute(map<string, IDatabase*> mappingDatabase){
    cout << "Exit";
    system("clear");
    cout << "Chao cac cau, djtme ban";
    cin.get();
    // vector<string> type = {"Student", "Lecturer", "Faculty"};
    // for (int i = 0; i < type.size(); i++){
    //     ISaveData* savingMachine = SaveDataFactory::create(type[i]);
    //     savingMachine->excute();
    //     delete savingMachine;
    // }
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