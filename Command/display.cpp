#include "display.h"
#include <memory>


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
    std::unique_ptr<IUI> printer = std::make_unique<StudentUI>();
    int size = studentDTB->getSize();
    for (int i = 0; i < size; i++)
        printer->print(studentDTB->getData(i));
};

StudentDatabaseDisplay::~StudentDatabaseDisplay(){

}

void LecturerDatabaseDisplay::display(IDatabase* database){
    LecturerDatabase* lecturerDTB = dynamic_cast<LecturerDatabase*>(database);
    int size = lecturerDTB->getSize();
    std::unique_ptr<IUI> printer = std::make_unique<LecturerUI>();
    for (int i = 0; i < size; i++)
        printer->print(lecturerDTB->getData(i));
}

LecturerDatabaseDisplay::~LecturerDatabaseDisplay(){

}

void FacultyDatabaseDisplay::display(IDatabase* database){
    FacultyDatabase* facultyDTB = dynamic_cast<FacultyDatabase*>(database);
    int size = facultyDTB->getSize();
    std::unique_ptr<IUI> printer = std::make_unique<FacultyUI>();
    for (int i = 0; i < size; i++)
        printer->print(facultyDTB->getData(i));
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