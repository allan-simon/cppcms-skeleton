/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall
 * be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Controllers
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
 *
 */



#ifndef CPPCMSSKEL_CONTROLLERS_WEBS_CONTROLLER_H
#define CPPCMSSKEL_CONTROLLERS_WEBS_CONTROLLER_H

#include <cppcms/json.h>
#include <cppcms/application.h>
#include <cppcms/url_dispatcher.h>

#include "cppcms_skel/controllers/generics/Controller.h"

#define CHECK_PERMISSION_OR_GO_TO_LOGIN() \
    if (!check_permission()) {\
       return;\
    }

#define TREAT_PAGE() \
    if (request().post().empty()) {\
        response().set_redirect_header(\
            Config::get_base_host() \
        );\
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
    





namespace contents {
    struct BaseContent;
}

/** @namespace controllers
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
        bool check_permission();

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

        /* 
         * Return the id of the current user 
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         */
        int get_current_user_id();

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
         * @brief Set a message to display on the next page a user will view
         *        Note: for the moment it relies on the session for storing 
         *              information, so if your session storage backend need
         *              it, it's your job to call session().save()
         *
         * @param message The content of the message that will be displayed
         *
         * @since 30 August 2011
         */
        void set_message(const std::string &message);

        /**
         * @brief Get the message to display on the page that is going to be
         *        displayed to the user, note that the message is "destroyed"
         *        after you get it, so calling a second time this method will
         *        return you an empty string
         *
         * @return The message or an empty string if no message
         *
         * @since 14 November 2012
         */
        const std::string get_message();

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
