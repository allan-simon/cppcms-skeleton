#include <iostream>

#include "models/Users.h" 
#include "results/Users.h" 
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

    public:
        Test() : cppcmsskel::models::Users(TEST_PATH TEST_NAME ".db") {

        }

        bool test_work() {
            const int userId = add(
                adminName,
                adminPassword,
                adminEmail,
                cppcmsskel::results::User::Permission::admin
            );

            cppcmsskel::results::User user = by_id(userId);
            return user.exists() &&
                user.id == userId &&
                user.name == adminName &&
                user.permission == cppcmsskel::results::User::Permission::admin;
        }

        bool test_not_work() {
            cppcmsskel::results::User user = by_id(42);
            return user.exists();
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
        "Try to check if we can retrieve whole user by its id ... " ,
        model.test_work(),
        nothingFailed
    );

    CPPCMSSKEL_TEST_RESULT_NOT_WORK(
        "Try to check if retreiving a user with a non existing id give a non existing user ... " ,
        model.test_not_work(),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
