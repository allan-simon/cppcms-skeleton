/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
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
 * @link     @PROJECT_WEBSITE@
 */


#ifndef CONTROLLERS_CONTROLLER_H
#define CONTROLLERS_CONTROLLER_H

#include <cppcms/json.h>
#include <cppcms/application.h>
#include <cppcms/url_dispatcher.h>



namespace contents {
    struct BaseContent;
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
    //TODO need to check what i'm doing wrong with virtual functions
	protected:

        /**
         * Wrapping function that will initialize content send to the
         * view with common values (such as interface language etc.)
         */

        //virtual void init_content(contents::BaseContent& content) = 0;
    
        /**
         * Return if the current visitor is a logged user or not
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         */
        //virtual bool is_logged() = 0 ;
        /**
         * Check if the current user as the permission to do this action,
         * view this page
         * @TODO : maybe add a parameter to precising which action
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         * 
         */
        //virtual bool check_permission() = 0;

        /**
         * Convenience function to make an http redirection to the 
         * referer
         */
        //virtual void go_back_to_previous_page() = 0;

        /* 
         * Return the id of the current user 
         * @TODO maybe move this in a dedicated class that would
         * represent the current user
         */
        //virtual int get_current_user_id() = 0;
	public:
		Controller(cppcms::service &serv);
        //virtual ~Controller() {};
};

} // End namespace generics
} // End namespace controllers

#endif
