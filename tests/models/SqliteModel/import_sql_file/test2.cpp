#include <iostream>

#include "models/SqliteModel.h" 
#include "generics/test.h"

#define SQL_PATH "../tests/models/SqliteModel/import_sql_file/" 
#define TEST_NAME "test"
#define BUG_INSERT_SQL "bug_insert.sql"
#define BUG_INSERT_CREATE_TABLES_SQL "bug_insert_create_tables.sql"

int main() {

    // the goal here is to test the following case
    // 
    // an import containing INSERT fails with a unique constraint
    // errors though the table is empty and the import works 
    // when done directly (i.e using  sqlite3 my.db < the_file.sql
    bool nothingFailed = true;

    cppcmsskel::models::SqliteModel model(TEST_NAME "_" "test2.db");

    // we first create the database
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to create the tables ... " ,
        model.import_sql_file(
          SQL_PATH BUG_INSERT_CREATE_TABLES_SQL
        ),
        nothingFailed
    );

    // and we load the data
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Now we inset some data",
        model.import_sql_file(
          SQL_PATH BUG_INSERT_SQL
        ),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
