#include "menu.h"
#include "faculty.h"

Menu::Menu(){
    _option = {"Them", "Xoa", "Sua", "Hien Thi"};
}

Menu::~Menu(){}

void displayList(vector<string>& list){
    for (size_t i = 0; i < list.size(); ++i) {
        cout << i + 1 << ". " << list[i] << endl;
    }
}

bool checkValidChoice(vector<string>& checkList, string& choice){
    for (const string &x: checkList){
        if (choice == x) return true;
    }

    return false;
}

void Menu::displayMenu(){
    cout << "==== MENU ====" << endl;
    displayList(_option);
    cout << "===============" << endl;
}


string Menu::getChoice(){
    string choice;
    displayMenu();
    while (true){
        cout << "Moi ban chon: ";
        getline(cin, choice);
        
        if (checkValidChoice(_option,choice)) break;
        cout << "Nhập sai rồi thằng ngu! \n";
    }

    return choice;
}

void Menu::addChoice(const string &newChoice){
    _option.push_back(newChoice);
}

void Menu::removeChoice(const string& choice){
    vector<string> newMenu = {};
    for (const string& x: _option){
        if (choice != x){
            newMenu.push_back(x);
        }
    }
    
    _option = newMenu;
}

void Menu::replaceChoice(const string& oldChoice, const string& newChoice){
    vector<string> newMenu = {};
    for (const string& x: _option){
        if (oldChoice != x){
            newMenu.push_back(x);
        }else{
            newMenu.push_back(newChoice);
        }
    }

    _option = newMenu;
}

vector<string> System::_entity = {"faculty", "student", "lecturer"};
void System::displaySystemName(){
    cout << "==== ENTITY ====" << endl;
    displayList(_entity);
    cout << "===============" << endl;
}


string System::getChoice(){
    string choice;
    displaySystemName();
    while (true){
        cout << "Moi ban chon: ";
        getline(cin, choice);
        
        if (checkValidChoice(_entity, choice)) break;
        cout << "Nhập sai rồi thằng ngu! \n";
    }

    return choice;
}


void System::runMenu(Menu& menu){
    string choice = menu.getChoice();
    
    if ("Them" == choice){
        string choice = getChoice();

        if (choice == "faculty"){
            Faculty newData = FacultyInfo::getInfo();
            addData(FacultyData::_data,newData);

        }else if (choice == "student"){

        }else if (choice == "lecturer"){

        }
        
    }else if ("Xoa" == choice){

    }else if ("Sua" == choice){

    }else if ("Hien Thi" == choice){

    }
}