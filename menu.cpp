#include "menu.h"
#include "faculty.h"
#include "utils.h"
#include "display.h"
#include "manageSystem.h"

Menu::Menu(){
    _option = {"Thêm", "Xóa", "Sửa", "Hiển Thị", "Thoát"};
}

Menu::~Menu(){}



void Menu::displayMenu(){
    cout << "==== MENU ====" << endl;
    displayAList::displayList(_option);
    cout << "===============" << endl;
}


string Menu::getChoice(){
    string choice;
    displayMenu();
    while (true){
        cout << "Mời bạn chọn: ";
        getline(cin, choice);
        
        if (ValidChoice::checkValidChoice(_option,choice)) break;
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
    displayAList::displayList(_entity);
    cout << "===============" << endl;
}


string System::getChoiceEntity(){
    string choice;
    displaySystemName();
    while (true){
        cout << "Mời bạn chọn: ";
        getline(cin, choice);
        
        if (ValidChoice::checkValidChoice(_entity, choice)) break;
        cout << "Nhập sai rồi thằng ngu! \n";
    }

    return choice;
}


void RunSystem::runMenu(Menu& menu){
    DisplayFactory display;
    while (true){
        string choiceMode = menu.getChoice();
        
        // if ("Thêm" == choiceMode){
        //     string choiceEntity = System::getChoiceEntity();
        //     if (choiceEntity == "faculty"){
        //         Faculty newData = FacultyInfo::getInfo();
        //         addData(FacultyData::_data, newData);     
        //     }else if (choiceEntity == "student"){
                
        //     }else if (choiceEntity == "lecturer"){
    
        //     }
            
        // }else if ("Xóa" == choiceMode){

        //     string choiceEntity = System::getChoiceEntity();
        //     if (choiceEntity == "faculty"){
        //         Faculty oldData;
        //         string id;
        //         cout << "Nhập ID của khoa mày muốn xóa: ";
        //         getline(cin, id);
        //         oldData.setId(id);
        //         removeData(FacultyData::_data, oldData);     
        //     }else if (choiceEntity == "student"){
                
        //     }else if (choiceEntity == "lecturer"){
    
        //     }
        // }else if ("Sửa" == choiceMode){
        //     string choiceEntity = System::getChoiceEntity();

        //     if (choiceEntity == "faculty"){
        //         Faculty oldData;
        //         string id;
        //         cout << "Nhập ID của khoa mày muốn thay thế: ";
        //         getline(cin, id);
        //         oldData.setId(id);
        //         Faculty newData = FacultyInfo::getInfo();
        //         replaceData(FacultyData::_data, oldData, newData);     
        //     }else if (choiceEntity == "student"){
                
        //     }else if (choiceEntity == "lecturer"){
    
        //     }
    
        // }else 
        if ("Hiển Thị" == choiceMode){
        }else if ("Thoát" == choiceMode){
            break;
        }
    }
    cout << "Mày đã bấm vào nút thoát chương trình!\n";

} 