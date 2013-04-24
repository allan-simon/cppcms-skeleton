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
 * @category Tatoeba wiki
 * @package  Models
 * @author   Allan SIMON <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/sysko/tatowiki@
 */

#ifndef CPPCMS_SKEL_USERS
#define CPPCMS_SKEL_USERS



#include "SqliteModel.h"

#define USERS_NOT_ADDED_ERROR -1

namespace cppcmsskel {
namespace models {


/**
 * @class Users
 * 
 * @brief @TODO
 * @since 30 October 2012       
 *
 */
class Users : public SqliteModel {
    private:
    
        /**
         * @brief Hash a string using sha1
         *
         * @param in The string to hash
         *
         * @return A string representing the hexadecimal value of the hash
         *
         * @since 17 March 2013
         */
        std::string sha1hex(
            const std::string &in
        );
        
        /**
         * @brief Hash a password (currently use sha1 + salt) 
         *
         * @param password The password to hash
         *
         * @return The hexadecimal string of the hash 
         *
         * @since 17 March 2013
         */
        std::string hash_password(
            const std::string &password
        );
         
        /**
         * @brief Get the salt used for the hash functions
         *
         * @return The string representation of the hash 
         *
         * @since 17 March 2013
         */
        std::string get_salt();
        
        /**
         * @brief Save a new salt used for the hash functions
         *
         * @param salt The salt to save
         *
         * @return True if everything went smoothly, false otherwise
         *
         * @since 17 March 2013
         */
        bool save_salt(const std::string &salt);

        /**
         * @brief Generate a random string of a given size
         *
         * @param length How long the string will be
         *
         * @return A random string
         *
         * @since 17 March 2013
         */
        std::string random_string(const size_t length);

    public:
        /**
         * @brief Constructor
         * @since 30 October 2012
         */
        Users();

        /**
         * @brief Return the id of the user having the given name
         *
         * @param string username User's name of whom we want the id
         *
         * @return mix We can return the id as a string or as an int
         */
        template <class T> T get_id_from_name(
            const std::string &username
        );


        /**
         * @brief Test if the pair login/pass exists in the database
         *
         * @param string login The username
         * @param string pass  Password entered by the user in the form
         *
         * @return bool True if the pair login/pass exists
         *
         * @since 13 November 2012
         *
         */        
        bool is_login_correct(
            const std::string &login,
            const std::string &pass
        );         
 
        /**
         * @brief Check if a username is already taken or not
         *
         * @param username The user name to check
         *
         * @return True if it's already taken, false otherwise
         *
         * @since 21 January 2013
         */
        bool username_exists(
            const std::string &username
        );
 
        /**
         * @brief Check if a email is already taken or not
         *
         * @param email The email to check
         *
         * @return True if it's already taken, false otherwise
         *
         * @since 21 January 2013
         */
        bool email_exists(
            const std::string &email
        );
 
                   
        /**        
         * @brief Add a new user with the given login/pass/mail
         *
         * @param string login The user's name on the website
         * @param string pass  His password
         * @param string email His email address
         *
         * @return int negative number if the user can't be added,
         *             id of the user if successful
         *              
         *
         * @since 13 November 2012
         */        
        int add(
            const std::string &login,
            const std::string &pass,
            const std::string &email
        );         
                   
        /**
         * @brief Update the password of a user
         *
         * @param login       The username that we're updating
         * @param newPassword The new password in clear 
         *
         * @return bool True if everythign went smoothly,false otherwise
         *
         * @since 15 March 2013
         */
        bool change_password(
            const std::string &login,
            const std::string &newPassword
        );


};


/**
* @brief          User to retrieve the identifier of a given user
* @TODO           Throw an exception when the user does not exists
*
* @tparam T       Type under which we want the id (int or std::string)
* @param username Name of the user want the id of
* 
*
* @return         The id in the requested type 
*/
template <class T> T models::Users::get_id_from_name(
    const std::string &username
) {
    cppdb::statement getIdFromUsername = sqliteDb.prepare(
        "SELECT id FROM users WHERE username = ? LIMIT 1"
    );
    getIdFromUsername.bind(username);
    cppdb::result res = getIdFromUsername.row();

    T userId;
    res.fetch(0, userId);
    getIdFromUsername.reset();
    
    return userId;

}


} // end namespace models 
} // end namespace cppcmsskel

#endif
