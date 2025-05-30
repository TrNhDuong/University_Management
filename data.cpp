#include "data.h"

#pragma region getDataType
string StudentDatabase::getDataType() const {
    return "Student";
}

string LecturerDatabase::getDataType() const {
    return "Lecturer";
}

string FacultyDatabase::getDataType() const {
    return "Faculty";
}
#pragma endregion

#pragma region getSize

int StudentDatabase::getSize() const {
    return _data.size();
}

int LecturerDatabase::getSize() const {
    return _data.size();
}

int FacultyDatabase::getSize() const {
    return _data.size();
}
#pragma endregion

#pragma region find(id)
//return -1 if not exists in database
int StudentDatabase::find(const string& id) const {
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1;
    return i;
}

int LecturerDatabase::find(const string& id) const{
    int i = 0;
    for (i ; i < _data.size(); ++i){
        if (_data[i].getId() == id) break;
    }
    if (i == _data.size()) return -1; 
    return i;
}

int FacultyDatabase::find(const string& id) const{
    int size = _data.size();
    int index = -1;
    for (int i = 0; i < size; i++)
        if (_data[i].getId() == id){
            index = i;
            break;
        }
    return index;
}

#pragma endregion

#pragma region getData
//Get data at index 
BaseEntity* FacultyDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Faculty out of bound\n");
    }
    return &_data[index];
}

BaseEntity* StudentDatabase::getData(const int& index){
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Student out of bound\n");
    }
    return &_data[index];
}

BaseEntity* LecturerDatabase::getData(const int& index){ //return the instance 
    if (index < 0 || index >= _data.size()){
        throw std::out_of_range ("Index Lecturer out of bound\n");
    }
    return &_data[index];
}

#pragma endregion

#pragma region Add, Remove, Replace Student
//Add, Remove, Replace method
//Student
void StudentDatabase:: Add(BaseEntity* obj){
    Student* s = dynamic_cast<Student*>(obj);
    _data.push_back(*s);
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
bool StudentDatabase::Remove(BaseEntity* obj){
    return Remove(obj->getId());
}

bool StudentDatabase::Replace(BaseEntity* d, BaseEntity* s){
    Student* des = dynamic_cast<Student*>(d);
    Student* scr = dynamic_cast<Student*>(s);
    int index = find(des->getId());
    if(index >= 0){
        _data[index].setName(scr->getName());
        _data[index].setId(scr->getId());
        _data[index].setBirth(scr->getBirth());
        _data[index].setGPA(scr->getGPA());
        _data[index].setEnrollYear(scr->getEnrollYear());
        _data[index].setCredit(scr->getCompletedCredit());
        return true;
    }else {
        return false; //if des obj not found
    }
}
#pragma endregion

#pragma region Add, Remove, Replace Faculty

void FacultyDatabase:: Add(BaseEntity* obj){
    Faculty* s = dynamic_cast<Faculty*>(obj);
    _data.push_back(*s);
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
bool FacultyDatabase::Remove(BaseEntity* obj){
    return Remove(obj->getId());
}


bool FacultyDatabase::Replace(BaseEntity* d, BaseEntity* s){
    Faculty* scr = dynamic_cast<Faculty*>(s);
    Faculty* des = dynamic_cast<Faculty*>(d);
    int index = find(des->getId());
    if(index >= 0){
        _data[index].setName(scr->getName());
        _data[index].setId(scr->getId());
        _data[index].setBirth(scr->getBirth());
        _data[index].setMail(scr->getMail());
        _data[index].setDean(scr->getDean());
        return true;
    }else {
        return false; //if des obj not found
    }
}

#pragma endregion

#pragma region Add, Remove, Replace Lecturer

void LecturerDatabase:: Add(BaseEntity* obj){
    Lecturer* s = dynamic_cast<Lecturer*>(obj);
    _data.push_back(*s);
}
Faculty* FacultyDatabase::findDean(const string& Id_gv) {  // trả về đối tượng là Faculty có Id trưởng khoa khớp với tham số truyền vào
    if (Id_gv == "NULL" || Id_gv == "") return nullptr;
    for (int i = 0; i < _data.size(); ++i){
        if (_data[i].getDean().getId() == Id_gv){ //lấy id của trưởng khoa so sánh với Id_gv
            return &_data[i]; //trả về tham chiếu chứa thông tin faculty 
        }
    }
    return nullptr; 

}
bool LecturerDatabase::Remove(const string& ID){
    for (int i = 0; i < _data.size(); ++i){
        if (ID == _data[i].getId()){
            //Kiểm tra tính ràng buộc dữ liệu
            //setting Null for dean if dean ID == ID
            FacultyDatabase& facultyDb = FacultyDatabase::getInstance();
            // find khoa thông qua id giáo viên để trả về một đối tượng con trỏ khoa có trưởng khoa là ID
            Faculty* obj = (facultyDb.findDean(ID));
            if (obj){
                // Nếu xóa 1 giáo viên mà giáo viên đó làm trưởng khoa -> sẽ tiến hành set null cho Dean của khoa.
                Lecturer zombie;
                zombie.setId("NULL");
                zombie.setName("NULL");
                zombie.setBirth("01/01/01");
                obj->setDean(zombie);
            } 
            _data.erase(_data.begin()+i);
            return true; 
            break;
        }
    }
    return false; //if delete failed
}
bool LecturerDatabase::Remove(BaseEntity* obj){
    return Remove(obj->getId());
}

bool LecturerDatabase::Replace(BaseEntity* d, BaseEntity* s){
    Lecturer* des = dynamic_cast<Lecturer*>(d);
    Lecturer* scr = dynamic_cast<Lecturer*>(s);
    //Kiểm tra xem scr có là trưởng khoa ? nếu có thì set null
    FacultyDatabase& facultyDb = FacultyDatabase::getInstance();
    Faculty* obj = (facultyDb.findDean(des->getId()));
    
    int index = find(des->getId());
    if(index >= 0){
        _data[index].setName(scr->getName());
        _data[index].setId(scr->getId());
        _data[index].setBirth(scr->getBirth());
        _data[index].setInstructYear(scr->getInstructYear());
        _data[index].setDeg(scr->getDegree());
        //Nếu như des có tồn tại trong bảng giáo viên -> Tiến hành xóa trưởng khoa
        if (obj){
                // Nếu xóa 1 giáo viên mà giáo viên đó làm trưởng khoa -> sẽ tiến hành set null cho Dean của khoa.
                Lecturer zombie;
                zombie.setId("NULL");
                zombie.setName("NULL");
                zombie.setBirth("01/01/01");
                obj->setDean(zombie); //khoa set trưởng khoa là NULL 
            } 
        return true;
    }else {
        return false; //if des obj not found
    }
}

#pragma endregion