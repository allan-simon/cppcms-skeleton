/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
 */

#ifndef CPPCMS_SKEL_UPLOADS
#define CPPCMS_SKEL_UPLOADS

#include <cppcms/http_file.h>
#include <booster/shared_ptr.h>
#include "cppcms_skel/results/Uploads.h"
#include "SqliteModel.h"

namespace cppcmsskel {
namespace models {

#define UPLOADS_SAVE_ON_DISK_ERROR ""
#define UPLOADS_SAVE_ON_DB_ERROR " "

/**
 * @class Uploads 
 * 
 * @since 7 June 2013
 *
 */
class Uploads : public SqliteModel {

    public:
        /**
         * @brief Constructor
         *
         * @since 7 June 2013
         */
        Uploads();
 
        /**
         * @brief Save a file on the server
         *
         * @param file A pointer to the file to save
         *
         * @since 7 June 2013
         */
        std::string save(
            booster::shared_ptr<cppcms::http::file> file
        );

 
        /**
         * @brief Get a list of files
         *
         * @param limit Number of files to get
         * @page  page  For paginated result, permit to get files
         *              of that page number
         *
         * @since 13 June 2013
         */
        results::Files list(
            const unsigned limit,
            const unsigned page = 0
        );
};


} // end namespace models 
} // end namespace cppcmsskel

#endif
