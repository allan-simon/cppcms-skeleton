#include <iostream>

#include "models/Users.h" 
#include "generics/test.h"

#define TEST_NAME "test"
#define SQL_PATH "../"
#define BASIC_SQL "basic.sql"
#define TEST_PATH "tests/models/Users/username_exists/"

//TODO copy paste of "is_admin.cpp"

class Test : public cppcmsskel::models::Users {
    public:
        Test() : cppcmsskel::models::Users(TEST_PATH TEST_NAME ".db") {

        }

        bool test_work() {
            return username_exists("username_which_exists");
        }

        bool test_not_work() {
            return username_exists("username_which_does_not_exist");
        }
};
        

int main() {

    bool nothingFailed = true;
    Test model;

    std::cout << SQL_PATH TEST_PATH BASIC_SQL << std::endl;
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to create the tables ... " ,
        model.import_sql_file(
          SQL_PATH TEST_PATH BASIC_SQL
        ),
        nothingFailed
    );


    CPPCMSSKEL_TEST_RESULT_WORK(
        "If a username is already present 'username exists' => true ... " ,
        model.test_work(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If a username is not present 'username exists' => false ... " ,
        model.test_not_work(),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
