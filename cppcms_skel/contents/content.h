/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Contents
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
