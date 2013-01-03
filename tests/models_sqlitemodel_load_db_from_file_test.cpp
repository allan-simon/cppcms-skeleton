#include <iostream>

#include "models/SqliteModel.h" 

#define OK "[OK]"
#define FAIL "[FAILED]"

#define SQL_PATH "../tests/" 
#define TEST_NAME "models_sqlitemodel_load_db_from_file_test"

int main() {

    models::SqliteModel model("test.db");
    // if we provide a correct file everything must
    // run smoothly 
    std::cout << "Try to load a correct SQL file ... " ;
    int result = model.load_db_from_file(
        SQL_PATH TEST_NAME  "_correct.sql"
    );
    // TODO maybe add things to check that not only
    // it has generated no exception but also that
    // the SQL code has actually been executed
    if (result == 1) {
        std::cout << FAIL << std::endl;
    } else {
        std::cout << OK << std::endl;
    }

    // if we provide a file containing a mistake we should
    // return an error
    std::cout << "Try to load a erroneous SQL file ... " ;
    result = model.load_db_from_file(
        SQL_PATH  TEST_NAME  "_not_correct.sql"
    );
    if (result == 0) {
        std::cout << FAIL << std::endl;
    } else {
        std::cout << OK << std::endl;
    }



    return 0;
}
