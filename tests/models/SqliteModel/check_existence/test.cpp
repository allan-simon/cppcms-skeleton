#include <iostream>

#include "models/SqliteModel.h" 
#include "generics/test.h"

#define TEST_NAME "test"
#define TEST_PATH "tests/models/SqliteModel/check_existence/"
#define BASIC_SQL "basic.sql"
#define SQL_PATH "../"

class TestModel : public cppcmsskel::models::SqliteModel {

    public:
        // constructor
        TestModel() : cppcmsskel::models::SqliteModel(TEST_PATH TEST_NAME ".db") {

        }
        
        // test
        bool test() {
            cppdb::statement existsRequest = sqliteDb.prepare(
                "SELECT 1 FROM users WHERE group_id = 1"
            ); 
            return check_existence(existsRequest); 
        }

        // test that should not work
        bool test_not_work() {
            cppdb::statement existsRequest = sqliteDb.prepare(
                "SELECT 1 FROM users WHERE group_id = 42"
            ); 
            return check_existence(existsRequest); 
        }


};

int main() {

    bool nothingFailed = true;
    TestModel model;

    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to create the tables ... " ,
        model.import_sql_file(
          SQL_PATH TEST_PATH BASIC_SQL
        ),
        nothingFailed
    );


    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to check the existence of an existing record ... " ,
        model.test(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "Try to check the existence of a non-existing record ... " ,
        model.test_not_work(),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
