/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall
 * be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Helpers
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
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



