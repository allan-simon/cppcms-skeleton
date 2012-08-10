/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * @category @PROJECT_NAME_HUMAN@
 * @package  Controllers
 * @author   @AUTHOR@ <@EMAIL@> 
 * @license  Affero General Public License
 * @link     @PROJECT_WEBSITE@
 */

#include <cppcms/session_interface.h>
#include "Controller.h"
#include "%%CONTROLLER_NAME%%.h"

#include "contents/%%CONTROLLER_NAME%%.h"




namespace controllers {
namespace webs {

%%CONTROLLER_NAME%%::%%CONTROLLER_NAME%%(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{

    //dispatcher().assign("%%ACTION_URL%%", &%%CONTROLLER_NAME%%::%%ACTION%%, this);

}


// %%%NEXT_ACTION_MARKER%%% , do not delete

}



} // End namespace webs
} // End namespace controllers
