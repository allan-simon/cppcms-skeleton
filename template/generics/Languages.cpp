/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 *
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category @PROJECT_NAME_HUMAN@
 * @author   @AUTHOR@ <@EMAIL@> 
 * @package  Generics
 *
 */

#include "Languages.h"

/**
 *
 */
Languages::Languages() {}

/**
 *
 */
void Languages::init(
    cppcms::json::array langsJson,
    cppcms::json::array interfaceLangsJson
) {
    cppcms::json::array::const_iterator end = interfaceLangsJson.end();

    // lines are in this form
    // code , locale , natural name
    // e.g
    // "en" , "en_GB.UTF-8", "English"
    for (
        cppcms::json::array::const_iterator p=interfaceLangsJson.begin();
        p!= end;
        ++p
    ) {
        
        cppcms::json::array lang = p->array();

        std::string langCode = lang[0].str();

        langToLocale[langCode] = lang[1].str();
        interfaceCodeToName[langCode] = lang[2].str();
    }
}

std::string Languages::get_locale_from_lang(
    const std::string &lang
) {
    return langToLocale[lang];
}


bool Languages::is_interface_lang(
    const std::string &interfaceLang
) {
    return langToLocale.find(interfaceLang) != langToLocale.end();
}

/**
 *
 */
void Languages::fill_interface_lang_select(
    cppcms::widgets::select &select
) {

    InterfaceCodeToName::const_iterator itr;
    for(
        itr = interfaceCodeToName.begin();
        itr != interfaceCodeToName.end();
        ++itr
    ) {
        select.add(
            itr->second,
            itr->first
        );
    }

}



