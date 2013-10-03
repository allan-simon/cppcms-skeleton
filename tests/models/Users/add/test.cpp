#include <iostream>

#include "models/Users.h" 
#include "generics/test.h"

#define TEST_NAME "test"
#define SQL_PATH "../"
#define BASIC_SQL "basic.sql"
#define TEST_PATH "tests/models/Users/add/"

//TODO copy paste of "is_admin.cpp"

class Test : public cppcmsskel::models::Users {

    private:
        const std::string newName = "new user";
        const std::string newEmail = "new@example.com";
        const std::string password = "newpassword";

        const std::string alreadyTakenName = "old user";
        const std::string alreadyTakenEmail = "old@example.com";

        // 
        bool test_add_new_user(
            const std::string &name,
            const std::string &email
        ) {


            int userId = add(
                name,
                password,
                email
            );

            return test_user_created(
                userId,
                name,
                email,
                password
            );
        }
        // performs various test that should fail if the user
        // does not exist, and will success if the success if the
        // user has been correctly added
        bool test_user_created(
            const int userId,
            const std::string &name,
            const std::string &email,
            const std::string &newPassword
        ) {
            if (userId == USERS_NOT_ADDED_ERROR) {
                std::cout << "not added" << std::endl;
                return false;
            }
            if (!username_exists(name)) {
                std::cout << "no name" << std::endl;
                return false;
            }

            if (!email_exists(email)) {

                std::cout << "no email" << std::endl;
                return false;
            }

            if (!username_exists(name)) {
                std::cout << "no name" << std::endl;
                return false;
            }

            if (!is_login_correct(name, newPassword)) {
                std::cout << "login wrong" << std::endl;
                return false;
            }

            return true;
        }
    public:
        Test() : cppcmsskel::models::Users(TEST_PATH TEST_NAME ".db") {

        }

        bool test_add_real_new_user() {
            return test_add_new_user(
                newName,
                newEmail
            );
        }

        bool test_email_taken() {
            return test_add_new_user(
                newName,
                alreadyTakenEmail
            );
        }

        bool test_username_taken() {
            return test_add_new_user(
                alreadyTakenName,
                newEmail
            );
        }

        bool test_username_email_taken() {
            return test_add_new_user(
                alreadyTakenName,
                alreadyTakenEmail
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
        "if brand new user => true ... " ,
        model.test_add_real_new_user(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If email already taken => false ... " ,
        model.test_email_taken(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If username is already used => false ... " ,
        model.test_username_taken(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If both username and email are taken => false ... " ,
        model.test_username_email_taken(),
        nothingFailed
    );



    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
