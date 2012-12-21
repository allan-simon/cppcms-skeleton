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



#ifndef CPPCMS_SKEL_GENERICS_LANGUAGES_H
#define CPPCMS_SKEL_GENERICS_LANGUAGES_H

#include <map>
#include "Singleton.h"
#include <cppcms/json.h>
#include <cppcms/form.h>

//TODO maybe replace all these maps by something smarter
typedef std::map<std::string, std::string> InterfaceLangToLocale;
typedef std::map<std::string, std::string> InterfaceCodeToName;
typedef std::map<std::string, std::string> NameToCode;


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
        /**
         * @brief map association the lang name to an iso code
         *        for example  English => en
         * @since 8 December 2012
         */
        NameToCode nameToCode;

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
         * @brief Return the name associated a interface lang code
         *        Note: the name of the language is in this language
         *        i.e  Français for fr , Deutsch for de etc.
         *
         * @param lang The interface lang code
         *
         * @return A language name string (such as Français)
         *
         * @since 22 December 2012
         *
         */
        std::string get_interface_lang_from_code(const std::string &code);
  
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


        /**
         * @brief Fill a html form's select and fill it with all the supported
         *        languages
         *
         * @param select The cppcms select to fill
         * @since 8 December 2012
         */
        void fill_form_select(cppcms::widgets::select &select);


};

#endif
