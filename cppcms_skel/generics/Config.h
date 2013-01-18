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

#ifndef CPPCMS_SKEL_CONTENT_CONFIG_H
#define CPPCMS_SKEL_CONTENT_CONFIG_H

#include <map>
#include "cppcms_skel/generics/Singleton.h"

/**
 * Singleton class that store some value used in html generation
 * such as the path for css files etc.
 */ 
class Config : public Singleton<Config> {
    friend class Singleton<Config>;

    private:

        /**
         * Default constructor, do nothing for the moment
         */
        Config();

        /**
         * @brief Store the base domain name
         *
         * @since 28 December 2012
         */
        std::string baseHost;

        /**
         * @brief Store the path for css files as displayed on the webpage
         *
         * @since 18 January 2013
         */
        std::string cssPath;

 

        /**
         * @brief Store the path for images files as used in the HTML
         * @since 19 January 2013
         */
        std::string imgPath;




        /**
         * @brief Store the path for css files on the server
         *        (if the application itself server the CSS)
         *
         * @since 18 January 2013
         */
         std::string innerCssFolder;

        /**
         * @brief Store the path for image files on the server
         *        (if the application itself server the images)
         *
         * @since 19 January 2013
         */
         std::string innerImgFolder;




    public:

        static std::string get_base_host();

        static void set_base_host(const std::string & baseHost);

        static std::string get_inner_css_folder();

        static void set_inner_css_folder(
            const std::string & cssFolder
        );

        static std::string get_css_path();

        static void set_css_path(const std::string & cssPath);


        static std::string get_inner_img_folder();

        static void set_inner_img_folder(
            const std::string & imgFolder
        );

        static std::string get_img_path();

        static void set_img_path(const std::string & imgPath);


        /**
         * Store the root URL of the website
         */
        std::string webPath;


        /**
         * Store the path where the sqlite3 database is stored
         */
        std::string sqlite3Path;
};

#endif


