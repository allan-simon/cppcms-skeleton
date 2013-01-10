#include <iostream>

#include "models/SqliteModel.h" 
#include "test.h"

#define OK "[OK]"
#define FAIL "[FAILED]"

#define SQL_PATH "../tests/" 
#define TEST_NAME "models_sqlitemodel_import_sql_file_test"

int main() {

    bool nothingFailed = true;

    models::SqliteModel model("test.db");
    // if we provide a correct file everything must
    // run smoothly 
    std::cout << "Try to load a correct SQL file ... " ;
    int result = model.import_sql_file(
        SQL_PATH TEST_NAME  "_correct.sql"
    );
    // TODO maybe add things to check that not only
    // it has generated no exception but also that
    // the SQL code has actually been executed
    CPPCMSSKEL_TEST(result == 1);

    // if we provide a file containing a mistake we should
    // return an error
    std::cout << "Try to load a erroneous SQL file ... " ;
    result = model.import_sql_file(
        SQL_PATH  TEST_NAME  "_not_correct.sql"
    );
    CPPCMSSKEL_TEST(result == 0);

    //
    std::cout << "Check that the file has been correctly imported ... ";
    result = model.import_sql_file(
        SQL_PATH TEST_NAME "_correct_data.sql"
    );
    CPPCMSSKEL_TEST(result == 1);

    // if the file does not exists we should not crash
    //std::cout << "Try to load an non existing SQL file ... " ;
    //result = model.import_sql_file(
    //    SQL_PATH TEST_NAME "_doesnt_exist.sql"
    //);
    //if (result == 2) {
    //    std::cout << FAIL << std::endl;
    //} else {
    //    std::cout << OK << std::endl;
    //}
    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
