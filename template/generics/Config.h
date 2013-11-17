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

#ifndef SHDICT_CONTENT_CONFIG_H
#define SHDICT_CONTENT_CONFIG_H

#include <map>
#include "generics/Singleton.h"

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

    public:
        /**
         * Store the path for css files
         */
        std::string cssPath;

        /**
         * Store the path for images files
         */
        std::string imgPath;

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


