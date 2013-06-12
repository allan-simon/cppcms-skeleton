/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Generics
 *
 */

#include <iostream>
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

    // lines are in this form
    // code , locale , natural name
    // e.g
    // "en" , "en_GB.UTF-8", "English"
    cppcms::json::array::const_iterator end = interfaceLangsJson.end();
    for (
        cppcms::json::array::const_iterator p=interfaceLangsJson.begin();
        p!= end;
        ++p
    ) {
        
        cppcms::json::array lang = p->array();

        std::string langCode = lang[0].str();
        std::string locale = lang[1].str();
        std::string name = lang[2].str();

        langToLocale[langCode] =  locale;
        interfaceCodeToName[langCode] = name;
    }
    // we now process the languages used in the website itself
    end = langsJson.end();
    for (
        cppcms::json::array::const_iterator p=langsJson.begin();
        p!= end;
        ++p
    ) {

        cppcms::json::array lang = p->array();

        std::string langCode = lang[0].str();
        std::string englishName = lang[1].str();
        nameToCode[englishName] = langCode;
    }

}

/**
 *
 */
std::string Languages::get_interface_lang_from_code(
    const std::string &code
) {
    return interfaceCodeToName[code];
}

/**
 *
 */
std::string Languages::get_locale_from_lang(
    const std::string &lang
) {
    return langToLocale[lang];
}


/**
 *
 */
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


/**
 *
 */
void Languages::fill_form_select(cppcms::widgets::select &select) {
    for( NameToCode::const_iterator itr = nameToCode.begin(); itr != nameToCode.end(); ++itr){
        //TODO l10n the language name
        select.add(
            itr->first,
            itr->second
        );
    }

}



