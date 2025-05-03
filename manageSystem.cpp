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

        if (choice == "1") {
            entityMenu->display();
            string entityChoice = entityMenu->getChoice();
            while (true) {
                if (entityChoice == "1") {
                    Student student;
                    StudentGetData::InputData(student);
                    static_cast<StudentDatabase*>(studentDB)->Add(student);
                } else if (entityChoice == "2") {
                    Lecturer lecturer;
                    LecturerGetData::InputData(lecturer);
                    static_cast<LecturerDatabase*>(lecturerDB)->Add(lecturer);
                } else if (entityChoice == "3") {
                    Faculty faculty;
                    FacultyGetData::InputData(faculty);
                    static_cast<FacultyDatabase*>(facultyDB)->Add(faculty);
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
        } else if (choice == "2") {
            entityMenu->display();
            string entityChoice = entityMenu->getChoice();
            while (true) {
                if (entityChoice == "1") {
                    string id;
                    cout << "Nhập mã sinh viên: ";
                    cin >> id;
                    Student student;
                    student.setId(id);
                    if (static_cast<StudentDatabase*>(studentDB)->Remove(student)) {
                        cout << "Xóa thành công sinh viên có mã " << id << "\n";
                    } else {
                        cout << "Không tìm thấy sinh viên có mã " << id << "\n";
                    }
                } else if (entityChoice == "2") {
                    string id;
                    cout << "Nhập mã giảng viên: ";
                    cin >> id;
                    Lecturer lecturer;
                    lecturer.setId(id);
                    if (static_cast<LecturerDatabase*>(lecturerDB)->Remove(lecturer)) {
                        cout << "Xóa thành công giảng viên có mã " << id << "\n";
                    } else {
                        cout << "Không tìm thấy giảng viên có mã " << id << "\n";
                    }
                } else if (entityChoice == "3") {
                    string id;
                    cout << "Nhập mã khoa: ";
                    cin >> id;
                    Faculty faculty;
                    faculty.setId(id);
                    if (static_cast<FacultyDatabase*>(facultyDB)->Remove(faculty)) {
                        cout << "Xóa thành công khoa có mã " << id << "\n";
                    } else {
                        cout << "Không tìm thấy khoa có mã " << id << "\n";
                    }
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
        } else if (choice == "3") {
            entityMenu->display();
            string entityChoice = entityMenu->getChoice();
            while (true) {
                if (entityChoice == "1") {
                    string id;
                    cout << "Nhập mã sinh viên muốn thay thế: ";
                    cin >> id;
                    Student student;
                    student.setId(id);

                    Student newStudent;
                    cout << "Nhập thông tin sinh viên mới: \n";
                    StudentGetData::InputData(newStudent);

                    if (static_cast<StudentDatabase*>(studentDB)->Replace(student, newStudent)) {
                        cout << "Cập nhật thành công sinh viên có mã " << id << "\n";
                    } else {
                        cout << "Không tìm thấy sinh viên có mã " << id << "\n";
                    }
                } else if (entityChoice == "2") {
                    string id;
                    cout << "Nhập mã giảng viên muốn thay thế: ";
                    cin >> id;
                    Lecturer lecturer;
                    lecturer.setId(id);

                    Lecturer newLecturer;
                    cout << "Nhập thông tin giảng viên mới: \n";
                    LecturerGetData::InputData(newLecturer);

                    if (static_cast<LecturerDatabase*>(lecturerDB)->Replace(lecturer, newLecturer)) {
                        cout << "Cập nhật thành công giảng viên có mã " << id << "\n";
                    } else {
                        cout << "Không tìm thấy giảng viên có mã " << id << "\n";
                    }
                } else if (entityChoice == "3") {
                    string id;
                    cout << "Nhập mã khoa muốn thay thế: ";
                    cin >> id;
                    Faculty faculty;
                    faculty.setId(id);

                    Faculty newFaculty;
                    cout << "Nhập thông tin khoa mới: \n";
                    FacultyGetData::InputData(newFaculty);

                    if (static_cast<FacultyDatabase*>(facultyDB)->Replace(faculty, newFaculty)) {
                        cout << "Cập nhật thành công khoa có mã " << id << "\n";
                    } else {
                        cout << "Không tìm thấy khoa có mã " << id << "\n";
                    }
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
        } else if (choice == "4") {
            entityMenu->display();
            string entityChoice = entityMenu->getChoice();
            while (true) {
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
        } else if (choice == "5") {
            break;
        } else {
            cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
        }
    }
}