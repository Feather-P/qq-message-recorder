#ifndef DATA_ACCESS_MODULE_HPP_
#define DATA_ACCESS_MODULE_HPP_

#include <sqlite3.h>
#include <string>

namespace QMR
{

class Dao
{
private:
    std::string dbObjectName;
    sqlite3 * database;
public:
    explicit Dao(const std::string & dbName);
    ~Dao();
};

} // namespace QMR

#endif