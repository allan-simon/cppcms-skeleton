/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 *
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category @PROJECT_NAME_HUMAN@
 * @author   @AUTHOR@ <@EMAIL@> 
 * @package  Controllers
 * @link     @PROJECT_WEBSITE@
 *
 */

#include <cppcms/session_interface.h>
#include "%%CONTROLLER_NAME%%.h"


#include "contents/%%CONTROLLER_NAME%%.h"

//%%%NEXT_INC_MODEL_CTRL_MARKER%%%


namespace @PROJECT_NS@ {
namespace controllers {
namespace webs {

%%CONTROLLER_NAME%%::%%CONTROLLER_NAME%%(cppcms::service& serv) :
    ::controllers::webs::Controller(serv)
{

    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete

    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
}

/**
 *
 */
%%CONTROLLER_NAME%%::~%%CONTROLLER_NAME%%() {
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
} // End namespace @PROJECT_NS@
