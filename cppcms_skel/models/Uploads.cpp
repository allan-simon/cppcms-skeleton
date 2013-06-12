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
 *
 * @category cppcmsskel
 * @package  Models
 * @author   Allan SIMON <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/sysko/cppcms-skeleton
 */


#include <cppdb/frontend.h>
#include <cppcms/util.h>
#include <cppcms/cppcms_error.h>
#include <cppcms/http_file.h>
#include <booster/log.h>

#include <cppcms_skel/generics/Config.h>
#include "models/Uploads.h"

namespace cppcmsskel {
namespace models {

/**
 *
 */
Uploads::Uploads() :
    SqliteModel()
{
}

/**
 * 
 */
std::string Uploads::save(
    booster::shared_ptr<cppcms::http::file> file
) {

    std::string filename = file->filename();
    try {
        //TODO if we keep the same name, we should then check that there's
        // not already a file with the same name
        file->save_to(filename);
        std::rename(
            filename.c_str(),
            (Config::get_upload_folder() + filename).c_str()
        );
    } catch (cppcms::cppcms_error const &e) {
        BOOSTER_ERROR("cppcms_skel") << e.what();
        return std::string();
    }
    return Config::get_upload_url() + filename;
}

} // end namespace models
} // end namespace cppcmsskel


