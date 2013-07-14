/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Controllers
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
    std::string absolutePath = Config::get_assets_folder() + jsFile;
    std::ifstream file(
        absolutePath.c_str()
    );  
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
