#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;

// Abstract base class for Menu
class Menu {
protected:
    vector<string> _options;
public:
    virtual ~Menu() = default;
    virtual void display() const = 0;
    string getChoice() const;
};

// Concrete class for Main Menu
class MainMenu : public Menu {
public:
    MainMenu();
    void display() const override;
};

// Concrete class for Entity Menu
class EntityMenu : public Menu {
public:
    EntityMenu();
    void display() const override;

};

// Factory class to create menus
class MenuFactory {
public:
    static unique_ptr<Menu> createMenu(const string& type);
};

#endif // MENU_H