/**
 * @file sendMail.h
 * @brief Gửi email thông báo
 * @details Lớp này sử dụng thư viện cURL để gửi email thông báo đến người nhận.
 * @note Bao gồm các phương thức để lấy API key, nhập thông tin người nhận, tiêu đề và nội dung email.
 * @note Lớp này cung cấp phương thức excute để thực hiện việc gửi email.
 * @note Sử dụng thư viện cURL để thực hiện các yêu cầu HTTP POST đến API gửi email.
*/

#ifndef SEND_MAIL_H
#define SEND_MAIL_H
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <fstream>
#include <vector>
#include "../data.h"
#include <map>
using namespace std;

/**
 * @class MailSV
 * @brief Lớp đại diện cho máy gửi email thông báo
 * @details Lớp này sử dụng thư viện cURL để gửi email thông báo đến người nhận.
 * @note Bao gồm các phương thức để lấy API key, nhập thông tin người nhận, tiêu đề và nội dung email.
 * @note Cung cấp phương thức excute để thực hiện việc gửi email.
 */
class MailCommand {
private:
    static size_t WriteCallback(char *contents, size_t size, size_t nmemb, string *response);
    string getAPIkey();
    vector<string> getReceiver(IDatabase* db);
    string inputHeader();
    string inputContent();
    void sendMail(vector<string> to_mail, string subject, string content);
public:
    MailCommand() = default;
    void excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand);
    ~MailCommand() = default;
};

#endif