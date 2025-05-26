#ifndef SEND_MAIL_H
#define SEND_MAIL_H
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <fstream>
using namespace std;

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