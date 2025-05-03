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
        } else if (choice == "1") {
            entityMenu->display();
            string entityChoice = entityMenu->getChoice();
            while (true){
                if (entityChoice == "1") {
                    Student student;
                    cout << "Nhập tên sinh viên: ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    student.setName(name);
                    cout << "Nhập mã sinh viên: ";
                    string id;
                    cin >> id;
                    student.setId(id);
                    cout << "Nhập ngày sinh sinh viên (dd/mm/yyyy): ";
                    string birth;
                    cin >> birth;
                    student.setBirth(birth);
                   
                    cout << "Nhập điểm trung bình sinh viên: ";
                    float gpa;
                    cin >> gpa;
                    student.setGPA(gpa);

                    cout << "Nhập số tín chỉ đã hoàn thành: ";
                    int completedCredit;
                    cin >> completedCredit;
                    student.setCredit(completedCredit);
                    
                    static_cast<StudentDatabase*>(studentDB)->Add(student);  //ép kiểu nếu nó là factory
                    
                } else if (entityChoice == "2") {
                    
                } else if (entityChoice == "3") {
                    
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
        }else{
            cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
        }
    }

}