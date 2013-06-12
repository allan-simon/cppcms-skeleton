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
#include "Img.h"



//%%%NEXT_INC_MODEL_CTRL_MARKER%%%


namespace controllers {
namespace webs {

Img::Img(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{
    dispatcher().assign("/([a-z_0-9/\\.-]+.(jpg|jpeg|png))[0-9]*", &Img::serve_file, this, 1, 2);

    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete

    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
}

void Img::serve_file(
    std::string imgFile,
    std::string mimeType
) {
    std::string absolutePath = Config::get_inner_img_folder() + imgFile;
    std::ifstream file(
        absolutePath.c_str()
    );  
    if(!file.good()) {  
       response().status(404);
       response().out() << "404";
    }  
    else {  
        // jpg and jpeg are equivalent but only the mime type image/jpeg is
        // legal
        if (mimeType == "jpg") {
            mimeType = "jpeg";
        }
        response().content_type(std::string("image/") + mimeType );
        response().out() << file.rdbuf();  
    }  

    file.close();
}



/**
 *
 */
Img::~Img() {
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
