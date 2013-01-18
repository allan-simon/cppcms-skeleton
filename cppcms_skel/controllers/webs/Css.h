/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
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
 * @package  Controllers
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
 *
 */


#ifndef CPPCMSSKEL_CONTROLLERS_WEBS_CSS_H
#define CPPCMSSKEL_CONTROLLERS_WEBS_CSS_H

#include "cppcms_skel/controllers/webs/Controller.h"


//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the// controller every time we modify a model. even though it does// not affect the controller
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
