#include <iostream>

#include "models/SqliteModel.h" 
#include "test.h"

#define OK "[OK]"
#define FAIL "[FAILED]"

#define SQL_PATH "../tests/" 
#define TEST_NAME "models_sqlitemodel_import_sql_file_test"
#define BUG_TRANSACTION_SQL "bug_transaction.sql"
int main() {

    bool nothingFailed = true;

    models::SqliteModel model("test.db");
    // if we provide a correct file everything must
    // run smoothly 
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to load a correct SQL file ... " ,
        model.import_sql_file(
            SQL_PATH TEST_NAME  "_correct.sql"
        ),
        nothingFailed
    );
    // TODO maybe add things to check that not only
    // it has generated no exception but also that
    // the SQL code has actually been executed

    // if we provide a file containing a mistake we should
    // return an error
    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "Try to load a erroneous SQL file ... ",
        model.import_sql_file(
            SQL_PATH  TEST_NAME  "_not_correct.sql"
        ),
        nothingFailed
    );

    //
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Check that the file has been correctly imported ... ",
        model.import_sql_file(
            SQL_PATH TEST_NAME "_correct_data.sql"
        ),
        nothingFailed
    );

    //
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Check that problem with transaction is fixed ... ",
        model.import_sql_file(
            SQL_PATH BUG_TRANSACTION_SQL
        ),
        nothingFailed
    );



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
