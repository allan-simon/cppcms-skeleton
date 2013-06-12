/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Contents
 *
 */

#ifndef CPPCMS_SKEL_CONTENTS_HELPER_HELPERS_H
#define CPPCMS_SKEL_CONTENTS_HELPER_HELPERS_H

#include <cppcms/view.h>

namespace contents {
    namespace helpers {
        /**
         * @struct contents::helpers::Helper
         * Base struct for sending data from the controller to the view
         * for data meant to be used in some reusable modules
         *
         * @since 14 November 2012
         */
        struct Helpers : public cppcms::base_content {
            /**
             * @brief Base url used in the helper in case we need to generate
             *        Some link
             * 
             * @since 14 November 2012
             *
             * @TODO  Check if we still need it
             */
            std::string baseUrl;
        };
    }
}

#endif



