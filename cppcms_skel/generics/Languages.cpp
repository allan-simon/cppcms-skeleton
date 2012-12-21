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
 * @package  Singletons
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
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



