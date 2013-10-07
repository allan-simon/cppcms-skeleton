#include <iostream>

#include "models/SqliteModel.h" 
#include "generics/test.h"

#define SQL_PATH "../" 
#define TEST_PATH "tests/models/SqliteModel/import_sql_file/"
#define TEST_NAME "works_with_trigger_block"
#define SQL_NAME "works_with_trigger_block.sql"

int main() {

    // the goal here is to test the following case
    // 
    // 
    //  a create trigger block contains several ";" but must be imported as
    //  one block, otherwise it will generate an error
    //  so we test that it's possible to import create trigger blocks without
    //  problem

    bool nothingFailed = true;

    cppcmsskel::models::SqliteModel model(TEST_NAME ".db");

    // we first create the database
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to create the tables ... " ,
        model.import_sql_file(
          SQL_PATH TEST_PATH SQL_NAME
        ),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
