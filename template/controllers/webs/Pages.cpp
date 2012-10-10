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

#include <cppcms/session_interface.h>
#include "Pages.h"

#include "contents/Pages.h"

#include "framework/src/contents/forms/change_interface_langs.h"



namespace controllers {
namespace webs {

Pages::Pages(cppcms::service& serv) : controllers::webs::Controller(serv) {
    dispatcher().assign("", &Pages::homepage, this);
}

/**
 *
 */
void Pages::change_interface_lang_treat() {
    forms::InterfaceLang form;
    form.set_langs();
    form.load(context());
    if(!form.validate()) {
        go_back_to_previous_page();
    }

    session()["interfaceLang"] =  form.interfaceLang.selected_id();

    go_back_to_previous_page();



}

/**
 *
 */
void Pages::homepage() {
    contents::pages::Homepage c;
    init_content(c);


    render("homepage", c);
}


} // End namespace webs
} // End namespace controllers
