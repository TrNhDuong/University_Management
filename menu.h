#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;


class Menu {
protected:
    vector<string> _options;
public:
    virtual ~Menu() = default;
    void display(int selected = 0) const;

    string getChoice() const;

    virtual string type() const = 0;
};

class MainMenu : public Menu {
public:
    MainMenu();
    string type() const override;
};

class EntityMenu : public Menu {
public:
    EntityMenu();
    string type() const override;

};

class MenuFactory {
public:
    static unique_ptr<Menu> createMenu(const string& type);
};
    

#endif