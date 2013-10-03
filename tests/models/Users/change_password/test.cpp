#include <iostream>

#include "models/Users.h" 
#include "generics/test.h"

#define TEST_NAME "test"
#define SQL_PATH "../"
#define BASIC_SQL "basic.sql"
#define TEST_PATH "tests/models/Users/change_password/"

//TODO copy paste of "is_admin.cpp"

class Test : public cppcmsskel::models::Users {

    private:
        const std::string newName = "user";
        const std::string newEmail = "user@example.com";
        const std::string oldPassword = "password";



        const std::string newPassword = "newpassword";
        // 
        bool test_add_new_user(
            const std::string &name,
            const std::string &email
        ) {


            int userId = add(
                name,
                oldPassword,
                email
            );

            return test_user_created(
                userId,
                name,
                email,
                oldPassword
            );
        }
        // performs various test that should fail if the user
        // does not exist, and will success if the success if the
        // user has been correctly added
        bool test_user_created(
            const int userId,
            const std::string &name,
            const std::string &email,
            const std::string &password
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

            if (!is_login_correct(name, password)) {
                std::cout << "login wrong" << std::endl;
                return false;
            }

            return true;
        }
    public:
        Test() : cppcmsskel::models::Users(TEST_PATH TEST_NAME ".db") {

        }

        bool test_change_password() {
            return change_password(
                newName,
                newPassword
            );
        }

        bool test_can_login_with_new_password() {
            return is_login_correct(
                newName,
                newPassword
            );
        }

        bool test_cant_login_with_previous_password() {
            return is_login_correct(
                newName,
                oldPassword
            );
        }



        bool test_add_real_new_user() {
            return test_add_new_user(
                newName,
                newEmail
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
        "we should be able to add a new user => true ... " ,
        model.test_add_real_new_user(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_WORK(
        "If we change the password normaly => true ... " ,
        model.test_change_password(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_WORK(
        "If we try to log with new password => true ... " ,
        model.test_can_login_with_new_password(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "If we try to log with old password => false ... " ,
        model.test_cant_login_with_previous_password(),
        nothingFailed
    );



    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
