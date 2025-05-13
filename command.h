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
   
    void execute() override;
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
    void execute() override;
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
    void execute() override;
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
    void execute() override;
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
    
            for (int i = 0; i < 2; ++i) {
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

class IAddHandler {
public:
    virtual void Add() = 0;
    virtual ~IAddHandler() = default;
};


class StudentAddHandler : public IAddHandler {
    public:
        void Add() override;
};

class FaccultyAddHandler : public IAddHandler {
    public:
        void Add() override;
};

class LecturerAddHandler : public IAddHandler {
    public:
        void Add() override;
};

class AddHandlerFactory {
   public:
    static IAddHandler* createAddHandler(const string& type);
};

class IReplaceHandler {
public:
    virtual void Replace() = 0;
    virtual ~IReplaceHandler() = default;
};
class StudentReplaceHandler : public IReplaceHandler {
    public:
        void Replace() override;
};
class FacultyReplaceHandler : public IReplaceHandler {
    public:
        void Replace() override;
};
class LecturerReplaceHandler : public IReplaceHandler {
    public:
        void Replace() override;
};
class ReplaceHandlerFactory {
   public:
    static IReplaceHandler* createReplaceHandler(const string& type);
};

class IRemoveHandler {
public:
    virtual void Remove() = 0;
    virtual ~IRemoveHandler() = default;
};
class StudentRemoveHandler : public IRemoveHandler {
    public:
        void Remove() override;
};
class FacultyRemoveHandler : public IRemoveHandler {
    public:
        void Remove() override;
};
class LecturerRemoveHandler : public IRemoveHandler {
    public:
        void Remove() override;
};
class RemoveHandlerFactory {
   public:
    static IRemoveHandler* createRemoveHandler(const string& type);
};

class IDisplayHandler {
public:
    virtual void Display() = 0;
    virtual ~IDisplayHandler() = default;
};
class StudentDisplayHandler : public IDisplayHandler {
    public:
        void Display() override;
};
class FacultyDisplayHandler : public IDisplayHandler {
    public:
        void Display() override;
};
class LecturerDisplayHandler : public IDisplayHandler {
    public:
        void Display() override;
};
class DisplayHandlerFactory {
   public:
    static IDisplayHandler* createDisplayHandler(const string& type);
};
#endif // _COMMAND_H_