#include <iostream>

#include "models/Users.h" 
#include "generics/test.h"

#define TEST_NAME "test"
#define SQL_PATH "../"
#define BASIC_SQL "basic.sql"
#define TEST_PATH "tests/models/Users/is_admin/"

class Test : public cppcmsskel::models::Users {
    private:
        const std::string adminName = "admin";
        const std::string adminEmail = "admin@example.com";
        const std::string adminPassword = "adminpassword";

        const std::string normalName = "normal";
        const std::string normalEmail = "normal@example.com";
        const std::string normalPassword = "normalpassword";
    public:
        Test() : cppcmsskel::models::Users(TEST_PATH TEST_NAME ".db") {

        }

        bool test_work() {
            const int userId = add(
                adminName,
                adminPassword,
                adminEmail,
                cppcmsskel::models::Users::Type::admin
            );

            return is_admin(userId);
        }

        bool test_not_work() {
            const int userId = add(
                normalName,
                normalPassword,
                normalEmail,
                cppcmsskel::models::Users::Type::normal
            );

            return is_admin(userId);
        }
};


int main() {

    bool nothingFailed = true;
    Test model;

    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to create the tables ... " ,
        model.import_sql_file(
          SQL_PATH TEST_PATH BASIC_SQL
        ),
        nothingFailed
    );


    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to check if we know that the admin is admin ... " ,
        model.test_work(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "Try to check if we know an normal user is not admin ... " ,
        model.test_not_work(),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
