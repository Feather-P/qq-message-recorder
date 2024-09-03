#include "models/DataAccessModule/DataAccessModule.hpp"
#include <string>

int main(){

    const std::string databaseName = "file:database/qq-message-recorder.db";

    QMR::Dao Dao(databaseName);
    Dao.CreateUsersTable();
}