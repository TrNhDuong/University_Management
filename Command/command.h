/**
 * @file command.h
 * @brief Các command để thực hiện các thao tác trên cơ sở dữ liệu
 */

#ifndef COMMAND_H
#define COMMAND_H
#include "search.h"
#include "display.h"
#include "sendMail.h"
#include "inputData.h"
#include "../utils.h"
#include <map>
#include <memory>
#include <string>
using std::string;
using std::map;
using std::unique_ptr;
using std::ostream;
using std::istream;

/**
 * @class ICommand
 * @brief Lớp trừu tượng đại diện cho một lệnh trong hệ thống
 * @details Các lệnh cụ thể sẽ kế thừa từ lớp này và triển khai các phương thức để thực hiện các thao tác trên cơ sở dữ liệu.
 * @note Các lệnh có thể bao gồm: tìm kiếm, hiển thị, thêm, xóa, thay thế, thông báo, tắt chương trình.
 */
class ICommand{
protected:
    string inputString(ostream& os, istream& is,const string& prompt);
public:
    ICommand() = default;
    virtual string getCommandType() = 0;
    virtual void execute(map<string, IDatabase*>, string typeEntity, const string& typeOfSubCommand) = 0;
    virtual ~ICommand() = default;
};


class SearchStrategy;

/**
 * @class SearchCommand
 * @brief Lớp đại diện cho lệnh tìm kiếm trong hệ thống
 * @details Lớp này sử dụng chiến lược tìm kiếm để thực hiện các thao tác tìm kiếm trên cơ sở dữ liệu. 
 */
class SearchCommand: public ICommand{
private:
    unique_ptr<SearchStrategy> _strategy;
public:
    SearchCommand() = default;
    ~SearchCommand() = default;
    string getCommandType() override;
    void execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

/**
 * @class DisplayCommand
 * @brief Lớp đại diện cho lệnh hiển thị trong hệ thống
 * @details Lớp này sử dụng máy hiển thị để hiển thị dữ liệu từ cơ sở dữ liệu.
 */
class DisplayCommand: public ICommand{
public:
    DisplayCommand() = default;
    ~DisplayCommand() = default;
    string getCommandType() override;
    void execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

/**
 * @class AddCommand
 * @brief Lớp đại diện cho lệnh thêm mới trong hệ thống
 * @details Lớp này sử dụng máy nhập dữ liệu để thêm mới một thực thể vào cơ sở dữ liệu.
 */
class AddCommand: public ICommand{
public:
    AddCommand() = default;
    ~AddCommand() = default;
    string getCommandType() override;
    void execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

/**
 * @class RemoveCommand
 * @brief Lớp đại diện cho lệnh xóa trong hệ thống
 * @details Lớp này thực hiện việc xóa một thực thể khỏi cơ sở dữ liệu dựa trên ID.
 */
class RemoveCommand: public ICommand{
public:
    RemoveCommand() = default;
    ~RemoveCommand() = default;

    string getCommandType() override;
    void execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

/**
 * @class ReplaceCommand
 * @brief Lớp đại diện cho lệnh thay thế trong hệ thống
 * @details Lớp này thực hiện việc thay thế một thực thể trong cơ sở dữ liệu bằng một thực thể mới.
 */
class ReplaceCommand: public ICommand{
public:
    ReplaceCommand() = default;
    ~ReplaceCommand() = default;

    string getCommandType() override;
    void execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

/**
 * @class Notification
 * @brief Lớp đại diện cho lệnh thông báo trong hệ thống
 * @details Lớp này thực hiện việc gửi thông báo đến người dùng.
 */
class Notification: public ICommand {
public:
    Notification() = default;
    ~Notification() = default;

    string getCommandType() override;
    void execute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand) override;
};

/**
 * @class TurnOffProgram
 * @brief Lớp đại diện cho lệnh tắt chương trình
 * @details Lớp này thực hiện việc tắt chương trình và giải phóng tài nguyên.
 */
class TurnOffProgram{
public:
    TurnOffProgram() = default;
    ~TurnOffProgram() = default;

    static void execute(map<string, IDatabase*> mappingDatabase);
};


/**
 * @class CommandFactory
 * @brief Lớp factory để tạo các lệnh dựa trên loại lệnh
 * @details Lớp này cung cấp phương thức để tạo các lệnh cụ thể dựa trên chuỗi loại lệnh.
 */
class CommandFactory{
public:
    static ICommand* create(const string& typeCommand);
};

#endif