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
 * @package  Forms
 * @author   @AUTHOR@ <@EMAIL@> 
 * @license  Affero General Public License
 * @link     @PROJECT_WEBSITE@
 */


#ifndef @MAIN_CLASS@_FORM_GENERICS_INTERFACE_LANG_FORM_H
#define @MAIN_CLASS@_FORM_GENERICS_INTERFACE_LANG_FORM_H


#include <cppcms/form.h>
#include "generics/Languages.h"

namespace forms{

/**
 * @brief Generic form to use wherever we can filter by language
 */
struct InterfaceLang : public cppcms::form {

    /**
     * @brief Html select to choose the interface's language 
     */
    cppcms::widgets::select interfaceLang;

    /**
     * @brief Button to submit the form
     */
    cppcms::widgets::submit submit;        


    /**
     * @brief Constructor
     */
    InterfaceLang() {

        //TODO i18n
        interfaceLang.non_empty();

        //TODO i18n
        submit.name("OK");
        submit.value("OK");

        add(interfaceLang);
        add(submit);

    }
    //TODO factorize this
    void set_langs() {
        Languages::get_instance()->fill_interface_lang_select(interfaceLang);
    }


};



}// end of namespace forms


#endif


