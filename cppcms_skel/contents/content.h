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
 * @package  Contents
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
 *
 */

#ifndef CPPCMS_SKEL_CONTENTS_BASE_CONTENT_H
#define CPPCMS_SKEL_CONTENTS_BASE_CONTENT_H

#include <cppcms/view.h>

#include "cppcms_skel/contents/forms/change_interface_langs.h"
#include "cppcms_skel/contents/helpers/current_user.h"
#include "messages.h"
namespace contents {

/**
 * @struct 
 */
struct BaseContent : public cppcms::base_content {

    /**
     * @brief Will contain The flash messages to inform the user about the
     *        success/failure of actions.
     *
     * @since 3 June 2013
     */
    Messages messages;

    /**
     * @brief Helper that contain all the information related to the
     *        current user
     *
     * @since 14 November 2012
     */
     helpers::CurrentUser currentUserHelper;

    /**
     * @brief Form which permits to change the user interface language
     *
     * @since 2 September
     */
    forms::InterfaceLang interfaceLang;

    /**
     * @brief Language of the page
     *
     * @since 24 May 2013
     */
     std::string lang;
    
};

}

#endif
