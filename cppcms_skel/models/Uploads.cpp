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
#include <booster/posix_time.h>
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
        file->write_data();
        file->save_to(
            (Config::get_upload_folder() + filename).c_str()
        );
    } catch (cppcms::cppcms_error const &e) {
        BOOSTER_ERROR("cppcms_skel") << e.what();
        return UPLOADS_SAVE_ON_DISK_ERROR;
    }
    
    cppdb::statement saveFile = sqliteDb.prepare(
        "INSERT INTO uploads(filename, created) "
        "VALUES(?,?)"
    );
    saveFile.bind(filename);
    saveFile.bind(
        booster::ptime::now().get_seconds()
    );

    if (!execute_simple(saveFile)) {
        return UPLOADS_SAVE_ON_DB_ERROR;
    }

    return Config::get_upload_url() + filename;
}

/**
 * 
 */
results::Files Uploads::list(
    const unsigned limit,
    const unsigned page
) {
    results::Files files;
    cppdb::statement listFiles = sqliteDb.prepare(
        "SELECT "
        "   filename, "
        "   created "
        "FROM uploads "
        "LIMIT ? OFFSET ? "
    );
    listFiles.bind(limit); 
    listFiles.bind(page*limit); 
    
    
    std::string baseURL = Config::get_upload_url();
    
    cppdb::result res = listFiles.query();
    while (res.next()) {
        std::string name = res.get<std::string>("filename");

        files.push_back(results::File(
            name,
            baseURL + name,
            res.get<unsigned>("created")
        ));
    }
    listFiles.reset();

    return files;
}

} // end namespace models
} // end namespace cppcmsskel


