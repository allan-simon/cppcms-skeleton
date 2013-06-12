/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
 */

#ifndef CPPCMS_SKEL_MODELS_SQLITE_H
#define CPPCMS_SKEL_MODELS_SQLITE_H

#include <cppdb/frontend.h>

namespace cppcmsskel {
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
       
        //TODO
        bool execute_simple(
            cppdb::statement &statement
        );
        
        /**
         * @brief Used with a statement try to check the existence
         *        or not of a given record
         *
         * @param statement The statement to execute
         *
         * @return bool True if the record exists, false otherwise
         *
         * @since 25 April 2012
         */
        bool check_existence(
            cppdb::statement &statement
        );
        
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
         *        FIXME TODO for the moment the import will totally ignore what's
         *        written after the last ';' 
         *
         * @param sqlFilePath The location of the file to import 
         *
         * @return bool True if the file is correctly imported, false otherwise
         */
        bool import_sql_file(
            const std::string &sqlFilePath
        );

};

}
}

#endif
