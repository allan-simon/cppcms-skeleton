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
 * @package  Contents
 * @author   @AUTHOR@ <@EMAIL@> 
 * @license  Affero General Public License
 * @link     @PROJECT_WEBSITE@
 */


#ifndef TATOEBACPP_CONTENTS_%%CONTROLLER_INCLUDE%%_H
#define TATOEBACPP_CONTENTS_%%CONTROLLER_INCLUDE%%_H

#include "cppcms_skel/contents/content.h"

//%%%NEXT_CONTENT_FORM_INCLUDE_MARKER%%%

namespace contents {
namespace %%CONTROLLER_NS%% {

/**
 * @class %%CONTROLLER_NAME%%
 * @brief Base content for every action of %%CONTROLLER_NAME%% controller
 * @since %%CONTROLLER_TODAY%%
 */
struct %%CONTROLLER_NAME%% : public BaseContent {
};

//%%%NEXT_CONTENT_MARKER%%%

} // end of namespace %%CONTROLLER_NS%%
} //end of namespace contents

#endif
