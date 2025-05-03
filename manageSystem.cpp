#include "menu.h"
#include "manageSystem.h"
#include "faculty.h"
#include "display.h"
#include "data.h"

void UniversitySystem::Run(){
    studentDB = &StudentDatabase::getInstance();
    lecturerDB = &LecturerDatabase::getInstance();
    facultyDB = &FacultyDatabase::getInstance();
    StudentReadData& studentReader = StudentReadData::getInstance();
    LecturerReadData& lecturerReader = LecturerReadData::getInstance();
    FacultyReadData& facultyReader = FacultyReadData::getInstance();
    studentReader.readData("Data/StudentData.txt");
    lecturerReader.readData("Data/LecturerData.txt");
    facultyReader.readData("Data/FacultyData.txt");

    MenuFactory menuFactory;
    unique_ptr<Menu> mainMenu = menuFactory.createMenu("Main");
    unique_ptr<Menu> entityMenu = menuFactory.createMenu("Entity");
    IDisplay* display = nullptr;
  
    mainMenu->display();
    while (true) {
        string choice = mainMenu->getChoice();
        if (choice == "5") {
            entityMenu->display();
            string entityChoice = entityMenu->getChoice();
            while (true){
                if (entityChoice == "1") {
                    display = DisplayFactory::createDisplay(studentDB);
                    display->display(studentDB);
                } else if (entityChoice == "2") {
                    display = DisplayFactory::createDisplay(lecturerDB);
                    display->display(lecturerDB);   
                } else if (entityChoice == "3") {
                    display = DisplayFactory::createDisplay(facultyDB);
                    display->display(facultyDB);
                } else if (entityChoice == "4") {
                    mainMenu->display();
                    break;
                } else if (entityChoice == "5") {
                    return;
                } else {
                    cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
                }

                entityChoice = entityMenu->getChoice();
            }
        }  else if (choice == "6") {
            break;
        }else{
            cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
        }
    }

}