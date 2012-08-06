/**
 * @PROJECT_NAME_HUMAN@  free collaborative creation of multilingual corpuses project
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
 * @link     http://tatoeba.org
 */


#ifndef TATOEBACPP_CONTENTS_PAGES_H
#define TATOEBACPP_CONTENTS_PAGES_H

#include "contents/content.h"

namespace contents {
namespace pages {

/**
 * Base content for every action of Pages controller
 *
 */
struct Pages : public BaseContent {
};

/**
 * @struct Homepage
 * Content used by the homepage
 */
struct Homepage : public Pages {

    Homepage() {
    }

};


} // end of namespace pages
} //end of namespace contents

#endif
