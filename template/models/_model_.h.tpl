/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 *
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category @PROJECT_NAME_HUMAN@
 * @author   @AUTHOR@ <@EMAIL@>
 * @package  Models
 *
 */

#ifndef @MAIN_CLASS_HEADER@_%%MODEL_INCLUDE%%
#define @MAIN_CLASS_HEADER@_%%MODEL_INCLUDE%%



#include "cppcms_skel/models/SqliteModel.h"
namespace models {


/**
 * @class %%MODEL_NAME%% %%MODEL_DESCRIPTION%%
 *
 * @since %%MODEL_TODAY%%
 *
 */
class %%MODEL_NAME%% : public cppcmsskel::models::SqliteModel {
    public:
        /**
         * @brief Constructor
         * @since %%MODEL_TODAY%%
         */
        %%MODEL_NAME%%();

};

} // end namespace models

#endif
