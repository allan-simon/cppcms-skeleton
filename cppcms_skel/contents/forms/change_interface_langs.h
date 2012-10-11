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
 * @package  Forms
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
 *
 */

#ifndef CPPCMS_SKEL_FORM_GENERICS_INTERFACE_LANG_FORM_H
#define CPPCMS_SKEL_FORM_GENERICS_INTERFACE_LANG_FORM_H


#include <cppcms/form.h>
#include "cppcms_skel/generics/Languages.h"

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


