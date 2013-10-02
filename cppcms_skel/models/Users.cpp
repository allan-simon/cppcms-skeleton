/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <cppdb/frontend.h>
#include <cppcms/util.h>
#include <cppcms/crypto.h>
#include <booster/posix_time.h>
#include <booster/log.h>


#include "models/Users.h"

#define SALT_SIZE 6

using namespace cppcms::crypto;

namespace cppcmsskel {
namespace models {

/**
 *
 */
Users::Users() :
    SqliteModel()
{
}

/**
 *
 */
Users::Users(const std::string &databasePath):
    SqliteModel(databasePath)
{
}



/**
 *
 */
bool Users::is_login_correct(
    const std::string &login,
    const std::string &pass
) {
    
    cppdb::statement checkPasswd = sqliteDb.prepare(
        "SELECT 1 FROM users "
        "WHERE username = ? AND password = ? LIMIT 1"
    );
    const std::string passHashed = hash_password(pass);
    checkPasswd.bind(login);
    checkPasswd.bind(passHashed);
    return check_existence(checkPasswd);
}


/**
 * 
 */
bool Users::username_exists(
    const std::string &username
) {
    cppdb::statement usernameExists = sqliteDb.prepare(
        "SELECT 1 FROM users "
        "WHERE username = ? "
    );
    usernameExists.bind(username);
    return check_existence(usernameExists);
}

/**
 * 
 */
bool Users::email_exists(
    const std::string &email
) {
    cppdb::statement emailExists = sqliteDb.prepare(
        "SELECT 1 FROM users "
        "WHERE email = ? "
    );
    emailExists.bind(email);
    return check_existence(emailExists);

}


/**
 *
 */
int Users::add(
    const std::string &login,
    const std::string &pass,
    const std::string &email
) {       

    
    cppdb::statement addUser = sqliteDb.prepare(
        "INSERT INTO users(username, password, email, since) "
        "VALUES(?,?,?,?)"
    );


    const std::string passHashed = hash_password(pass);
    addUser.bind(login);
    addUser.bind(passHashed);
    addUser.bind(email);
    addUser.bind(
        booster::ptime::now().get_seconds()
    );
          
    if (!execute_simple(addUser)) {
        return USERS_NOT_ADDED_ERROR;
    }
    int userId = static_cast<int>(addUser.last_insert_id());
    return userId;
}     

/**
 *
 */
bool Users::change_password(
    const std::string &login,
    const std::string &newPassword
) {
    cppdb::statement request = sqliteDb.prepare(
        "UPDATE users "
        "SET "
        "   password = ?  "
        "WHERE username =  ?"
    );
    
    const std::string passHashed = hash_password(newPassword);
    request.bind(passHashed);
    request.bind(login);

    return execute_simple(request);


}

/**
 *
 */
bool Users::change_permission_level(
    const std::string &login,
    const int newPermissionLevel
) {
    cppdb::statement request = sqliteDb.prepare(
        "UPDATE users "
        "SET "
        " group_id = ?  "
        "WHERE username =  ?"
    );
    
    request.bind(newPermissionLevel);
    request.bind(login);

    return execute_simple(request);
}


/**
 *
 */
bool Users::admin_exists(void) {
    cppdb::statement adminExists = sqliteDb.prepare(
        "SELECT 1 FROM users "
        "WHERE group_id = ? "
    );
    adminExists.bind(USERS_ADMIN);
    return check_existence(adminExists);


}


/**
 *
 */
bool Users::is_admin(const int userId) {

    cppdb::statement isAdmin = sqliteDb.prepare(
        "SELECT 1 FROM users "
        "WHERE group_id = ? AND"
        "   user_id = ? "
    );
    isAdmin.bind(USERS_ADMIN);
    isAdmin.bind(userId);
    return check_existence(isAdmin);

}

/**
 *
 */
std::string Users::sha1hex(
    const std::string &in
) {
    using namespace cppcms::crypto;
    std::unique_ptr<message_digest> digest(message_digest::sha1());
    unsigned char buf[256];
    digest->append(in.c_str(),in.size());
    unsigned digestSize =digest->digest_size();
    digest->readout(buf);

    std::string res;
    for(unsigned i=0; i<digestSize ;i++) {
        char tmpBuf[3];
        sprintf(tmpBuf,"%02x",buf[i]);
        res+=tmpBuf;
    }
    return res;
}

/**
 *
 */
std::string Users::hash_password(
    const std::string &password
) {
    
    return sha1hex(password + get_salt());
}

/**
 *
 */
std::string Users::get_salt() {
    cppdb::statement getSalt = sqliteDb.prepare(
        "SELECT value FROM salt "
        "LIMIT 1 "
    );
    cppdb::result res = getSalt.row();
    std::string salt = "";
    res.fetch(0,salt);

    // Don't forget to reset statement
    getSalt.reset();

    if (salt != "" ) {
        return salt;
    }
    salt = random_string(SALT_SIZE);
    save_salt(salt);
    return salt;
}

/**
 *
 */
bool Users::save_salt(const std::string &salt) {
    cppdb::statement save = sqliteDb.prepare(
        "INSERT INTO salt(value)"
        "VALUES(?)"
    );
    save.bind(salt);
    return execute_simple(save);
}

/**
 *
 *
 */
std::string Users::random_string(
    const size_t length
) {
    srand(static_cast<unsigned>(time(NULL)));

    auto randchar = []() -> char {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t maxIndex = (sizeof(charset) - 1);
        return charset[ static_cast<unsigned>(rand()) % maxIndex ];
    };

    std::string randomString(length,0);
    std::generate_n( randomString.begin(), length, randchar );
    return randomString;
}


} // end namespace models
} // end namespace cppcmsskel


