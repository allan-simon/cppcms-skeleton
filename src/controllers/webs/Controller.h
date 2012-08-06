/**
 * @PROJECT_NAME_HUMAN@  free collaborative creation of multilingual corpuses project
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
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
 * @category @PROJECT_NAME_HUMAN@
 * @package  Controllers
 * @author   @AUTHOR@ <@EMAIL@> 
 * @license  Affero General Public License
 * @link     http://tatoeba.org
 */


#ifndef CONTROLLERS_WEBS_CONTROLLER_H
#define CONTROLLERS_WEBS_CONTROLLER_H

#include <cppcms/json.h>
#include <cppcms/application.h>
#include <cppcms/url_dispatcher.h>

#include "controllers/generics/Controller.h"


//#include "contents/content.h"

#define CHECK_PERMISSION_OR_GO_TO_LOGIN() \
    if (!check_permission()) {\
       return;\
    }

#define TREAT_PAGE() \
    if (request().post().empty()) {\
        response().set_redirect_header(\
            "/" \
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
    class BaseContent;
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

        /* 
         * Return the id of the current user 
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         */
        int get_current_user_id();

                
        /**
         * @brief Set a message to display on the next page a user will view
         *
         * @param message The content of the message that will be displayed
         *
         * @since 30 August 2011
         */
        void set_message(std::string message);

	public:
		Controller(cppcms::service &serv);
};

} // End namespace webs
} // End namespace controllers

#endif
