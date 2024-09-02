#ifndef DATA_ACCESS_MODULE_HPP_
#define DATA_ACCESS_MODULE_HPP_

#include <sqlite3.h>
#include <string>

namespace QMR
{

class Dao
{
private:
    std::string dbObjectPath;

    sqlite3 * database;
public:
    explicit Dao(std::string & dbPath);
    ~Dao();
};

} // namespace QMR

#endif