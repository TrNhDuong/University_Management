#include "command.h"
#include "display.h"

void StudentAddHandler::Add() {
    Student student;
    cout << "Nhập thông tin sinh viên: \n";
    StudentGetData::InputData(student);
    studentDB->Add(student);
}

void LecturerAddHandler::Add() {
    Lecturer lecturer;
    cout << "Nhập thông tin giảng viên: \n";
    LecturerGetData::InputData(lecturer);
    lecturerDB->Add(lecturer);
}

void FacultyAddHandler::Add() {
    Faculty faculty;
    cout << "Nhập thông tin khoa: \n";
    FacultyGetData::InputData(faculty);
    facultyDB->Add(faculty);
}

IAddHandler* AddHandlerFactory::Create(const string& type) {
    if (type == "1") {
        return new StudentAddHandler();
    } else if (type == "2") {
        return new LecturerAddHandler();
    } else if (type == "3") {
        return new FacultyAddHandler();
    }
    return nullptr;
}

void AddCommand::execute() {
    string entityChoice;

    while (true) {
        entityChoice = menu->getChoice();
        if (entityChoice == "4") break;

        IAddHandler* handler = AddHandlerFactory::Create(entityChoice);
        if (handler) {
            handler->Add();
            delete handler;
        } else {
            cout << "Bạn đã nhập sai, mời nhập lại!\n";
        }

        getch();
    }
}

class StudentReplaceHandler : public IReplaceHandler {
public:
    void Replace() override {
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
    }
};

class LecturerReplaceHandler : public IReplaceHandler {
public:
    void Replace() override {
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
    }
};
class FacultyReplaceHandler : public IReplaceHandler {
public:
    void Replace() override {
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
    }
};


IReplaceHandler* ReplaceHandlerFactory::Create(const string& type) {
    if (type == "1") {
        return new StudentReplaceHandler();
    } else if (type == "2") {
        return new LecturerReplaceHandler();
    } else if (type == "3") {
        return new FacultyReplaceHandler();
    }
    return nullptr;
}

void ReplaceCommand::execute() {
    string entityChoice;

    while (true) {
        entityChoice = menu->getChoice();
        if (entityChoice == "4") break;

        IReplaceHandler* handler = ReplaceHandlerFactory::Create(entityChoice);
        if (handler) {
            handler->Replace();
            delete handler;
        } else {
            cout << "Bạn đã nhập sai, mời nhập lại!\n";
        }

        getch();
    }
}

class StudentRemoveHandler : public IRemoveHandler {
public:
    void Remove() override {
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
    }
};

class LecturerRemoveHandler : public IRemoveHandler {
public:
    void Remove() override {
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
    }
};

class FacultyRemoveHandler : public IRemoveHandler {
public:
    void Remove() override {
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
    }
};

IRemoveHandler* RemoveHandlerFactory::Create(const string& type) {
    if (type == "1") {
        return new StudentRemoveHandler();
    } else if (type == "2") {
        return new LecturerRemoveHandler();
    } else if (type == "3") {
        return new FacultyRemoveHandler();
    }
    return nullptr;
}

void RemoveCommand::execute() {
    string entityChoice;

    while (true) {
        entityChoice = menu->getChoice();
        if (entityChoice == "4") break;

        std::unique_ptr<IRemoveHandler> handler(RemoveHandlerFactory::Create(entityChoice));
        if (handler) {
            handler->Remove();
        } else {
            cout << "Bạn đã nhập sai, mời nhập lại!\n";
        }

        getch();
    }
}

void StudentDisplayHandler::Display() {
    cout << "Danh sách sinh viên:\n";
    studentDB->Display();
}
void LecturerDisplayHandler::Display() {
    cout << "Danh sách giảng viên:\n";
    lecturerDB->Display();
}
void FacultyDisplayHandler::Display() {
    cout << "Danh sách khoa:\n";
    facultyDB->Display();
}
IDisplayHandler* DisplayHandlerFactory::Create(const string& type) {
    if (type == "1") {
        return new StudentDisplayHandler();
    } else if (type == "2") {
        return new LecturerDisplayHandler();
    } else if (type == "3") {
        return new FacultyDisplayHandler();
    }
    return nullptr;
}

void DisplayCommand::execute() {
    string entityChoice;

    while (true) {
        menu->display();
        entityChoice = menu->getChoice();
        if (entityChoice == "4") break;

        std::unique_ptr<IDisplayHandler> handler(DisplayHandlerFactory::Create(entityChoice));
        if (handler) {
            handler->Display();
        } else {
            cout << "Bạn yêu đã nhập sai, mời nhập lại!\n";
        }

        getch();
    }
}
