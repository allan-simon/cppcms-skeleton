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


#ifndef CPPCMS_SKEL_MODELS_SQLITE_H
#define CPPCMS_SKEL_MODELS_SQLITE_H

#include <cppdb/frontend.h>


namespace models {

/**
 * @class SqliteModel
 * 
 * @brief base class to represent a model based on
 *        a sqlite database 
 */
class SqliteModel {
    private:
        /**
         * @brief Create the session using the Sqlite3
         *        database provided at the given path
         *
         * @param databasePath Location of the Sqlite3 db
         *
         * @since 3 January 2013
         */
        void create_session(
            const std::string &databasePath
        );

    protected:
        cppdb::session sqliteDb;
    public:
        SqliteModel();

        /**
         * @brief Create a Model based on sqlite3 database
         *
         * @param databasePath The location of the Sqlite3 database
         *
         * @since 3 January 2013
         */
        SqliteModel(const std::string &databasePath);
        SqliteModel(cppdb::session sqliteDb);

        /**
         * @brief Import an SQL file into the database opened by the model
         *
         * @param sqlFilePath The location of the file to import 
         *
         * @return 0 if the file is correctly imported, positive number otherwise
         */
        int import_sql_file(
            const std::string &sqlFilePath
        );
};

}

#endif
