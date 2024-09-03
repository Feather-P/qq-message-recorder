#include "DataAccessModule.hpp"
#include <cstdlib>
#include <iostream>

namespace QMR
{

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

    void Dao::CreateUsersTable()
    {
        std::string sql =
        "CREATE TABLE USERS(\
            ID       INT PRIMARY KEY NOT NULL,\
            QID      TEXT NOT NULL,\
            USERNAME TEXT NOT NULL,\
            REGTIME  INTEGER,\
            UPDTIME  INTEGER\
        );";

        char * errMsg = nullptr;

        int returnCode = 
        sqlite3_exec(
            database, 
            sql.c_str(), 
            nullptr, 
            nullptr, 
            &errMsg
        );
        
        if (returnCode != SQLITE_OK) {
            std::cerr << "Can't create users table, error message is: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            sqlite3_close(database);
            abort();
        }
        else std::cout << "Created the users table successfully.\n";
    }
}  // namespace QMR