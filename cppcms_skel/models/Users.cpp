/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * @category cppcmsskel
 * @package  Models
 * @author   Allan SIMON <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/sysko/cppcms-skeleton
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
        "INSERT INTO users(username, password, email, since)"
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
    int userId = addUser.last_insert_id();
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
    srand(time(NULL));

    auto randchar = []() -> char {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t maxIndex = (sizeof(charset) - 1);
        return charset[ rand() % maxIndex ];
    };

    std::string randomString(length,0);
    std::generate_n( randomString.begin(), length, randchar );
    return randomString;
}


} // end namespace models
} // end namespace cppcmsskel


