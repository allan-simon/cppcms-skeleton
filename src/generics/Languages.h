/**
 * Tatoeba Project, free collaborative creation of multilingual corpuses project
 * Copyright (C) 2011 Allan SIMON <allan.simon@supinfo.com>
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
 * @category Tatodetect
 * @package  Singletons
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @license  Affero General Public License
 * @link     http://tatoeba.org
 */



#ifndef SHDICT_GENERICS_LANGUAGES_H
#define SHDICT_GENERICS_LANGUAGES_H

#include <map>
#include "Singleton.h"
#include <cppcms/json.h>
#include <cppcms/form.h>

//TODO maybe replace all these maps by something smarter
typedef std::map<std::string, std::string> InterfaceLangToLocale;
typedef std::map<std::string, std::string> InterfaceCodeToName;


//TODO try to view how it deals with i18n (especially for language name sorting)
/**
 * Singleton class used to store the information about the
 * languages supported in Tatoeba, and their related info
 * ISO code, name, id in the database 
 */
class Languages : public Singleton<Languages> {
    friend class Singleton<Languages>;

    private:

        /**
         * @brief map associating a lang string to a locale (for example
         *        fr => fr_FR.UTF-8
         *
         * @since 1 September 2011
         */
        InterfaceLangToLocale langToLocale;

        InterfaceCodeToName interfaceCodeToName;

        Languages();

    public:

        /**
         * Initialize the singleton with the data stored in config.js 
         * TODO DOC
         */
        void init(
            cppcms::json::array langsJson,
            cppcms::json::array interfaceLangsJson
        );

          
        /**
         * @brief Return the locale associated to a interface lang code
         *
         * @param lang The interface lang code
         *
         * @return A locale string (such as fr_FR.UTF-8)
         *
         * @since 1 September 2011
         *
         */
        std::string get_locale_from_lang(const std::string &lang);
  
  
        /**
         * @brief Permits to know if a given subdomain is actually an interface
         *        lang
         *
         * @param subdomain The subdomain to test
         *
         * @return True if it represents a interface lang code, false otherwise
         *
         * @since 1 September 2011
         *
         */

        bool is_interface_lang(const std::string &subdomain);
  

 
        /**
         * @brief Fill a html form's select with all the supported languages
         *        for the user interface.
         *
         * @param select The cppcms select to fill
         *
         * @since 2 September 2011
         */
        void fill_interface_lang_select(cppcms::widgets::select &select);

};

#endif
