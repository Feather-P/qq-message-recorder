#include "models/DataAccessModule/DataAccessModule.hpp"
#include <string>

int main(){

    const std::string URIdatabaseName = "file:database/qq-message-recorder.db";
    const std::string databaseName = "database/qq-message-recorder.db";

    if (!QMR::isFileExist(databaseName)) {
        QMR::Dao Dao(URIdatabaseName);
        Dao.InitializeTables();
    }
    else {
        QMR::Dao Dao(URIdatabaseName);
    }
    /*Initialize the DataAccessObject, if it is brand new one, create tables*/
    
}