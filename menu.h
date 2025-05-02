#ifndef _MENU_H_
#define _MENU_H_
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Menu{
private:
    vector<string> _option;
public:
    string getChoice();
    void displayMenu();
    void addChoice(const string &newChoice);
    void removeChoice(const string& choice);
    void replaceChoice(const string& oldChoice, const string& newChoice);
    Menu();
    ~Menu(); 
};


class System{
    public:
        static vector<string> _entity;
        static void displaySystemName();
        static string getChoiceEntity();
};

class RunSystem{
    public:
        static void runMenu(Menu& menu);
};


#endif