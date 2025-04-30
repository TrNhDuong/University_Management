#include "menu.h"
#include "faculty.h"
#include <iomanip>
Menu::Menu(){
    _option = {"Thêm", "Xóa", "Sửa", "Hiển Thị", "Thoát"};
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


string System::getChoiceEntity(){
    string choice;
    displaySystemName();
    while (true){
        cout << "Mời bạn chọn: ";
        getline(cin, choice);
        
        if (checkValidChoice(_entity, choice)) break;
        cout << "Nhập sai rồi thằng ngu! \n";
    }

    return choice;
}


void RunSystem::runMenu(Menu& menu){
    while (true){
        string choiceMode = menu.getChoice();
        
        if ("Thêm" == choiceMode){
            string choiceEntity = System::getChoiceEntity();
            if (choiceEntity == "faculty"){
                Faculty newData = FacultyInfo::getInfo();
                addData(FacultyData::_data, newData);     
            }else if (choiceEntity == "student"){
                
            }else if (choiceEntity == "lecturer"){
    
            }
            
        }else if ("Xóa" == choiceMode){

            string choiceEntity = System::getChoiceEntity();
            if (choiceEntity == "faculty"){
                Faculty oldData;
                string id;
                cout << "Nhập ID của khoa mày muốn xóa: ";
                getline(cin, id);
                oldData.setId(id);
                removeData(FacultyData::_data, oldData);     
            }else if (choiceEntity == "student"){
                
            }else if (choiceEntity == "lecturer"){
    
            }
        }else if ("Sửa" == choiceMode){
            string choiceEntity = System::getChoiceEntity();

            if (choiceEntity == "faculty"){
                Faculty oldData;
                string id;
                cout << "Nhập ID của khoa mày muốn thay thế: ";
                getline(cin, id);
                oldData.setId(id);
                Faculty newData = FacultyInfo::getInfo();
                replaceData(FacultyData::_data, oldData, newData);     
            }else if (choiceEntity == "student"){
                
            }else if (choiceEntity == "lecturer"){
    
            }
    
        }else if ("Hiển Thị" == choiceMode){
            string choiceEntity = System::getChoiceEntity();

            if (choiceEntity == "faculty"){
                //in danh sách khoa
                cout << "==== FACULTY INFORMATION ====\n";
                std::cout << std::left
                        << std::setw(10) << "ID"
                        << std::setw(20) << "Name"
                        << std::setw(12) << "Birth"
                        << std::setw(30) << "Mail"
                        << std::setw(25) << "Dean"
                        << "\n";
                for (const Faculty& x: FacultyData::_data){
                    FacultyInfo::printFacultyInfo(x);
                }
                cout << "=============================\n";

            }else if (choiceEntity == "student"){
                
            }else if (choiceEntity == "lecturer"){
    
            }
        }else if ("Thoát" == choiceMode){
            break;
        }
    }
    cout << "Mày đã bấm vào nút thoát chương trình!\n";

} 