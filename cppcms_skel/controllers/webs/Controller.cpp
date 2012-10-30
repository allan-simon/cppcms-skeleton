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


#include "Controller.h"
#include <cppcms/serialization_classes.h>
#include <cppcms/archive_traits.h>
#include <cppcms/session_interface.h>
#include <cppcms/filters.h>
#include <cppcms/http_response.h>

#include "cppcms_skel/contents/content.h"
#include "cppcms_skel/generics/Config.h"

namespace controllers {
namespace webs {

/**
 *
 */
Controller::Controller(cppcms::service &serv) :
    controllers::generics::Controller(serv)
{


}

/**
 *
 */
void Controller::init_content(contents::BaseContent& content) {
    
    response().content_encoding("UTF-8");
    response().set_content_header("text/html; charset=UTF-8");

    content.interfaceLang.set_langs();
    //std::cout << "user name: " << session()["name"] << std::endl;

    if (session().is_set("message")) {
        content.message = session()["message"];
        session().erase("message");
    }
}


/**
 *
 */
inline bool Controller::is_logged() {
    return !session()["name"].empty();
}




/**
 *
 */
void Controller::go_back_to_previous_page() {
    

    const std::string referer = request().http_referer();

    if (referer.empty()) {
        response().make_error_response(404);
    } else {

        //TODO we do not handle the case where the referer is not a valid page
        // "*_treat" page, or page that require a priviledge that the user does
        // not have anymore (if session has expired etc.)
        response().set_redirect_header(
            referer
        );
    }
}


/**
 *
 */
bool Controller::check_permission() {

    //TODO for the moment we do not handle case
    // when you're logged but you're current group has not
    // enough priviledges
    if (!is_logged()) {
        std::ostringstream oss;
        
        oss << cppcms::filters::urlencode(
           request().path_info()
        );

        response().set_redirect_header(
            "/users/login"
            "?from=" + oss.str()
        );
        return false;
    }
    return true;
}

/**
 *
 */
int Controller::get_current_user_id() {
    //std::cout << "[NOTICE] current id:" << session()["userId"] << std::endl;
    return atoi(session()["userId"].c_str());
}



/**
 *
 */

void Controller::set_message(std::string message) {

    session()["message"] = message;
}



} // End namespace webs
} // End namespace controllers
