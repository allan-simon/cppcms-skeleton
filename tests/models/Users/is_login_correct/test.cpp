#include <iostream>

#include "models/Users.h" 
#include "generics/test.h"

#define TEST_NAME "test"
#define SQL_PATH "../"
#define BASIC_SQL "basic.sql"
#define TEST_PATH "tests/models/Users/is_login_correct/"

//TODO copy paste of "is_admin.cpp"

class Test : public cppcmsskel::models::Users {
    public:
        Test() : cppcmsskel::models::Users(TEST_PATH TEST_NAME ".db") {

        }

        bool test_both_ok() {
            return is_login_correct(
                "username_which_exists",
                "password_correct"
            );
        }

        bool test_both_wrong() {
            return is_login_correct(
                "username_which_does_not_exist",
                "password_not_correct"
            );
        }

        bool test_only_username_ok() {
            return is_login_correct(
                "username_which_exists",
                "password_not_correct"
            );
        }

        bool test_only_password_ok() {
            return is_login_correct(
                "username_which_does_not_exist",
                "password_correct"
            );
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
        "if username AND password are correct => true ... " ,
        model.test_both_ok(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If both are not correct => false ... " ,
        model.test_both_wrong(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If only username is correct => false ... " ,
        model.test_only_username_ok(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If only password is correct => false ... " ,
        model.test_only_password_ok(),
        nothingFailed
    );






    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
