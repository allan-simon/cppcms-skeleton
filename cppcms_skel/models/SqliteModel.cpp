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

#include <fstream>

#include <booster/log.h>

#include "SqliteModel.h"
#include "cppcms_skel/generics/Config.h"


namespace models {

/**
 *
 */
SqliteModel::SqliteModel() {
    create_session(
        Config::get_instance()->sqlite3Path
    );
}


/**
 *
 */
SqliteModel::SqliteModel(cppdb::session sqliteDb) : sqliteDb(sqliteDb) {

}

/**
 *
 */
SqliteModel::SqliteModel(const std::string &databasePath) {
    create_session(databasePath);
}

/**
 *
 */
void SqliteModel::create_session(
    const std::string &databasePath
) {
    try {

        sqliteDb = cppdb::session(
            "sqlite3:db=" + databasePath
        );
        // We need this to have triggers call even in some tricky case 
        // (for example "update or replace" that cause a deletion, will not call
        // the delete trigger otherwise)
        sqliteDb.create_statement("PRAGMA recursive_triggers = 1 ;").exec();
    } catch (cppdb::cppdb_error const &e) {

        BOOSTER_ERROR("cppcms") << e.what();
    }

}

/**
 *
 */
int SqliteModel::import_sql_file(
    const std::string &sqlFilePath
) {
    try {
        std::ifstream f(sqlFilePath.c_str());
        std::string fileStr(
            (std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>()
        );
        sqliteDb << fileStr << cppdb::exec; 
        size_t current = 0;
        size_t next = -1;
        do
        {
            current = next + 1;
            next = fileStr.find_first_of( ";", current );
            std::string tmpRequest =  fileStr.substr( current, next - current );
            sqliteDb.create_statement(tmpRequest)  << cppdb::exec; 
        } while (next != std::string::npos);


    } catch(std::exception const &e) {
        BOOSTER_ERROR("cppcms") << e.what();
        return 1;
    }
    return 0;
}

} // end of namespace models
