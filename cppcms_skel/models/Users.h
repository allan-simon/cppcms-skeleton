/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
 */

#ifndef CPPCMS_SKEL_USERS
#define CPPCMS_SKEL_USERS



#include "SqliteModel.h"


namespace cppcmsskel {
namespace models {


#define USERS_NOT_ADDED_ERROR -1

//TODO replace this by an enum
#define USERS_ADMIN 0
#define USERS_MODERATOR 1
#define USERS_ADVANCED_USER 2
#define USERS_NORMAL_USER 3
#define USERS_BLOCKED_USER 4
#define USERS_INACTIVE_USER 5

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
        
        /**
         * @brief change the permission a user has
         *
         * @param login The user we want to upgrade/downgrade
         * @param newPermissionLevel The new permission of this user
         *
         * @return bool Return if the change was successful or not
         *
         * @since 25 April 2013
         */
        bool change_permission_level(
            const std::string &login,
            const int newPermissionLevel
        );


        /**
         * @brief check if there's already at least one admin user
         *
         * @return bool True if there's an admin or more, false otherwise
         *
         * @since 25 April 2013
         */
        bool admin_exists(void);


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
