/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Controllers
 *
 */

#ifndef CPPCMSSKEL_CONTROLLERS_WEBS_CONTROLLER_H
#define CPPCMSSKEL_CONTROLLERS_WEBS_CONTROLLER_H

#include <cppcms/json.h>
#include <cppcms/application.h>
#include <cppcms/url_dispatcher.h>

#include "cppcms_skel/controllers/generics/Controller.h"
#include "cppcms_skel/contents/content.h"
#include "cppcms_skel/results/Users.h"

#define LOGIN_REQUIRED() \
    if (!login_required()) {\
       return;\
    }

#define ADMIN_REQUIRED() \
    if (!admin_required()) {\
        return;\
    }


#define TREAT_PAGE() \
    if (request().post().empty()) {\
        go_to_main_page(); \
        return;\
    }

#define GET_FIELD(fieldVar, fieldString) \
    it = getData.find(fieldString);\
    if (it != getData.end()) {\
        fieldVar = it->second;\
    }

#define GET_INT_FIELD(fieldVar, fieldString) \
    it = getData.find(fieldString);\
    if (it != getData.end()) {\
        fieldVar = atoi(it->second.c_str());\
    }



/**
 * @namespace controllers
 * regroup all controllers of the application
 */
namespace controllers {
namespace webs {

/**
 * @class Controller
 * it's a generic which is herited by all controllers
 */
class Controller : public controllers::generics::Controller {
	protected:

        /**
         * Wrapping function that will initialize content send to the
         * view with common values (such as interface language etc.)
         */

        void init_content(contents::BaseContent& content);

        /**
         * Return if the current visitor is a logged user or not
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         */
        bool is_logged();

        /**
         * @brief Function that logout the user, it's not supposed to be called
         *        In other controllers than the one managing users but as other
         *        Methods dealing with the current user are put there, we put it
         *        too for consistency
         *
         * @since 14 November 2012
         */
         void current_user_logout();

        /**
         * Check if the current user as the permission to do this action,
         * view this page
         * @TODO : maybe add a parameter to precising which action
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         *
         */
        bool login_required();

        bool admin_required();

        /**
         * Convenience function to make an http redirection to the
         * referer
         */
        void go_back_to_previous_page();

        /**
         * @brief Redirect to the main page of the application (which
         *        is maybe not the root of the domain)
         *
         * @since 17 November 2012
         */
        void go_to_main_page();

        /**
         * Redirect to login page, with the page we tried to display in
         * parameter so that after login, we will be able to go back to
         * where we were if wanted
         *
         * @since 20 October 2013
         */
        void go_to_login();
        /*
         * Return the id of the current user
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         */
        int get_current_user_id();


        /**
         * Set what is the permission level (admin/moderator/normal user etc.)
         * of the current user (a.k.a the one who is making the request)
         *
         * @param permissionLevel The permission level we want to set
         *
         * @since 20 October 2013
         */
        void set_current_user_permission_level(
           const int permissionLevel
        );

        void set_current_user_permission_level(
            cppcmsskel::results::User::Permission permissionLevel
        );

        /**
         * Get what is the permission level (admin/moderator/normal user etc.)
         * of the current user (a.k.a the one who is making the request)
         *
         * @return int The permission level of the current user
         *
         * @since 20 October 2013
         */
        int get_current_user_permission_level();

        /**
         * Check if the user making the request is an admin or not
         *
         * @return bool True if the user is an admin, false otherwise
         *
         * @since 20 October 2013
         */
        bool is_current_user_admin();

        /**
         * @brief Gives the current username
         *
         * @return string The username
         *
         * @since 14 November 2012
         */
        const std::string get_current_username();

        /**
         * @brief Set the current user name and id to be reused after by other
         *        Controllers
         *        Note: for the moment it relies on the session for storing
         *              information, so if your session storage backend need
         *              it, it's your job to call session().save()
         *
         * @param string userName The user's name
         * @param id     Userid   The user's id (thanks captain obvious)
         *
         * @since 14 November 2012
         */
        void set_current_username_and_id(
            const std::string &username,
            const int userId
        );


        /**
         * @brief Set the current user name to be reused after by other
         *        Controllers
         *        Note: for the moment it relies on the session for storing
         *              information, so if your session storage backend need
         *              it, it's your job to call session().save()
         *
         * @param string userName The user's name
         *
         * @since 14 November 2012
         */
        void set_current_username(
            const std::string &username
        );

        /**
         * @brief Wrapper  function to set the redirect url header
         *
         * @param string url The URL on which the user will be redirected
         * @since 12 November 2012
         */
        void redirect(
            const std::string &url
        );

        /**
         * @brief Add a message to display on the next page a user will view
         *        Note: for the moment it relies on the session for storing
         *              information, so if your session storage backend need
         *              it, it's your job to call session().save()
         *
         * @param text The content of the message that will be displayed
         * @param type The kind of message (success message, error mess, etc.)
         *
         * @since 3 June 2013
         */
        void add_message(
            const std::string &text,
            const std::string &type = "info"
        );

        /**
         * @brief Add an error message that will be displayed at next page
         *        viewed by the user
         *
         * @param text Text to display in the message
         *
         * @since 3 June 2013
         */
        void add_error(const std::string &text);

        /**
         * @brief Add a warning message that will be displayed at next page
         *        viewed by the user
         *
         * @param text Text to display in the message
         *
         * @since 3 June 2013
         */
        void add_warning(const std::string &text);

        /**
         * @brief Add an information message that will be displayed at next
         *        page viewed by the user
         *
         * @param text Text to display in the message
         *
         * @since 3 June 2013
         */
        void add_info(const std::string &text);

        /**
         * @brief Add a success message that will be displayed at next page
         *        viewed by the user
         *
         * @param text Text to display in the message
         *
         * @since 3 June 2013
         */
        void add_success(const std::string &text);

        /**
         * @brief Get the messages to display on the page that is going to be
         *        displayed to the user, note that messages are "destroyed"
         *        after you get them, so calling a second time this method
         *        will return you an empty set of messages
         *
         * @return The messages
         *
         * @since 14 November 2012
         */
        const contents::Messages get_messages();

        /**
         * @brief Get the same language in which the current user has the
         *        interface
         *
         * @return string The code of the language of the interface for the
         *                current user
         *
         * @since 16 November 2012
         *
         */
         const std::string get_interface_lang();

	public:
		Controller(cppcms::service &serv);
};

} // End namespace webs
} // End namespace controllers

#endif
