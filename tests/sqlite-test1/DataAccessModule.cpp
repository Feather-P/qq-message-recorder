#include "DataAccessModule.hpp"
#include <cstdlib>
#include <iostream>

namespace QMR
{

    Dao::Dao(std::string & dbPath)
    {
        dbObjectPath = dbPath;
        int returnCode {};
        returnCode = sqlite3_open(dbObjectPath.c_str(), &database);

        if (returnCode != 0){
           std::cerr << "Can't open a sqlite file, error message is: " << sqlite3_errmsg(database) << std::endl;
           abort();
        }

        std::cout << "sqlite file opened successfully, which path is: " << dbObjectPath <<std::endl;
    }

    Dao::~Dao()
    {
        int returnCode {};
        returnCode = sqlite3_close(database);

        if (returnCode != 0){
           std::cerr << "Can't close a sqlite database, error message is: " << sqlite3_errmsg(database) << std::endl;
           abort();
        }

        std::cout << "sqlite file closed successfully" ;
    }
}  // namespace QMR