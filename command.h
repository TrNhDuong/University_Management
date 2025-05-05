/**
@file command.h
@brief Khai báo các lớp lệnh cho hệ thống quản lý sinh viên.
*/

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "menu.h"
#include "data.h"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;


/**
 * @class Command
 *  @brief Lớp cơ sở cho các lệnh trong hệ thống quản lý sinh viên.
 */
class Command {
public:
    /**
     * @brief Hàm hủy ảo cho lớp Command.
     */
    virtual ~Command() = default;

    /**
     * @brief Thực hiện lệnh.
     */
    virtual void execute() = 0;
};

/**
 * @class AddCommand
 * @brief Lớp lệnh thêm sinh viên, giảng viên hoặc khoa vào cơ sở dữ liệu.
 */
class AddCommand : public Command {
private:
    /**
     * @brief Con trỏ đến menu.
     */
    Menu* menu;

    /**
     * @brief Con trỏ đến cơ sở dữ liệu sinh viên.
     */
    IDatabase* studentDB;

    /**
     * @brief Con trỏ đến cơ sở dữ liệu giảng viên.
     */
    IDatabase* lecturerDB;

    /**
     * @brief Con trỏ đến cơ sở dữ liệu khoa.
     */
    IDatabase* facultyDB;

public:
    /**
     * @brief Hàm khởi tạo cho lớp AddCommand.
     * @param m Con trỏ đến menu.
     * @param sDB Con trỏ đến cơ sở dữ liệu sinh viên.
     * @param lDB Con trỏ đến cơ sở dữ liệu giảng viên.
     * @param fDB Con trỏ đến cơ sở dữ liệu khoa.
     */

    AddCommand(Menu* m, IDatabase* sDB, IDatabase* lDB, IDatabase* fDB)
        : menu(m), studentDB(sDB), lecturerDB(lDB), facultyDB(fDB) {}

    /**
     * @brief Thực hiện lệnh thêm sinh viên, giảng viên hoặc khoa vào cơ sở dữ liệu.
     */
   
    void execute() override {
        menu->display();
        string entityChoice = menu->getChoice();
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
                break;
            } else {
                cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
            }
            menu->display();
            entityChoice = menu->getChoice();
        }
    }
};

/**
 * @class RemoveCommand
 * @brief Lớp lệnh xóa sinh viên, giảng viên hoặc khoa khỏi cơ sở dữ liệu.
 */
class RemoveCommand : public Command {
private:
    /**
     * @brief Con trỏ đến menu.
     */ 
    Menu* menu;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu sinh viên.
     */
    IDatabase* studentDB;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu giảng viên.
     */
    IDatabase* lecturerDB;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu khoa.
     */
    IDatabase* facultyDB;

public:
    /**
     * @brief Hàm khởi tạo cho lớp RemoveCommand.
     * @param m Con trỏ đến menu.
     * @param sDB Con trỏ đến cơ sở dữ liệu sinh viên.
     * @param lDB Con trỏ đến cơ sở dữ liệu giảng viên.
     * @param fDB Con trỏ đến cơ sở dữ liệu khoa.
     */
    RemoveCommand(Menu* m, IDatabase* sDB, IDatabase* lDB, IDatabase* fDB)
        : menu(m), studentDB(sDB), lecturerDB(lDB), facultyDB(fDB) {}

    /**
     * @brief Thực hiện lệnh xóa sinh viên, giảng viên hoặc khoa khỏi cơ sở dữ liệu.
     */
    void execute() override {
        menu->display();
        string entityChoice = menu->getChoice();
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
                break;
            } else {
                cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
            }
            menu->display();
            entityChoice = menu->getChoice();
        }
    }
};


/**
 * @class ReplaceCommand
 * @brief Lớp lệnh thay thế thông tin sinh viên, giảng viên hoặc khoa trong cơ sở dữ liệu.
 */
class ReplaceCommand : public Command {
private:
    /**
     * @brief Con trỏ đến menu.
     */
    Menu* menu;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu sinh viên.
     */
    IDatabase* studentDB;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu giảng viên.
     */
    IDatabase* lecturerDB;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu khoa.
     */
    IDatabase* facultyDB;

public:
    /**
     * @brief Hàm khởi tạo cho lớp ReplaceCommand.
     * @param m Con trỏ đến menu.
     * @param sDB Con trỏ đến cơ sở dữ liệu sinh viên.
     * @param lDB Con trỏ đến cơ sở dữ liệu giảng viên.
     * @param fDB Con trỏ đến cơ sở dữ liệu khoa.
     */
    ReplaceCommand(Menu* m, IDatabase* sDB, IDatabase* lDB, IDatabase* fDB)
        : menu(m), studentDB(sDB), lecturerDB(lDB), facultyDB(fDB) {}

    /**
     * @brief Thực hiện lệnh thay thế thông tin sinh viên, giảng viên hoặc khoa trong cơ sở dữ liệu.
     */
    void execute() override {
        menu->display();
        string entityChoice = menu->getChoice();
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
                break;
            }else {
                cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
            }
            menu->display();
            entityChoice = menu->getChoice();
        }
    }
};


/**
 * @class DisplayCommand
 * @brief Lớp lệnh hiển thị thông tin sinh viên, giảng viên hoặc khoa trong cơ sở dữ liệu.
 */
class DisplayCommand : public Command {
private:
    /**
     * @brief Con trỏ đến menu.
     */
    Menu* menu;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu sinh viên.
     */
    IDatabase* studentDB;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu giảng viên.
     */
    IDatabase* lecturerDB;
    /**
     * @brief Con trỏ đến cơ sở dữ liệu khoa.
     */
    IDatabase* facultyDB;
public:
    /**
     * @brief Hàm khởi tạo cho lớp DisplayCommand.
     * @param m Con trỏ đến menu.
     * @param sDB Con trỏ đến cơ sở dữ liệu sinh viên.
     * @param lDB Con trỏ đến cơ sở dữ liệu giảng viên.
     * @param fDB Con trỏ đến cơ sở dữ liệu khoa.
     */
    DisplayCommand(Menu* m, IDatabase* sDB, IDatabase* lDB, IDatabase* fDB)
        : menu(m), studentDB(sDB), lecturerDB(lDB), facultyDB(fDB) {}

    /**
     * @brief Thực hiện lệnh hiển thị thông tin sinh viên, giảng viên hoặc khoa trong cơ sở dữ liệu.
     */
    void execute() override {
        menu->display();
        string entityChoice = menu->getChoice();
        IDisplay* display = nullptr;

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
                break;
            } else {
                cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
            }
            menu->display();
            entityChoice = menu->getChoice();
        }
    }
};

/**
 * @class ExitCommand
 * @brief Lớp lệnh thoát khỏi chương trình.
 */
#include <vector>
#include <algorithm>
class ExitCommand : public Command {
    public:
        void execute() override {
            vector<string> funnyQuestions = {
                "Bạn chắc chứ?",
                "Suy nghĩ kỹ chưa?",
                "Bạn sẽ bỏ tui đi à?",
                "Thoát thật đấy à?",
                "Không hối tiếc chứ?",
                "Chắc chắn chưa?",
                "Không quay lại nữa à?",
                "Bạn dám à?",
                "Thoát rồi ai chơi với tui?",
                "Còn suy nghĩ lại không?"
            };
    
            srand(time(nullptr)); // Khởi tạo seed
    
            vector<int> usedIndices;
    
            for (int i = 0; i < 0; ++i) {
                int index;
                do {
                    index = rand() % funnyQuestions.size();
                } while (find(usedIndices.begin(), usedIndices.end(), index) != usedIndices.end());
    
                usedIndices.push_back(index);
    
                cout << funnyQuestions[index] << "\n> ";
                string userInput;
                getline(cin, userInput); // Đảm bảo người dùng trả lời trước khi tiếp tục
            }
    
            cout << "Tạm biệt! Cảm ơn bạn đã sử dụng chương trình.\n";
            exit(0);
        }
    };
#endif // _COMMAND_H_