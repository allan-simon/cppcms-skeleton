#include <iostream>

#include "models/Users.h" 
#include "generics/test.h"

#define TEST_NAME "test"
#define SQL_PATH "../"
#define BASIC_SQL "basic.sql"
#define TEST_PATH "tests/models/Users/email_exists/"

//TODO copy paste of "is_admin.cpp"

class Test : public cppcmsskel::models::Users {
    public:
        Test() : cppcmsskel::models::Users(TEST_PATH TEST_NAME ".db") {

        }

        bool test_work() {
            return email_exists("username.exists@example.com");
        }

        bool test_not_work() {
            return email_exists("usename.not.exist@example.com");
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
        "If an email is already present 'email exists' => true ... " ,
        model.test_work(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If an email is not present 'email exists' => false ... " ,
        model.test_not_work(),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
