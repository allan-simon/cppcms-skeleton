/**
 * @PROJECT_NAME_HUMAN@  free collaborative creation of multilingual corpuses project
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
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
 * @category @PROJECT_NAME_HUMAN@
 * @package  Singletons
 * @author   @AUTHOR@ <@EMAIL@> 
 * @license  Affero General Public License
 * @link     http://tatoeba.org
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


