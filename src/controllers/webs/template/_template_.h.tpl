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

#ifndef CONTROLLERS_WEBS_%%CONTROLLER_INCLUDE%%_H
#define CONTROLLERS_WEBS_%%CONTROLLER_INCLUDE%%_H

#include "Controller.h"


//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the// controller every time we modify a model. even though it does// not affect the controller
namespace models {
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%% 
}

namespace controllers {
namespace webs { 
/**
 * @class %%CONTROLLER_NAME%%
 * @brief %%CONTROLLER_DESCRIPTION%%
 * @since %%CONTROLLER_TODAY%%
 */
class %%CONTROLLER_NAME%% : public Controller {
    public:
        /**
         * @brief Constructor
         * @since %%CONTROLLER_TODAY%%
         */
        %%CONTROLLER_NAME%%(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since %%CONTROLLER_TODAY%%
         */
        ~%%CONTROLLER_NAME%%();

    private:
        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace generics

#endif
