/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Contents
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


