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

#define USERNAME "username"
#define USERID   "userid"
#define MESSAGE "message"
#define INTERFACE_LANG "interfaceLang"


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
    response().set_content_header("text/html");

    content.interfaceLang.set_langs();
    if (is_logged()) {
        content.currentUserHelper.username = get_current_username();
    }

    content.message = get_message();
}

/**
 *
 */
const std::string Controller::get_message() {
    std::string message = "";
    if (session().is_set(MESSAGE)) {
        message = session()[MESSAGE];
        session().erase(MESSAGE);
    }
    return message;
}

/**
 *
 */
bool Controller::is_logged() {
    return !get_current_username().empty();
}


/**
 *
 */
const std::string Controller::get_current_username() {
    return session()[USERNAME];
}

/**
 *
 */
void Controller::set_current_username_and_id(
    const std::string &username,
    const int userId
) {

    session()[USERID] = std::to_string(userId);
    session()[USERNAME] = username;
    session().save();
}

/**
 *
 */
void Controller::set_current_username(
    const std::string &username
) {
    session()[USERNAME] = username;
    session().save();
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
        redirect(referer);
    }
}

/**
 *
 */
void Controller::go_to_main_page() {
    //TODO replace this by something using Config:: 
    redirect("/");
}


/**
 *
 */
void Controller::redirect(
    const std::string &url
) {
    response().set_redirect_header(
        url
    );
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

        redirect(
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
    //TODO replace atoi by stoi from C++11
    return std::stoi(session()[USERID]);
}



/**
 *
 */

void Controller::set_message(const std::string &message) {
    //TODO maybe concatenate the message instead of replacing it
    //     as it may be possible in the future that several message
    //     are raised
    session()[MESSAGE] = message;
}

/**
 *
 */
void Controller::current_user_logout() {
    session().clear();
}

/**
 *
 */
const std::string Controller::get_interface_lang() {
    return session()[INTERFACE_LANG];
}


} // End namespace webs
} // End namespace controllers
