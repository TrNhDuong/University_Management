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
using namespace std;

/**
 * @class MailSV
 * @brief Lớp đại diện cho máy gửi email thông báo
 * @details Lớp này sử dụng thư viện cURL để gửi email thông báo đến người nhận.
 * @note Bao gồm các phương thức để lấy API key, nhập thông tin người nhận, tiêu đề và nội dung email.
 * @note Cung cấp phương thức excute để thực hiện việc gửi email.
 */
class MailSV {
private:
    static size_t WriteCallback(char *contents, size_t size, size_t nmemb, string *response);
    string getAPIkey();
    string inputReceiver();
    string inputHeader();
    string inputContent();
    void sendMail(string to_mail, string subject, string content);
public:
    MailSV() = default;
    void excute();
    ~MailSV() = default;
};

#endif