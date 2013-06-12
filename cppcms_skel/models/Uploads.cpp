/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
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


