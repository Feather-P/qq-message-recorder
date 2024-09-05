#ifndef DATA_ACCESS_MODULE_HPP_
#define DATA_ACCESS_MODULE_HPP_

#include <sqlite3.h>
#include <string>

namespace QMR
{
bool isFileExist(const std::string & fileDir);

class BaseTableDefination
{
private:
    std::string tableName;

public:
    std::string getTableName() const;
    void setTableName(const std::string & expectedTableName);
};

class CreateTableDefination : public BaseTableDefination
{
private:
    std::string sql;

public:
    std::string getSql() const;
    void setSql(const std::string & expectedSql);
};

class Dao
{
private:
    sqlite3 * database;
    std::string dbObjectName;
public:
    explicit Dao(const std::string & dbName);
    ~Dao();
    void CreateTable(const CreateTableDefination & tableDefination);
    void InitializeTables();
};
} // namespace QMR

#endif