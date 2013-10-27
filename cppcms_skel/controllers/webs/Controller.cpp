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
#include "cppcms_skel/results/Users.h"

#define USERNAME "username"
#define USERID   "userid"
#define MESSAGES "messages"
#define INTERFACE_LANG "interfaceLang"
#define PERMISSION_LEVEL "permissionLevel"


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
    content.lang = get_interface_lang();
    content.interfaceLang.set_langs();
    if (is_logged()) {
        content.currentUserHelper.username = get_current_username();
    }

    content.messages = get_messages();
}

/**
 *
 */
const contents::Messages Controller::get_messages() {
    contents::Messages messages;
    if (session().is_set(MESSAGES)) {

        session().fetch_data(MESSAGES,messages);
        session().erase(MESSAGES);
    }
    return messages;
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
void Controller::set_current_user_permission_level(
   const int permissionLevel
) {
    session()[PERMISSION_LEVEL] = std::to_string(permissionLevel);
}

/**
 *
 */
int Controller::get_current_user_permission_level() {
    return std::stoi(session()[PERMISSION_LEVEL]);
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
}

/**
 *
 */
void Controller::set_current_username(
    const std::string &username
) {
    session()[USERNAME] = username;
}



/**
 *
 */
void Controller::go_back_to_previous_page() {


    const std::string referer = request().http_referer();

    if (referer.empty()) {
        go_to_main_page();
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
    //TODO that will not work if the
    // application is not set at the root
    // of the server
    redirect("/");
}

/**
 *
 */
void Controller::go_to_login(
) {
    std::ostringstream oss;
    oss << cppcms::filters::urlencode(
       request().path_info()
    );

    redirect(
        //TODO that will not work if the
        // application is not set at the root
        // of the server
        "/users/login"
        "?from=" + oss.str()
    );

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
bool Controller::login_required() {

    if (!is_logged()) {
        go_to_login();
        return false;
    }

    return true;
}

bool Controller::admin_required() {

    if(!login_required()) {
        return false;
    }

    if(!is_current_user_admin()) {
        return false;
    }
    return true;

}


/**
 *
 */
int Controller::get_current_user_id() {
    return std::stoi(session()[USERID]);
}

/**
 *
 */
void Controller::add_message(
    const std::string &text,
    const std::string &type
) {

    contents::Messages messages;
    std::vector<int> plop;
    contents::Message newMessage(text, type);
    if (session().is_set(MESSAGES)) {
        std::string tmp;
        session().fetch_data(MESSAGES,messages);
    }

    messages.push_back(newMessage);
    session().store_data(
        MESSAGES,
        messages
    );
}

/**
 *
 */
void Controller::add_error(const std::string &text) {
    add_message(text, CPPCMS_SKEL_MESSAGE_ERROR);
}

/**
 *
 */
void Controller::add_info(const std::string &text) {
    add_message(text, CPPCMS_SKEL_MESSAGE_INFO);
}

/**
 *
 */
void Controller::add_success(const std::string &text) {
    add_message(text, CPPCMS_SKEL_MESSAGE_SUCCESS);
}

/**
 *
 */
void Controller::add_warning(const std::string &text) {
    add_message(text, CPPCMS_SKEL_MESSAGE_WARNING);
}

/**
 *
 */
bool Controller::is_current_user_admin() {
    const int admin = static_cast<int>(
        cppcmsskel::results::User::Permission::admin
    );
    return get_current_user_permission_level() == admin;
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
