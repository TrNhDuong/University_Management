/**
 * @file baseEntity.h
 * @brief Khai báo các lớp BaseEntity và Birth.
 */

 #ifndef _BASE_ENTITY_H_
 #define _BASE_ENTITY_H_
 
 #include <string>
 using std::string;
 using std::ostream;
 
 /**
  * @class Birth
  * @brief Đại diện cho ngày sinh.
  */
 class Birth {
 private:
     int _day; ///< Ngày sinh.
     int _month; ///< Tháng sinh.
     int _year; ///< Năm sinh.
 
 public:
     /**
      * @brief Hàm khởi tạo mặc định của lớp Birth.
      */
     Birth();
 
     /**
      * @brief Hàm hủy của lớp Birth.
      */
     ~Birth();
 
     /**
      * @brief Thiết lập ngày sinh bằng ngày, tháng, năm.
      * @param d Ngày sinh.
      * @param m Tháng sinh.
      * @param y Năm sinh.
      */
     void setBirth(const int& d, const int& m, const int& y);
 
     /**
      * @brief Thiết lập ngày sinh bằng chuỗi định dạng "dd/mm/yyyy".
      * @param str Chuỗi ngày sinh.
      */
     void setBirth(const string& str);
 
     /**
      * @brief Lấy ngày sinh.
      * @return Ngày sinh.
      */
     int getDay() const;
 
     /**
      * @brief Lấy tháng sinh.
      * @return Tháng sinh.
      */
     int getMonth() const;
 
     /**
      * @brief Lấy năm sinh.
      * @return Năm sinh.
      */
     int getYear() const;
 };
 
 /**
  * @class BaseEntity
  * @brief Đại diện cho một thực thể cơ bản với tên, mã định danh và ngày sinh.
  */
 class BaseEntity {
 protected:
     string _name; ///< Tên của thực thể.
     string _id; ///< Mã định danh của thực thể.
     Birth _birthDay; ///< Ngày sinh của thực thể.
 
 public:
     /**
      * @brief Lấy tên của thực thể.
      * @return Tên của thực thể.
      */
     string getName() const;
 
     /**
      * @brief Lấy mã định danh của thực thể.
      * @return Mã định danh của thực thể.
      */
     string getId() const;
 
     /**
      * @brief Lấy ngày sinh của thực thể.
      * @return Ngày sinh dưới dạng đối tượng Birth.
      */
     Birth getBirth() const;
 
     /**
      * @brief Thiết lập tên của thực thể.
      * @param name Tên cần thiết lập.
      */
     void setName(const string& name);
 
     /**
      * @brief Thiết lập mã định danh của thực thể.
      * @param id Mã định danh cần thiết lập.
      */
     void setId(const string& id);
 
     /**
      * @brief Thiết lập ngày sinh của thực thể bằng đối tượng Birth.
      * @param birthDay Đối tượng Birth đại diện cho ngày sinh.
      */
     void setBirth(const Birth& birthDay);
 
     /**
      * @brief Thiết lập ngày sinh của thực thể bằng chuỗi định dạng "dd/mm/yyyy".
      * @param str Chuỗi ngày sinh.
      */
     void setBirth(const string& str);
 
     /**
      * @brief Hàm khởi tạo mặc định của lớp BaseEntity.
      */
     BaseEntity();
 
     /**
      * @brief Hàm hủy của lớp BaseEntity.
      */
     virtual ~BaseEntity();
 };
 
 #endif // _BASE_ENTITY_H_