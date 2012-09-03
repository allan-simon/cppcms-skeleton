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
 * @package  Models
 * @author   @AUTHOR@ <@EMAIL@> 
 * @license  Affero General Public License
 * @link     @PROJECT_WEBSITE@
 */


#include <booster/log.h>

#include "models/SqliteModel.h"
#include "generics/Config.h"

namespace models {
SqliteModel::SqliteModel() {
    try {

        sqliteDb = cppdb::session(
            "sqlite3:db=" + Config::get_instance()->sqlite3Path
        );

        // We need this to have triggers call even in some tricky case 
        // (for example "update or replace" that cause a deletion, will not call
        // the delete trigger otherwise)
        sqliteDb.create_statement("PRAGMA recursive_triggers = 1 ;").exec();
    } catch (cppdb::cppdb_error const &e) {

        BOOSTER_ERROR("cppcms") << e.what();
    }

}


SqliteModel::SqliteModel(cppdb::session sqliteDb) : sqliteDb(sqliteDb) {

}

} // end of namespace models
