#include "DataAccessModule.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

namespace QMR
{
    /*BEGIN OF SOMETHING ABOUT TABLES*/
    std::string BaseTableDefination::getTableName() const
    {
        return tableName;
    }

    void BaseTableDefination::setTableName(const std::string & expectedTableName)
    {
        tableName = expectedTableName;
    }

    std::string CreateTableDefination::getSql() const
    {
        return sql;
    }

    void CreateTableDefination::setSql(const std::string & expectedSql)
    {
        sql = expectedSql;
    }
    /*END OF SOMETHING ABOUT TABLES*/

    /*BEGIN OF THE DEFINE OF DAO*/
    Dao::Dao(const std::string & dbName) : dbObjectName(dbName)
    {
        int configReturnCode = sqlite3_config(SQLITE_CONFIG_URI, 1);// Enable sqlite3 URI path feature

        int returnCode = sqlite3_open(dbObjectName.c_str(), &database);

        if (returnCode != 0){
           std::cerr << "Can't open a sqlite file, error message is: " << sqlite3_errmsg(database) << "\"\n";
           abort();
        }

        std::cout << "sqlite file opened successfully, which file name is: " << dbObjectName << "\"\n";
    }

    Dao::~Dao()
    {
        int returnCode = sqlite3_close(database);

        if (returnCode != SQLITE_OK){
           std::cerr << "Can't close a sqlite database, error message is: " << sqlite3_errmsg(database) << "\"\n";
           abort();
        }

        std::cout << "sqlite file closed successfully" ;
    }

    void Dao::CreateTable(const CreateTableDefination & tableDefination){

        char * errMsg = nullptr;
        std::string sql = tableDefination.getSql();

        int returnCode = 
        sqlite3_exec(
            database, 
            sql.c_str(), 
            nullptr, 
            nullptr, 
            &errMsg
        );
        
        if (returnCode != SQLITE_OK) {
            std::cerr << "Can't create " << tableDefination.getTableName() << " Table, error message is: " << errMsg << "\"\n";
            sqlite3_free(errMsg);
            sqlite3_close(database);
            abort();
        }
        else std::cout << "Created the " << tableDefination.getTableName() << " table successfully.\n";
    }

    void Dao::InitializeTables()
    {
        CreateTableDefination UsersTableDefinations;
        const std::string userTableName = "USERS";
        const std::string userCreateSql =
        "CREATE TABLE USERS(\
            ID       INT PRIMARY KEY NOT NULL,\
            QID      TEXT NOT NULL,\
            USERNAME TEXT NOT NULL,\
            REGTIME  INTEGER,\
            UPDTIME  INTEGER\
        );";
        UsersTableDefinations.setTableName(userTableName);
        UsersTableDefinations.setSql(userCreateSql);

        CreateTableDefination MessagesTableDefinations;
        const std::string messagesTableName = "MESSAGES";
        const std::string messagesCreateSql =
        "CREATE TABLE MESSAGES(\
            MID       INT PRIMARY KEY NOT NULL,\
            SENDERQID TEXT NOT NULL,\
            CATEGORY  TEXT,\
            CONTENT   BLOB\
        );";
        MessagesTableDefinations.setTableName(messagesTableName);
        MessagesTableDefinations.setSql(messagesCreateSql);

        CreateTable(UsersTableDefinations);
        CreateTable(MessagesTableDefinations);
    }
    /*END OF DEFINE OF DAO*/

}  // namespace QMR