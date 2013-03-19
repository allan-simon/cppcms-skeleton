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

#include <fstream>


#include <cppcms/http_response.h>
#include <cppcms/session_interface.h>
#include <cppcms_skel/generics/Config.h>
#include "Js.h"



//%%%NEXT_INC_MODEL_CTRL_MARKER%%%


namespace controllers {
namespace webs {

Js::Js(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{
    dispatcher().assign("/([a-z_0-9/*\\.-]+.js)[0-9]*", &Js::serve_file, this, 1);


    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete

    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
}


void Js::serve_file(std::string jsFile) {
    std::string absolutePath = Config::get_inner_js_folder() + jsFile;
    std::ifstream file(
        absolutePath.c_str()
    );  
    std::cout << absolutePath << std::endl;
    if(!file.good()) {  
       response().status(404);
       response().out() << "404";
    }  
    else {  
        response().content_type("application/javascript");
        response().out() << file.rdbuf();  
    }  

    file.close();
}


/**
 *
 */
Js::~Js() {
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
