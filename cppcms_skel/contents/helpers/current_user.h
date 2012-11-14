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

