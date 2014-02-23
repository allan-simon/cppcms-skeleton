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

        int id;
        std::string name;
        Permission permission;

        User(
            const int idParam = -1,
            const std::string & nameParam = "",
            int permissionParam = 5 // blocked user
        ) :
            id(idParam),
            name(nameParam)
        {
            //TODO that line has undefined behavior if int is not
            // a valid permission
            permission = static_cast<Permission>(permissionParam);
        };

        bool exists () {
            return id > 0;
        }


    };

} // End namespace results
} // End namespace cppcmsskel

#endif

