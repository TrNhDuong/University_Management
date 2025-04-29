#include "menu.h"

Menu::Menu(){
    _option = {"Them", "Xoa", "Sua", "Hien Thi"};
}

Menu::~Menu(){}

void Menu::displayMenu(){
    cout << "==== MENU ====" << endl;

    for (size_t i = 0; i < _option.size(); ++i) {
        cout << i + 1 << ". " << _option[i] << endl;
    }

    cout << "===============" << endl;
}

bool Menu::checkChoice(const string& choice){
    for (const string &x: _option){
        if (choice == x) return true;
    }

    return false;
}

string Menu::getChoice(){
    string choice;
    while (true){
        displayMenu();
        cout << "Moi ban chon: ";
        getline(cin, choice);
        
        if (checkChoice(choice)) break;
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
