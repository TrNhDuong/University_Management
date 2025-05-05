/**
 * @file readData.h
 * @brief Khai báo các lớp đọc dữ liệu từ file.
 * @details Các lớp này sử dụng Singleton design pattern để đảm bảo chỉ có một thể hiện duy nhất của mỗi lớp.
 */

#ifndef _READDATA_H
#define _READDATA_H
#include"data.h"
#include<string> 
#include<sstream>
#include<fstream>

using std::ifstream, std::ofstream;
using std::string, std::stringstream;


/**
 * @class IReadData
 * @brief Interface cho các lớp đọc dữ liệu từ file.
 * @details Interface này định nghĩa phương thức readData để đọc dữ liệu từ file.
 */
class IReadData{
public:
    virtual ~IReadData() = default;
};

/**
 * @class FacultyReadData
 * @brief Lớp đọc dữ liệu từ file cho Faculty.
 * @details Lớp này sử dụng Singleton design pattern để đảm bảo chỉ có một thể hiện duy nhất của lớp.
 */
class FacultyReadData: public IReadData {
private:
    /**
     * @brief Hàm khởi tạo mặc định cho lớp FacultyReadData.
     * @details Hàm này khởi tạo các thuộc tính của lớp FacultyReadData với giá trị mặc định.
     */
    FacultyReadData() = default; 

    /**
     * @brief Hàm sao chép và gán cho lớp FacultyReadData.
     * @details Hàm này bị xóa để đảm bảo rằng không thể sao chép hoặc gán cho lớp FacultyReadData.
     */
    FacultyReadData(const FacultyReadData&) = delete;

    /**
     * @brief Hàm gán cho lớp FacultyReadData.
     * @details Hàm này bị xóa để đảm bảo rằng không thể sao chép hoặc gán cho lớp FacultyReadData.
     */
    FacultyReadData& operator= (const FacultyReadData&) = delete; 

    /**
     * @brief Hàm hủy cho lớp FacultyReadData.
     * @details Hàm này được gọi khi đối tượng FacultyReadData bị hủy.
     */
    ~FacultyReadData() = default;

    /**
     * @brief Đối tượng ifstream để đọc dữ liệu từ file.
     * @details Đối tượng này được sử dụng để mở và đọc dữ liệu từ file.
     */
    ifstream _fileIn; //There is a possibility that programm read multiple of files, so i wont create a class to singleton the ifstream. 
public:

    /**
     * @brief Hàm lấy thể hiện duy nhất của lớp FacultyReadData.
     * @details Hàm này sử dụng Singleton design pattern để đảm bảo chỉ có một thể hiện duy nhất của lớp FacultyReadData.
     * @return Thể hiện duy nhất của lớp FacultyReadData.
     */
    static FacultyReadData& getInstance(){
        /**
         * @brief Thể hiện duy nhất của lớp FacultyReadData.
         * @details Thể hiện này được sử dụng để đảm bảo chỉ có một thể hiện duy nhất của lớp FacultyReadData.
         */
        static FacultyReadData instance;
        return instance;
    };

    /**
     * @brief Hàm đọc dữ liệu từ file.
     * @details Hàm này đọc dữ liệu từ file và lưu vào cơ sở dữ liệu.
     * @param filename Tên file cần đọc dữ liệu.
     */
    void readData(const string& filename);
};

/**
 * @class LecturerReadData
 * @brief Lớp đọc dữ liệu từ file cho Lecturer.
 * @details Lớp này sử dụng Singleton design pattern để đảm bảo chỉ có một thể hiện duy nhất của lớp.
 */
class LecturerReadData : public IReadData{
private:
    /**
     * @brief Hàm khởi tạo mặc định cho lớp LecturerReadData.
     * @details Hàm này khởi tạo các thuộc tính của lớp LecturerReadData với giá trị mặc định.
     */
    LecturerReadData() = default;

    /**
     * @brief Hàm sao chép và gán cho lớp LecturerReadData.
     * @details Hàm này bị xóa để đảm bảo rằng không thể sao chép hoặc gán cho lớp LecturerReadData.
     */
    LecturerReadData(const LecturerReadData&) = delete;

    /**
     * @brief Hàm gán cho lớp LecturerReadData.
     * @details Hàm này bị xóa để đảm bảo rằng không thể sao chép hoặc gán cho lớp LecturerReadData.
     */
    LecturerReadData& operator= (const LecturerReadData&) = delete;
    
    /**
     * @brief Hàm hủy cho lớp LecturerReadData.
     * @details Hàm này được gọi khi đối tượng LecturerReadData bị hủy.
     */
    ~LecturerReadData() = default;

    /**
     * @brief Đối tượng ifstream để đọc dữ liệu từ file.
     * @details Đối tượng này được sử dụng để mở và đọc dữ liệu từ file.
     */
    ifstream _fileIn;
public:
    /**
     * @brief Hàm lấy thể hiện duy nhất của lớp LecturerReadData.
     * @details Hàm này sử dụng Singleton design pattern để đảm bảo chỉ có một thể hiện duy nhất của lớp LecturerReadData.
     * @return Thể hiện duy nhất của lớp LecturerReadData.
     */
    static LecturerReadData& getInstance(){
        /**
         * @brief Thể hiện duy nhất của lớp LecturerReadData.
         * @details Thể hiện này được sử dụng để đảm bảo chỉ có một thể hiện duy nhất của lớp LecturerReadData.
         */
        static LecturerReadData instance;
        return instance;
    };

    /**
     * @brief Hàm đọc dữ liệu từ file.
     * @details Hàm này đọc dữ liệu từ file và lưu vào cơ sở dữ liệu.
     * @param filename Tên file cần đọc dữ liệu.
     */
    void readData(const string& filename); 
};

/**
 * @class StudentReadData
 * @brief Lớp đọc dữ liệu từ file cho Student.
 * @details Lớp này sử dụng Singleton design pattern để đảm bảo chỉ có một thể hiện duy nhất của lớp.
 */
class StudentReadData : public IReadData {
private:
    /**
     * @brief Hàm khởi tạo mặc định cho lớp StudentReadData.
     * @details Hàm này khởi tạo các thuộc tính của lớp StudentReadData với giá trị mặc định.
     */
    StudentReadData() = default;

    /**
     * @brief Hàm sao chép và gán cho lớp StudentReadData.
     * @details Hàm này bị xóa để đảm bảo rằng không thể sao chép hoặc gán cho lớp StudentReadData.
     */
    StudentReadData(const StudentReadData&) = delete;

    /**
     * @brief Hàm gán cho lớp StudentReadData.
     * @details Hàm này bị xóa để đảm bảo rằng không thể sao chép hoặc gán cho lớp StudentReadData.
     */
    StudentReadData& operator= (const StudentReadData&) = delete;

    /**
     * @brief Hàm hủy cho lớp StudentReadData.
     * @details Hàm này được gọi khi đối tượng StudentReadData bị hủy.
     */
    ~StudentReadData() = default;

    /**
     * @brief Đối tượng ifstream để đọc dữ liệu từ file.
     * @details Đối tượng này được sử dụng để mở và đọc dữ liệu từ file.
     */
    ifstream _fileIn;
public:
    /**
     * @brief Hàm lấy thể hiện duy nhất của lớp StudentReadData.
     * @details Hàm này sử dụng Singleton design pattern để đảm bảo chỉ có một thể hiện duy nhất của lớp StudentReadData.
     * @return Thể hiện duy nhất của lớp StudentReadData.
     */
    static StudentReadData& getInstance(){
        /**
         * @brief Thể hiện duy nhất của lớp StudentReadData.
         * @details Thể hiện này được sử dụng để đảm bảo chỉ có một thể hiện duy nhất của lớp StudentReadData.
         */
        static StudentReadData instance;
        return instance;
    };
    /**
     * @brief Hàm đọc dữ liệu từ file.
     * @details Hàm này đọc dữ liệu từ file và lưu vào cơ sở dữ liệu.
     * @param filename Tên file cần đọc dữ liệu.
     */
    void readData(const string& filename);
};
#endif