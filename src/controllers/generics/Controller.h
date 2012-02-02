/**
 * Tatoeba Project, free collaborative creation of multilingual corpuses project
 * Copyright (C) 2011 Allan SIMON <allan.simon@supinfo.com>
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
 * @category Tatodetect
 * @package  Controllers
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @license  Affero General Public License
 * @link     http://tatoeba.org
 */


#ifndef CONTROLLERS_CONTROLLER_H
#define CONTROLLERS_CONTROLLER_H

#include <cppcms/json.h>
#include <cppcms/application.h>
#include <cppcms/url_dispatcher.h>

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

namespace contents {
    class BaseContent;
}

/** @namespace controllers
 * regroup all controllers of the application
 */
namespace controllers {
namespace generics {
/**
 * @class Controller
 * it's a generic which is herited by all controllers
 */
class Controller : public cppcms::application {
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
	public:
		Controller(cppcms::service &serv);
};

} // End namespace generics
} // End namespace controllers

#endif
