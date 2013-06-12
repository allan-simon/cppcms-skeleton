/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 *
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category @PROJECT_NAME_HUMAN@
 * @author   @AUTHOR@ <@EMAIL@> 
 * @package  Contents
 *
 */

#ifndef @MAIN_CLASS_HEADER@_CONTENTS_%%CONTROLLER_INCLUDE%%_H
#define @MAIN_CLASS_HEADER@_CONTENTS_%%CONTROLLER_INCLUDE%%_H

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
