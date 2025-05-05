/**
 * @file data.h
 * @brief Khai báo các lớp cơ sở dữ liệu cho sinh viên, giảng viên và khoa.
 * @details Các lớp này quản lý danh sách sinh viên, giảng viên và khoa trong hệ thống.
 */

#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include "student.h"
#include "lecturer.h"
#include "faculty.h"
#include "baseEntity.h"
#include <exception>
#include <string>
#include <fstream>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::fstream;

/**
 * @class IDatabase
 * @brief Lớp cơ sở cho các cơ sở dữ liệu sinh viên, giảng viên và khoa.
 * @details Các lớp này quản lý danh sách sinh viên, giảng viên và khoa trong hệ thống.
 */
class IDatabase{
public:
    /**
     * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
     * @return Kiểu dữ liệu của cơ sở dữ liệu.
     * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
     */
    virtual string getDataType() const = 0;

    virtual ~IDatabase() = default;
};

/**
 * @class StudentDatabase
 * @brief Lớp cơ sở dữ liệu cho sinh viên.
 * @details Lớp này quản lý danh sách sinh viên trong hệ thống.
 */
class StudentDatabase: public IDatabase{
private:
    /**
     * @brief Danh sách sinh viên.
     */
    vector<Student> _data;

    /**
     * @brief Hàm khởi tạo mặc định.
     */
    StudentDatabase() = default; 

    /**
     * @brief Hàm hủy.
     */
    ~StudentDatabase() override = default;

    /**
     * @brief Hàm sao chép và gán không được phép.
     */
    StudentDatabase(const StudentDatabase&) = delete;

    /**
     * @brief Hàm gán không được phép.
     */
    Student& operator = (const StudentDatabase&) = delete;
public:
    /**
     * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
     * @return Kiểu dữ liệu của cơ sở dữ liệu.
     * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
     */
    string getDataType() const override;

    /**
     * @brief Lấy thể hiện duy nhất của lớp StudentDatabase.
     * @return Tham chiếu đến thể hiện duy nhất của lớp StudentDatabase.
     */
    static StudentDatabase& getInstance(){
        static StudentDatabase instance;
        return instance;
    }

    /**
     * @brief Lấy kích thước của cơ sở dữ liệu.
     * @return Kích thước của cơ sở dữ liệu.
     * @details Hàm này trả về số lượng đối tượng trong cơ sở dữ liệu.
     */
    int getSize() const;
    
    /**
     * @brief Lấy dữ liệu từ cơ sở dữ liệu theo chỉ số.
     * @param index Chỉ số của đối tượng cần lấy.
     * @return Tham chiếu đến đối tượng trong cơ sở dữ liệu.
     * @details Hàm này trả về một tham chiếu đến đối tượng trong cơ sở dữ liệu theo chỉ số.
     */
    Student& getData(const int& index);
    
    /**
     * @brief Tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh.
     * @param id Mã định danh của đối tượng cần tìm.
     * @return Chỉ số của đối tượng trong cơ sở dữ liệu, hoặc -1 nếu không tìm thấy.
     * @details Hàm này tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh và trả về chỉ số của nó.
     */
    int find(const string& id) const;
    /**
     * @brief Thêm một đối tượng vào cơ sở dữ liệu.
     * @param obj Đối tượng cần thêm vào cơ sở dữ liệu.
     * @details Hàm này thêm một đối tượng vào cơ sở dữ liệu.
     */
    void Add(const Student& obj);

    /**
     * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
     * @param ID Mã định danh của đối tượng cần xóa.
     * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
     * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
     */
    bool Remove(const string& ID); 

    /**
     * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
     * @param obj Đối tượng cần xóa khỏi cơ sở dữ liệu.
     * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
     * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
     */
    bool Remove(Student& obj); ///return true if remove succesfully, return false if ID not found

    /**
     * @brief Thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
     * @param des Đối tượng cần thay thế.
     * @param src Đối tượng mới thay thế.
     * @return true nếu thay thế thành công, false nếu không tìm thấy đối tượng cần thay thế.
     * @details Hàm này thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
     */
    bool Replace(Student& des, Student& src); //return true if remove succesfully, return false if des not found
    friend class StudentDatabaseDisplay;
    friend class StudentReadData;
};

/**
 * @class LecturerDatabase
 * @brief Lớp cơ sở dữ liệu cho giảng viên.
 * @details Lớp này quản lý danh sách giảng viên trong hệ thống.
 */
class LecturerDatabase: public IDatabase{
private:
    /**
     * @brief Danh sách giảng viên.
     */
    vector<Lecturer> _data;
    /**
     * @brief Hàm khởi tạo mặc định.
     */
    LecturerDatabase() = default; 
    /**
     * @brief Hàm hủy.
     */
    ~LecturerDatabase() = default;
    /**
     * @brief Hàm sao chép và gán không được phép.
     */
    LecturerDatabase(const LecturerDatabase&) = delete;
    /**
     * @brief Hàm gán không được phép.
     */
    LecturerDatabase& operator = (const LecturerDatabase&) = delete;
public:
    /**
     * @brief Lấy thể hiện duy nhất của lớp LecturerDatabase.
     * @return Tham chiếu đến thể hiện duy nhất của lớp LecturerDatabase.
     */
    static LecturerDatabase& getInstance(){
        /**
         * @brief Thể hiện duy nhất của lớp LecturerDatabase.
         */
        static LecturerDatabase instance;
        return instance;
    }

    /**
     * @brief Lấy kiểu dữ liệu của cơ sở dữ liệu.
     * @return Kiểu dữ liệu của cơ sở dữ liệu.
     * @details Hàm này trả về một chuỗi mô tả kiểu dữ liệu của cơ sở dữ liệu.
     */
    string getDataType() const override;
    
    /**
     * @brief Lấy dữ liệu từ cơ sở dữ liệu theo chỉ số.
     * @param index Chỉ số của đối tượng cần lấy.
     * @return Tham chiếu đến đối tượng trong cơ sở dữ liệu.
     * @details Hàm này trả về một tham chiếu đến đối tượng trong cơ sở dữ liệu theo chỉ số.
     */
    Lecturer& getData(const int& index);

    /**
     * @brief Lấy kích thước của cơ sở dữ liệu.
     * @return Kích thước của cơ sở dữ liệu.
     * @details Hàm này trả về số lượng đối tượng trong cơ sở dữ liệu.
     */
    int find(const string& id) const; //return the index in vector _data, it is necessary (can't use friend to lecturer => invalid action harm to capsulation)
    
    /**
     * @brief Tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh.
     * @param id Mã định danh của đối tượng cần tìm.
     * @return Chỉ số của đối tượng trong cơ sở dữ liệu, hoặc -1 nếu không tìm thấy.
     * @details Hàm này tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh và trả về chỉ số của nó.
     */
    void Add(const Lecturer& obj);

    /**
     * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
     * @param ID Mã định danh của đối tượng cần xóa.
     * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
     * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
     */
    bool Remove(const string& ID);

    /**
     * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
     * @param obj Đối tượng cần xóa khỏi cơ sở dữ liệu.
     * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
     * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
     */
    bool Remove(Lecturer& obj);

    /**
     * @brief Thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
     * @param des Đối tượng cần thay thế.
     * @param src Đối tượng mới thay thế.
     * @return true nếu thay thế thành công, false nếu không tìm thấy đối tượng cần thay thế.
     * @details Hàm này thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
     */
    bool Replace(Lecturer& des, Lecturer& src);


    friend class LecturerDatabaseDisplay;
    friend class LecturerReadData;
};

/**
 * @class FacultyDatabase
 * @brief Lớp cơ sở dữ liệu cho khoa.
 * @details Lớp này quản lý danh sách khoa trong hệ thống.
 */
class FacultyDatabase: public IDatabase{
private:
    /**
     * @brief Danh sách khoa.
     */
    vector<Faculty> _data;

    /**
     * @brief Hàm khởi tạo mặc định.
     */
    FacultyDatabase() = default;
    /**
     * @brief Hàm hủy.
     */
    ~FacultyDatabase() = default;
    /**
     * @brief Hàm sao chép và gán không được phép.
     */
    FacultyDatabase(const FacultyDatabase&) = delete;
    /**
     * @brief Hàm gán không được phép.
     */
    FacultyDatabase& operator = (const FacultyDatabase&) = delete;
public:
    /**
     * @brief Lấy thể hiện duy nhất của lớp FacultyDatabase.
     * @return Tham chiếu đến thể hiện duy nhất của lớp FacultyDatabase.
     */
    static FacultyDatabase& getInstance(){
        /**
         * @brief Thể hiện duy nhất của lớp FacultyDatabase.
         */
        static FacultyDatabase instance;
        return instance;
    }
    /**
     * @brief Lấy kích thước của cơ sở dữ liệu.
     * @return Kích thước của cơ sở dữ liệu.
     * @details Hàm này trả về số lượng đối tượng trong cơ sở dữ liệu.
     */
    string getDataType() const override;

    /**
     * @brief Lấy dữ liệu từ cơ sở dữ liệu theo chỉ số.
     * @param index Chỉ số của đối tượng cần lấy.
     * @return Tham chiếu đến đối tượng trong cơ sở dữ liệu.
     * @details Hàm này trả về một tham chiếu đến đối tượng trong cơ sở dữ liệu theo chỉ số.
     */
    Faculty& getData(const int& index);

    /**
     * @brief Lấy kích thước của cơ sở dữ liệu.
     * @return Kích thước của cơ sở dữ liệu.
     * @details Hàm này trả về số lượng đối tượng trong cơ sở dữ liệu.
     */
    int find(const string& id) const;

    /**
     * @brief Tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh.
     * @param id Mã định danh của đối tượng cần tìm.
     * @return Chỉ số của đối tượng trong cơ sở dữ liệu, hoặc -1 nếu không tìm thấy.
     * @details Hàm này tìm kiếm một đối tượng trong cơ sở dữ liệu theo mã định danh và trả về chỉ số của nó.
     */
    void Add(const Faculty& obj);

    /**
     * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
     * @param ID Mã định danh của đối tượng cần xóa.
     * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
     * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
     */
    bool Remove(const string& ID);

    /**
     * @brief Xóa một đối tượng khỏi cơ sở dữ liệu.
     * @param obj Đối tượng cần xóa khỏi cơ sở dữ liệu.
     * @return true nếu xóa thành công, false nếu không tìm thấy đối tượng.
     * @details Hàm này xóa một đối tượng khỏi cơ sở dữ liệu.
     */
    bool Remove(Faculty& obj);

    /**
     * @brief Thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
     * @param des Đối tượng cần thay thế.
     * @param src Đối tượng mới thay thế.
     * @return true nếu thay thế thành công, false nếu không tìm thấy đối tượng cần thay thế.
     * @details Hàm này thay thế một đối tượng trong cơ sở dữ liệu bằng một đối tượng khác.
     */
    bool Replace(Faculty& des, Faculty& src);
    
    friend class FacultyReadData;
    friend class FacultyDatabaseDisplay;
};


/**
 * @class StudentGetData
 * @brief Lớp nhập dữ liệu cho sinh viên.
 * @details Lớp này cung cấp các phương thức để nhập dữ liệu cho sinh viên từ bàn phím.
 */
class StudentGetData{
    public:
        /**
         * @brief Nhập dữ liệu cho sinh viên từ bàn phím.
         * @param student Đối tượng sinh viên cần nhập dữ liệu.
         * @details Hàm này yêu cầu người dùng nhập thông tin cho sinh viên và lưu vào đối tượng sinh viên.
         */
        static void InputData(Student& student);
    };

/**
 * @class LecturerGetData
 * @brief Lớp nhập dữ liệu cho giảng viên.
 * @details Lớp này cung cấp các phương thức để nhập dữ liệu cho giảng viên từ bàn phím.
 */
class LecturerGetData{
    public:
        /**
         * @brief Nhập dữ liệu cho giảng viên từ bàn phím.
         * @param lecturer Đối tượng giảng viên cần nhập dữ liệu.
         * @details Hàm này yêu cầu người dùng nhập thông tin cho giảng viên và lưu vào đối tượng giảng viên.
         */
        static void InputData(Lecturer& lecturer);
    };

/**
 * @class FacultyGetData
 * @brief Lớp nhập dữ liệu cho khoa.
 * @details Lớp này cung cấp các phương thức để nhập dữ liệu cho khoa từ bàn phím.
 */
class FacultyGetData{
    public:
        /**
         * @brief Nhập dữ liệu cho khoa từ bàn phím.
         * @param faculty Đối tượng khoa cần nhập dữ liệu.
         * @details Hàm này yêu cầu người dùng nhập thông tin cho khoa và lưu vào đối tượng khoa.
         */
        static void InputData(Faculty& faculty);
};    

#endif // _DATA_H_
/**
 * @brief Kết thúc tệp data.h
 * @details Tệp này chứa các lớp cơ sở dữ liệu cho sinh viên, giảng viên và khoa,
 * cũng như các lớp nhập dữ liệu từ bàn phím.
 */