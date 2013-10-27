/**
 * Copyright (C) 2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Results
 *
 */

#ifndef CPPCMS_SKEL_RESULTS_USERS_H
#define CPPCMS_SKEL_RESULTS_USERS_H

#include <vector>
#include <map>
#include <string>

namespace cppcmsskel {
namespace results {

    struct User {

         /**
          * @enum Permission
          * @brief Enumeration of the different kind of users
          */
         enum class Permission {
             admin = 0,
             moderator,
             advance,
             normal,
             inactive,
             blocked
         };

        std::string name;
        int id;
        Permission permission;




    };

} // End namespace results
} // End namespace cppcmsskel

#endif

