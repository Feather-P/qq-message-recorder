#include <iostream>
#include <sqlite3.h>

int main(){
    sqlite3 * database {};
    int returnCode {};

    returnCode = sqlite3_open("testdb.db", &database);

    if (returnCode != 0){
        std::cerr << "Can't open a sqlite file, error message is: " << sqlite3_errmsg(database) << std::endl;
        return 1;
    }
    std::cout << "sqlite file opened successfully.\n";

    sqlite3_close(database);

    return 0;
}