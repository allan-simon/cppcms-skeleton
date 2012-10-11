/*
 cppcms-skeleton a set of tools and code over cppcms
 Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*/

#include <booster/log.h>

#include "SqliteModel.h"
#include "cppcms_skel/generics/Config.h"


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
