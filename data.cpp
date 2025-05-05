/**
 * @file data.cpp
 * @brief Triển khai các lớp cơ sở dữ liệu cho sinh viên, giảng viên và khoa.
 * @details Các lớp này quản lý danh sách sinh viên, giảng viên và khoa trong hệ thống.
 */

#include "data.h"

/**
 * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
 * @return Kiểu dữ liệu của cơ sở dữ liệu.
 * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
 */
string StudentDatabase::getDataType() const {
    return "Student";
}

/**
 * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
 * @return Kiểu dữ liệu của cơ sở dữ liệu.
 * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
 */
string LecturerDatabase::getDataType() const {
    return "Lecturer";
}

/**
 * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
 * @return Kiểu dữ liệu của cơ sở dữ liệu.
 * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
 */
string FacultyDatabase::getDataType() const {
    return "Faculty";
}


/**
 * @brief Lấy kích thước của cơ sở dữ liệu.
 * @return Kích thước của cơ sở dữ liệu.
 * @details Hàm này trả về số lượng đối tượng trong cơ sở dữ liệu.
 */
int StudentDatabase::getSize() const {
    return _data.size();
}

/**
 * @brief Tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh.
 * @param id Mã định danh của đối tượng cần tìm.
 * @return Chỉ số của đối tượng trong cơ sở dữ liệu, hoặc -1 nếu không tìm thấy.
 * @details Hàm này tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh và trả về chỉ số của nó.
 */
int FacultyDatabase::find(const string& id) const {

    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; //return -1 if it not find out
    return i;
}

/**
 * @brief Tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh.
 * @param id Mã định danh của đối tượng cần tìm.
 * @return Chỉ số của đối tượng trong cơ sở dữ liệu, hoặc -1 nếu không tìm thấy.
 * @details Hàm này tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh và trả về chỉ số của nó.
 */
int StudentDatabase::find(const string& id) const {
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; //return -1 if it not find out
    return i;
}

/**
 * @brief Tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh.
 * @param id Mã định danh của đối tượng cần tìm.
 * @return Chỉ số của đối tượng trong cơ sở dữ liệu, hoặc -1 nếu không tìm thấy.
 * @details Hàm này tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh và trả về chỉ số của nó.
 */
int LecturerDatabase::find(const string& id) const{ //return the index
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; //return -1 if it not find out
    return i;
}

/**
 * @brief Lấy dữ liệu từ cơ sở dữ liệu theo chỉ số.
 * @param index Chỉ số của đối tượng cần lấy.
 * @return Tham chiếu đến đối tượng trong cơ sở dữ liệu.
 * @details Hàm này trả về một tham chiếu đến đối tượng trong cơ sở dữ liệu theo chỉ số.
 */
Faculty& FacultyDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Faculty out of bound\n");
    }
    return _data[index];
}

/**
 * @brief Lấy dữ liệu từ cơ sở dữ liệu theo chỉ số.
 * @param index Chỉ số của đối tượng cần lấy.
 * @return Tham chiếu đến đối tượng trong cơ sở dữ liệu.
 * @details Hàm này trả về một tham chiếu đến đối tượng trong cơ sở dữ liệu theo chỉ số.
 */
Student& StudentDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Student out of bound\n");
    }
    return _data[index];
}

/**
 * @brief Lấy dữ liệu từ cơ sở dữ liệu theo chỉ số.
 * @param index Chỉ số của đối tượng cần lấy.
 * @return Tham chiếu đến đối tượng trong cơ sở dữ liệu.
 * @details Hàm này trả về một tham chiếu đến đối tượng trong cơ sở dữ liệu theo chỉ số.
 */
Lecturer& LecturerDatabase::getData(const int& index){ //return the instance 
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Lecturer out of bound\n");
    }
    return _data[index];
}


/**
 * @brief Thêm một đối tượng vào cơ sở dữ liệu.
 * @param obj Đối tượng cần thêm vào cơ sở dữ liệu.
 * @details Hàm này thêm một đối tượng vào cơ sở dữ liệu.
 */
void StudentDatabase:: Add(const Student& obj){
    _data.push_back(obj);
}

bool StudentDatabase::Remove(const string& ID){
    for (int i = 0; i < _data.size(); ++i){
        if (ID == _data[i].getId()){
            _data.erase(_data.begin()+i);
            return true; 
            break;
        }
    }
    return false; //if delete failed
}

/**
 * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
 * @param obj Đối tượng cần xóa khỏi cơ sở dữ liệu.
 * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
 * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
 */
bool StudentDatabase::Remove(Student& obj){
    return Remove(obj.getId());
}

/**
 * @brief Thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
 * @param des Đối tượng cần thay thế.
 * @param src Đối tượng mới thay thế.
 * @return true nếu thay thế thành công, false nếu không tìm thấy đối tượng cần thay thế.
 * @details Hàm này thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
 */
bool StudentDatabase::Replace(Student& des, Student& src){
    int index = find(des.getId());
    if(index >= 0){
        _data[index].setName(src.getName());
        _data[index].setId(src.getId());
        _data[index].setBirth(src.getBirth());
        _data[index].setGPA(src.getGPA());
        _data[index].setEnrollYear(src.getEnrollYear());
        _data[index].setCredit(src.getCompletedCredit());
        return true;
    }else {
        return false; //if des obj not found
    }
}


/**
 * @brief Thêm một đối tượng vào cơ sở dữ liệu.
 * @param obj Đối tượng cần thêm vào cơ sở dữ liệu.
 * @details Hàm này thêm một đối tượng vào cơ sở dữ liệu.
 */
void FacultyDatabase:: Add(const Faculty& obj){
    _data.push_back(obj);
}
bool FacultyDatabase::Remove(const string& ID){
    for (int i = 0; i < _data.size(); ++i){
        if (ID == _data[i].getId()){
            _data.erase(_data.begin()+i);
            return true; 
            break;
        }
    }
    return false; //if delete failed
}

/**
 * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
 * @param obj Đối tượng cần xóa khỏi cơ sở dữ liệu.
 * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
 * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
 */
bool FacultyDatabase::Remove(Faculty& obj){
    return Remove(obj.getId());
}
bool FacultyDatabase::Replace(Faculty& des, Faculty& src){
    int index = find(des.getId());
    if(index >= 0){
        _data[index].setName(src.getName());
        _data[index].setId(src.getId());
        _data[index].setBirth(src.getBirth());
        _data[index].setMail(src.getMail());
        _data[index].setDean(src.getDean());
        return true;
    }else {
        return false; //if des obj not found
    }
}



/**
 * @brief Thêm một đối tượng vào cơ sở dữ liệu.
 * @param obj Đối tượng cần thêm vào cơ sở dữ liệu.
 * @details Hàm này thêm một đối tượng vào cơ sở dữ liệu.
 */
void LecturerDatabase:: Add(const Lecturer& obj){
    _data.push_back(obj);
}
bool LecturerDatabase::Remove(const string& ID){
    for (int i = 0; i < _data.size(); ++i){
        if (ID == _data[i].getId()){
            _data.erase(_data.begin()+i);
            return true; 
            break;
        }
    }
    return false; //if delete failed
}

/**
 * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
 * @param obj Đối tượng cần xóa khỏi cơ sở dữ liệu.
 * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
 * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
 */
bool LecturerDatabase::Remove(Lecturer& obj){
    return Remove(obj.getId());
}

/**
 * @brief Thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
 * @param des Đối tượng cần thay thế.
 * @param src Đối tượng mới thay thế.
 * @return true nếu thay thế thành công, false nếu không tìm thấy đối tượng cần thay thế.
 * @details Hàm này thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
 */
bool LecturerDatabase::Replace(Lecturer& des, Lecturer& src){
    int index = find(des.getId());
    if(index >= 0){
        _data[index].setName(src.getName());
        _data[index].setId(src.getId());
        _data[index].setBirth(src.getBirth());
        _data[index].setInstructYear(src.getInstructYear());
        _data[index].setDeg(src.getDegree());
        return true;
    }else {
        return false; //if des obj not found
    }
}

/**
 * @brief Nhập dữ liệu cho sinh viên từ bàn phím.
 * @param student Đối tượng sinh viên cần nhập dữ liệu.
 * @details Hàm này yêu cầu người dùng nhập thông tin cho sinh viên và lưu vào đối tượng sinh viên.
 */
void StudentGetData::InputData(Student& student){
    cout << "Nhập tên sinh viên: ";
    string name;
    cin.ignore();
    getline(cin, name);
    student.setName(name);
    cout << "Nhập mã sinh viên: ";
    string id;
    cin >> id;
    student.setId(id);
    cout << "Nhập ngày sinh sinh viên (dd/mm/yyyy): ";
    string birth;
    cin >> birth;
    student.setBirth(birth);

    cout << "Nhập điểm trung bình sinh viên: ";
    float gpa;
    cin >> gpa;
    student.setGPA(gpa);

    cout << "Nhập số tín chỉ đã hoàn thành: ";
    int completedCredit;
    cin >> completedCredit;
    student.setCredit(completedCredit);
}

/**
 * @brief Nhập dữ liệu cho giảng viên từ bàn phím.
 * @param lecturer Đối tượng giảng viên cần nhập dữ liệu.
 * @details Hàm này yêu cầu người dùng nhập thông tin cho giảng viên và lưu vào đối tượng giảng viên.
 */
void LecturerGetData::InputData(Lecturer& lecturer){
    cout << "Nhập tên giảng viên: ";
    string name;
    cin.ignore();
    getline(cin, name);
    lecturer.setName(name);
    cout << "Nhập mã giảng viên: ";
    string id;
    cin >> id;
    lecturer.setId(id);
    cout << "Nhập ngày sinh giảng viên (dd/mm/yyyy): ";
    string birth;
    cin >> birth;
    lecturer.setBirth(birth);

    cout << "Nhập năm giảng dạy: ";
    int instructYear;
    cin >> instructYear;
    lecturer.setInstructYear(instructYear);

    cout << "Nhập học vị: ";
    string degree;
    cin.ignore();
    getline(cin, degree);
    lecturer.setDeg(degree);
}

/**
 * @brief Nhập dữ liệu cho khoa từ bàn phím.
 * @param faculty Đối tượng khoa cần nhập dữ liệu.
 * @details Hàm này yêu cầu người dùng nhập thông tin cho khoa và lưu vào đối tượng khoa.
 */
void FacultyGetData::InputData(Faculty& faculty){
    cout << "Nhập tên khoa: ";
    string name;
    cin.ignore();
    getline(cin, name);
    faculty.setName(name);
    cout << "Nhập mã khoa: ";
    string id;
    cin >> id;
    faculty.setId(id);
    cout << "Nhập ngày thành lập khoa (dd/mm/yyyy): ";
    string birth;
    cin >> birth;
    faculty.setBirth(birth);

    cout << "Nhập email khoa: ";
    string email;
    cin.ignore();
    getline(cin, email);
    faculty.setMail(email);

    cout << "Nhập mã giảng viên trưởng khoa: ";
    string deanId;
    cin >> deanId;
    LecturerDatabase& lecturerDB = LecturerDatabase::getInstance();
    int index = lecturerDB.find(deanId);
    if (index != -1) {
        faculty.setDean(lecturerDB.getData(index));
    } else {
        cout << "Giảng viên không tồn tại trong hệ thống.\n";
        return;
    }
      
}