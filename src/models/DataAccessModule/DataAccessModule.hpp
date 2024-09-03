#ifndef DATA_ACCESS_MODULE_HPP_
#define DATA_ACCESS_MODULE_HPP_

#include <sqlite3.h>
#include <string>

namespace QMR
{

class Dao
{
private:
    sqlite3 * database;
    std::string dbObjectName;
public:
    explicit Dao(const std::string & dbName);
    ~Dao();
    void CreateUsersTable();
};

} // namespace QMR

#endif