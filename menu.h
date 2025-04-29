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
        bool checkChoice(const string& choice);
        Menu();
        ~Menu(); 
};


#endif