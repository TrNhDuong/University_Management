/**
 * @file search.h
 * @brief Tìm kiếm các thực thể trong cơ sở dữ liệu
 * @details Các lớp trong tệp này định nghĩa các chiến lược tìm kiếm khác nhau cho các thực thể trong cơ sở dữ liệu.
 * @note Bao gồm các lớp IdSearch và NameSearch để tìm kiếm theo ID và tên.
 * @note Lớp SearchStrategy là lớp trừu tượng cơ sở cho các chiến lược tìm kiếm.
 * @note Các lớp này sử dụng cơ sở dữ liệu IDatabase để thực hiện các thao tác tìm kiếm.
 * @note Các lớp này trả về một vector chứa các con trỏ đến các thực thể BaseEntity phù hợp với tiêu chí tìm kiếm.
 */
#ifndef SEARCH_H
#define SEARCH_H
#include "../Entity/baseEntity.h"
#include "../data.h"
#include <vector>
#include <memory>
#include <string>
using std::vector;
using std::string;

/**
 * @class SearchStrategy
 * @brief Lớp trừu tượng đại diện cho chiến lược tìm kiếm
 * @details Các lớp con sẽ triển khai phương thức search để thực hiện các thao tác tìm kiếm trên cơ sở dữ liệu.
 * @note Các lớp con bao gồm IdSearch và NameSearch.
 */
class SearchStrategy{
public:
    SearchStrategy() = default;
    virtual ~SearchStrategy() = default;

    virtual vector<BaseEntity*> search(IDatabase* database, const string& keySearch) = 0;
};

/**
 * @class IdSearch
 * @brief Lớp đại diện cho chiến lược tìm kiếm theo ID
 * @details Lớp này kế thừa từ SearchStrategy và triển khai phương thức search để tìm kiếm các thực thể theo ID trong cơ sở dữ liệu.
 */
class IdSearch: public SearchStrategy{
public:
    IdSearch() = default;
    ~IdSearch() = default;
    vector<BaseEntity*> search(IDatabase* database, const string& id) override;
};

/**
 * @class NameSearch
 * @brief Lớp đại diện cho chiến lược tìm kiếm theo tên
 * @details Lớp này kế thừa từ SearchStrategy và triển khai phương thức search để tìm kiếm các thực thể theo tên trong cơ sở dữ liệu.
 */
class NameSearch: public SearchStrategy{
public:
    NameSearch() = default;
    ~NameSearch() = default;
    vector<BaseEntity*> search(IDatabase* database, const string& name) override;
};

#endif