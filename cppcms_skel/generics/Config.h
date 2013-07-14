/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Generics
 *
 */

#ifndef CPPCMS_SKEL_CONTENT_CONFIG_H
#define CPPCMS_SKEL_CONTENT_CONFIG_H

#include <map>
#include <cppcms/json.h>
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
         * @brief Store the base url for the assets (img/css/js)
         *
         * @since 14 July 2013
         */
        std::string assetsURL;

        /**
         * @brief Store the URL for uploaded files as used in the HTML
         * @since 07 June 2013
         */
        std::string uploadURL;

        /**
         * @brief Store the path for assets files (img/css/js) 
         *        on the server (if the application itself serve 
         *        them
         *
         * @since 14 July 2013
         */
         std::string assetsFolder;


        /**
         * @brief Store the internal path for the uploaded file on the
         *        server 
         * @since 7 June 2013
         */
        std::string uploadFolder;



    public:
        /**
         * @brief Set the values used by the config singleton
         *        using the part of the config json dedicated
         *        to it 
         *
         * @param appConfig The json array containing the configuration
         *
         * @param 07 June 2013
         */
        static void set_values(cppcms::json::value appConfig);

        static std::string get_base_host();
        static void set_base_host(const std::string & baseHost);

        static std::string get_assets_folder();
        static void set_assets_folder(
            const std::string & assetsFolder
        );
        
        static std::string get_assets_url();
        static void set_assets_url(
            const std::string & assetsURL
        );



        static std::string get_upload_url();
        static void set_upload_url(const std::string &uploadURL);

        static std::string get_upload_folder();
        static void set_upload_folder(const std::string &uploadFolder);

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


