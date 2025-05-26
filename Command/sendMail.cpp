#include "sendMail.h"

size_t MailSV::WriteCallback(char *contents, size_t size, size_t nmemb, string *response){
    size_t total_size = size * nmemb;
    response->append(contents, total_size);
    return total_size;
}

string MailSV::getAPIkey(){
    string apiKey;
    fstream file(".env", ios::in);
    string line;
    getline(file, line);
    int i = 0;
    while (line[i] != '=')
        i++;
    i++;
    while (i < line.size())
        apiKey += line[i++];
    return apiKey;
}

string MailSV::inputReceiver(){
    string receiver;
    cout << "Nhap mail nguoi nhan: ";
    getline(cin, receiver);
    return receiver;
}

string MailSV::inputHeader(){
    string header;
    cout << "Tieu de: ";
    getline(cin, header);
    return header;
}

string MailSV::inputContent(){
    string content;
    cout << "Noi dung: ";
    getline(cin, content);
    return content;
}

void MailSV::sendMail(string to_email, string subject, string content ){
    string from_email = "nhatduong01012005@gmail.com";
    std::string api_key = getAPIkey();
    CURL *curl;
    CURLcode res;
    string response_string;

    string post_data = "{"
        "\"personalizations\": ["
            "{"
                "\"to\": ["
                    "{"
                        "\"email\": \"" + to_email + "\""
                    "}"
                "]"
            "}"
        "],"
        "\"from\": {"
            "\"email\": \"" + from_email + "\""
        "},"
        "\"subject\": \"" + subject + "\","
        "\"content\": ["
            "{"
                "\"type\": \"text/plain\","
                "\"value\": \"" + content + "\""
            "}"
        "]"
    "}";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.sendgrid.com/v3/mail/send");
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        // Thiết lập header cho xác thực và content type
        struct curl_slist *headers = nullptr;
        std::string auth_header = "Authorization: Bearer " + api_key;
        headers = curl_slist_append(headers, auth_header.c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Email sent successfully!" << std::endl;
            std::cout << "Response from SendGrid: " << response_string << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

}

void MailSV::excute(){
    string receiver = inputReceiver();
    string header = inputHeader();
    string content = inputContent();
    sendMail(receiver, header, content);
}
