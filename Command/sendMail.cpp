#include "sendMail.h"

size_t MailCommand::WriteCallback(char *contents, size_t size, size_t nmemb, string *response){
    size_t total_size = size * nmemb;
    response->append(contents, total_size);
    return total_size;
}

string MailCommand::getAPIkey(){
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

vector<string> MailCommand::getReceiver(IDatabase* db){
    vector<string> receiver;
    for (int i = 0; i < db->getSize(); i++)
        receiver.push_back(db->getData(i)->getMail());
    return receiver;
}

string MailCommand::inputHeader(){
    string header;
    cout << "Tieu de: ";
    getline(cin, header);
    return header;
}

string MailCommand::inputContent(){
    string content;
    cout << "Noi dung: ";
    getline(cin, content);
    return content;
}

void MailCommand::sendMail(vector<string> toMail, string subject, string content ){
    string from_email = "nhatduong01012005@gmail.com";
    std::string api_key = getAPIkey(); // không nên để public
    CURL *curl;
    CURLcode res;
    string response_string;

    std::string to_recipients_json;
    for (size_t i = 0; i < toMail.size(); ++i) {
        to_recipients_json += "{ \"email\": \"" + toMail[i] + "\" }";
        if (i < toMail.size() - 1) {
            to_recipients_json += ", ";
        }
    }

    string post_data = "{"
        "\"personalizations\": ["
            "{"
                "\"to\": [" + to_recipients_json + "]"
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


void MailCommand::excute(map<string, IDatabase*> mappingDatabase, string typeEntity, const string& typeOfSubCommand){
    IDatabase* db = mappingDatabase[typeEntity];
    vector<string> receiver = getReceiver(db);
    string header = inputHeader();
    string content = inputContent();
    sendMail(receiver, header, content);
}
