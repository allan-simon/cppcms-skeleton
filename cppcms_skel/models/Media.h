/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com> 
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
 * @category Tatoeba wiki
 * @package  Models
 * @author   Allan SIMON <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/sysko/tatowiki@
 */

#ifndef CPPCMS_SKEL_MEDIA
#define CPPCMS_SKEL_MEDIA

#include <cppcms/http_file.h>
#include <booster/shared_ptr.h>
#include "SqliteModel.h"


namespace cppcmsskel {
namespace models {




/**
 * @class Media 
 * 
 * @since 7 June 2013
 *
 */
class Media : public SqliteModel {

    public:
        /**
         * @brief Constructor
         *
         * @since 7 June 2013
         */
        Media();

 
        /**
         * @brief Check if a email is already taken or not
         *
         * @param email The email to check
         *
         * @return True if it's already taken, false otherwise
         *
         * @since 21 January 2013
         */
        std::string save_media(
            booster::shared_ptr<cppcms::http::file> file
        );
 


};


} // end namespace models 
} // end namespace cppcmsskel

#endif
