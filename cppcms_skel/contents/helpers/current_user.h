/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Contents
 *
 */

#ifndef CPPCMS_SKEL_CONTENTS_HELPER_CURRENT_USER_H
#define CPPCMS_SKEL_CONTENTS_HELPER_CURRENT_USER_H

#include "helpers.h"

namespace contents {
    namespace helpers {
        /**
         * @struct CurrentUser
         * Used everywhere we need to send current user information
         * to the view
         *
         * @since 14 November 2012
         */
        struct CurrentUser : public Helpers {
    
            /**
             * @brief Name of the user, empty for visitor
             *
             * @since 14 November 2012
             */
            std::string username;

            public:
                /**
                 * @brief To know if the current user is logged or not
                 *
                 * @since 14 November 2012
                 */
                bool is_logged() {
                    return !username.empty();
                }
        };
    }
}
#endif

