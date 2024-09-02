#include "models/DataAccessModule/DataAccessModule.hpp"
#include <string>

int main(){
    
    const std::string databaseName = "testdb.db";

    QMR::Dao Dao(databaseName);
}