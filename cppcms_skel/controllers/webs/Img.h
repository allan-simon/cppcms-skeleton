/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Controllers
 *
 */

#ifndef CPPCMSSKEL_CONTROLLERS_WEBS_IMG_H
#define CPPCMSSKEL_CONTROLLERS_WEBS_IMG_H


#include "Controller.h"


//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the// controller every time we modify a model. even though it does// not affect the controller
namespace models {
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%% 
}

namespace controllers {
namespace webs { 
/**
 * @class Img
 * @brief @TODO add a description
 * @since 19 January 2013
 */
class Img : public Controller {
    public:
        /**
         * @brief Constructor
         * @since 19 January 2013
         */
        Img(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since 19 January 2013
         */
        ~Img();

        /**
         * @brief Serve an image file
         *
         * @param imgFile The relative path of the image file
         * @param mimeType Mime Type of the image (either jpeg, png or gif)
         *
         * @since 18 January 2013
         */
         void serve_file(
            std::string imgFIle,
            std::string mimeType
        );



    private:
        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace controllers

#endif
