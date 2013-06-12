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
#include "SqliteModel.h"


namespace cppcmsskel {
namespace models {




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
        

};


} // end namespace models 
} // end namespace cppcmsskel

#endif
