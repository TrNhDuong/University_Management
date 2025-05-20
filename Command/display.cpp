#include "display.h"
#include "../utils.h"
#include <memory>
#include <iostream>

using std::cin;


void StudentUI::print(BaseEntity* student){
    Student* st = dynamic_cast<Student*>(student);
    if (st){
        cout << format(
            "{:10}|{:40}|{:02}/{:02}/{:04}|{:5}|{:4}\n",
            st->getId(),st->getName(), 
            st->getBirth().getDay(), st->getBirth().getMonth(), st->getBirth().getYear(), 
            st->getGPA(), st->getCompletedCredit()
            );
    }
}

void LecturerUI::print(BaseEntity* lecturer){
    Lecturer* lec = dynamic_cast<Lecturer*>(lecturer);
    if (lec){
        cout << format(
            "{:10}|{:40}|{:02}/{:02}/{:4}|{:5}|{:4}\n",
            lec->getId(), lec->getName(), 
            lec->getBirth().getDay(), lec->getBirth().getMonth(), lec->getBirth().getYear(),
            lec->getInstructYear(), lec->getDegree()
        );
    }
}

void FacultyUI::print(BaseEntity* faculty){
    Faculty* facul = dynamic_cast<Faculty*>(faculty);
    if (facul){
        cout << format(
            "{:10}|{:40}|{:02}/{:02}/{:4}|{:30}|{:25}\n",
            facul->getId(), facul->getName(),
            facul->getBirth().getDay(), facul->getBirth().getMonth(), facul->getBirth().getYear(), 
            facul->getMail(), facul->getDean().getName()
        );
    }
}


void StudentDatabaseDisplay::display(IDatabase* database){
    StudentDatabase* studentDTB = dynamic_cast<StudentDatabase*>(database);
    int menuSize = studentDTB->getSize();
    std::unique_ptr<IUI> printer = std::make_unique<StudentUI>();
    vector<BaseEntity*> data;
    for (int i = 0; i < menuSize; i++){
        data.push_back(studentDTB->getData(i));
    }
    PrintMenuNewFormat::printMenu(data, "STUDENT DATABASE", "Student");

}


StudentDatabaseDisplay::~StudentDatabaseDisplay(){

}

void LecturerDatabaseDisplay::display(IDatabase* database){
    // dynamic_cast<LecturerDatabase*>(database);
    LecturerDatabase* lecturerDTB = dynamic_cast<LecturerDatabase*>(database);
    int menuSize = lecturerDTB-> getSize();
    std::unique_ptr<IUI> printer = std::make_unique<LecturerUI>();
    vector<BaseEntity*> data;
    for (int i = 0; i < menuSize; i++){
        data.push_back(lecturerDTB->getData(i));
    }
    PrintMenuNewFormat::printMenu(data, "LECTURER DATABASE", "Lecturer");
}

LecturerDatabaseDisplay::~LecturerDatabaseDisplay(){

}
void FacultyDatabaseDisplay::display(IDatabase* database){
    // dynamic_cast<FacultyDatabase*>(database);
    FacultyDatabase* facultyDTB = dynamic_cast<FacultyDatabase*>(database);
    int menuSize = facultyDTB-> getSize();
    std::unique_ptr<IUI> printer = std::make_unique<FacultyUI>();
    vector<BaseEntity*> data;
    for (int i = 0; i < menuSize; i++){
        data.push_back(facultyDTB->getData(i));
    }
    PrintMenuNewFormat::printMenu(data, "FACULTY DATABASE", "Faculty");
}

FacultyDatabaseDisplay::~FacultyDatabaseDisplay(){

}

IDisplay* DisplayFactory::createDisplay(const string& type){
    if ("Student" == type){
        return new StudentDatabaseDisplay();
    } else if ("Lecturer" == type){
        return new LecturerDatabaseDisplay();
    } else if ("Faculty" == type){
        return new FacultyDatabaseDisplay();
    }
    return nullptr;
}

void PrintMenuNewFormat::printMenu(vector<BaseEntity*>& data,const string& title, string type){
    int selected = 0;
    char key;
    if (type == "Student"){
        int width = 73;
        while (true){
            clearScreen();
            setColor(37);
            cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
            size_t leftPad = (width - title.length()) / 2;
            size_t rightPad = width - title.length() - leftPad-1;
            cout << "║"
                << std::string(leftPad, ' ') << title << std::string(rightPad, ' ')
                << "║\n";
            cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
            cout << format(
                "║{:11}{:35}{:14}{:6}{:4}║\n",
                "ID", "Name", "Birth", "GPA", "Credit"
            );
            cout << "╠════════════════════════════════════════════════════════════════════════╣\n";

            for (int i = 0; i < data.size(); i++){
                if (i == selected){
                    setColor(32);
                }else{
                    setColor(37);
                }

                Student *st = dynamic_cast<Student*>(data[i]);
                cout << format(
                    "║{:11}{:35}{:02}/{:02}/{:4}{:^12}{:^4}║\n",
                    st->getId(),st->getName(), 
                    st->getBirth().getDay(), st->getBirth().getMonth(), st->getBirth().getYear(), 
                    st->getGPA(), st->getCompletedCredit()
                );
                setColor(37);
                
            }

            cout << "╚════════════════════════════════════════════════════════════════════════╝\n"; 

            key = getch();
            if (key == '\033') { // Phím mũi tên
                getch(); // Bỏ qua ký tự '['
                key = getch();
                if (key == 'A') selected = (selected - 1 + data.size()) % data.size(); // Lên
                else if (key == 'B') selected = (selected + 1) % data.size();       // Xuống
            }
            else if (key == ' ') {
                break;
            }
        }
    }else if (type == "Lecturer"){
        int width = 73;
        while (true){
            clearScreen();
            setColor(37);
            cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
            size_t leftPad = (width - title.length()) / 2;
            size_t rightPad = width - title.length() - leftPad-1;
            cout << "║"
                << std::string(leftPad, ' ') << title << std::string(rightPad, ' ')
                << "║\n";
            cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
            cout << format(
                "║   {:10}{:25}{:14}{:13}{:7}║\n",
                "ID", "Name", "Birth", "Degree", "Year"
            );
            cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
            for (int i = 0; i < data.size(); i++){
                if (i == selected){
                    setColor(32);
                }else{
                    setColor(37);
                }
                Lecturer *lec = dynamic_cast<Lecturer*>(data[i]);
                cout << format(
                    "║{:11}{:25}{:02}/{:02}/{:<9}{:10}{:8}   ║\n",
                    lec->getId(), lec->getName(), 
                    lec->getBirth().getDay(), lec->getBirth().getMonth(), lec->getBirth().getYear(),
                    lec->getDegree(), lec->getInstructYear()
                );
                setColor(37);
            }

            cout << "╚════════════════════════════════════════════════════════════════════════╝\n";

            key = getch();
            if (key == '\033') { // Phím mũi tên
                getch(); // Bỏ qua ký tự '['
                key = getch();
                if (key == 'A') selected = (selected - 1 + data.size()) % data.size(); // Lên
                else if (key == 'B') selected = (selected + 1) % data.size();       // Xuống
            }
            else if (key == ' ') {
                break;
            }
        }
    }else if (type == "Faculty"){
        int width = 85;
        while (true){
            clearScreen();
            setColor(37);
            cout << "╔════════════════════════════════════════════════════════════════════════════════════╗\n";
            std::string title = "FACULTY DATABASE";
            size_t leftPad = (width - title.length()) / 2;
            size_t rightPad = width - title.length() - leftPad-1;
            cout << "║"
                << std::string(leftPad, ' ') << title << std::string(rightPad, ' ')
                << "║\n";
            cout << "╠════════════════════════════════════════════════════════════════════════════════════╣\n";
            cout << format(
                "║ {:<15}{:20}{:<10}{:^20}{:^18}║\n",
                "ID", "Name", "Birth", "Mail", "Dean"
            );

            cout << "╠════════════════════════════════════════════════════════════════════════════════════╣\n";
            for (int i = 0; i < data.size(); i++){
                if (i == selected){
                    setColor(32);
                }else{
                    setColor(37);
                }
                Faculty *facul = dynamic_cast<Faculty*>(data[i]);
                cout << format(
                    "║{:<9}{:<24}{:02}/{:02}/{:<9}{:20}{:16}║\n",
                    facul->getId(), facul->getName(),
                    facul->getBirth().getDay(), facul->getBirth().getMonth(), facul->getBirth().getYear(), 
                    facul->getMail(), facul->getDean().getName()
                );
                setColor(37);
            }
            cout << "╚════════════════════════════════════════════════════════════════════════════════════╝\n";
            
            key = getch();
            if (key == '\033') { // Phím mũi tên
                getch(); // Bỏ qua ký tự '['
                key = getch();
                if (key == 'A') selected = (selected - 1 + data.size()) % data.size(); // Lên
                else if (key == 'B') selected = (selected + 1) % data.size();       // Xuống
            }
            else if (key == ' ') {
                break;
            }
        }
    }
}