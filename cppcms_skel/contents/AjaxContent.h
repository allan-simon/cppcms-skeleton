/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Contents
 *
 */

#ifndef CPPCMS_SKEL_CONTENTS_AJAX_CONTENT_H
#define CPPCMS_SKEL_CONTENTS_AJAX_CONTENT_H

#include <vector>
#include <cppcms/view.h>

#include "messages.h"
namespace cppcmsskel {
namespace contents {

struct AjaxError {
    /** 
     * @brief Error code, to make it easy to treat with 'if' and 
     *        language of the interface independant
     *
     * @since 18 June 2013
     */
    unsigned code;
    
    /**
     * @brief Error text, to make it easy for human to know what's
     *        going wrong
     *
     * @since 18 June 2013
     */
    std::string text;
    
    AjaxError(
        const unsigned codeParam,
        const std::string &textParam
    ) : 
    code(codeParam) , 
    text(textParam)
    {
    }
};

typedef std::vector<AjaxError> AjaxErrors;

/**
 * @struct 
 */
struct AjaxContent : public cppcms::base_content {

    /**
     * @brief Will contain The flash messages to inform the user about the
     *        success/failure of actions.
     *
     * @since 3 June 2013
     */
    AjaxErrors errors;

    void add_error(
        const unsigned code,
        const std::string &text
    ) {
        errors.push_back(AjaxError(code,text));
    }
        
};

} // End of namespace contents 
} // End of namespace cppcmsskel
#endif
