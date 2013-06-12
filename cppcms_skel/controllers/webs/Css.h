/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Controllers
 *
 */

#ifndef CPPCMSSKEL_CONTROLLERS_WEBS_CSS_H
#define CPPCMSSKEL_CONTROLLERS_WEBS_CSS_H

#include "cppcms_skel/controllers/webs/Controller.h"


// needed to avoid to include models directly here,
// which would have the side effects to require to recompile the
// controller every time we modify a model. even though it does
// not affect the controller
namespace models {
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%% 
}

namespace controllers {
namespace webs { 
/**
 * @class Css Controller used to serve the css when run as a standalone server
 * @since 18 January 2013
 */
class Css : public Controller {
    public:
        /**
         * @brief Constructor
         * @since 18 January 2013
         */
        Css(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since 18 January 2013
         */
        ~Css();

        /**
         * @brief Serve a css file
         *
         * @param cssFile the relative path of the css file
         *
         * @since 18 January 2013
         */
         void serve_file(
            std::string cssFIle
        );

    private:
        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace controllers

#endif
