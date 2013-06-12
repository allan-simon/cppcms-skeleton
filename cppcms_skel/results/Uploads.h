/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Results
 *
 */

#ifndef CPPCMS_SKEL_RESULTS_FILES_H
#define CPPCMS_SKEL_RESULTS_FILES_H

#include <vector>
#include <map>
#include <string>

namespace cppcmsskel {
namespace results {

    /**
     * @struct Upload Represent an uploaded file
     *
     * @since 12 June 2013
     *
     */
    struct File {
        std::string name;
        std::string URLname;
        unsigned created;
        
        File() {};
        File(
            const std::string &nameParam,
            const std::string &URLnameParam,
            const unsigned createdParam
        ) :
            name(nameParam),
            URLname(URLnameParam),
            created(createdParam)
        {

        };
    };

    typedef std::vector<results::File> Files;

} // End namespace results
} // End namespace cppcmsskel

#endif
