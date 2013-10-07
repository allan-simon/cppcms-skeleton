/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
 */

#ifndef CPPCMS_SKEL_MODELS_IMPORTER_H
#define CPPCMS_SKEL_MODELS_IMPORTER_H

#include <cppdb/frontend.h>

namespace cppcmsskel {
namespace models {

/**
 * @class SqlImporter Class used to import sql statements from the outside
 *                    into the local database
 * @since 7 October 2013
 */
class SqlImporter {

    private:
        /**
         * @brief position of the cursor in the Sql string to import
         * @since 7 October 2013
         */
        size_t currentPosition;
        /**
         * @brief string containing the sql statements to analyze and import
         * @since 7 October 2013
         */
        std::string sqlString;

        /**
         * @brief Current part (or complete sql statements) being analyzed
         *        note: it's not supposed to contain more than one complete
         *        SQL block at a time
         * @since 7 October 2013
         */
        std::string currentFragment;


        
    protected:
        cppdb::session sqliteDb;

       /**
         * @brief it will find the next sql block and update the internal
         *        currentFragment and currentPosition, so that several
         *        successive call will go trough the string 
         * @return The position just after the end of the next block or 
         *         std::string::npos if there's no next block
         * @since 7 October 2013
         */
        size_t next_sql_block();

        /**
         * Check if the block we're currently analyzing contains or not
         * the beginning of a trigger block
         *
         * @return True if it contains the beginning of a trigger block
         *         false otherwise
         *
         * @since 7 October 2013
         */
        bool contains_trigger_begin(
            const std::string &sqlFragment 
        );

        /**
         * It will try to find the position of the end of the trigger block
         *
         * @return The position of the end of the trigger block if there's one
         *         if not, std::string::npos is returned
         * @since 7 October 2013
         */
        size_t find_trigger_end();
    public:
        /**
         * Constructor
         * @since 7 October 2013
         */
        SqlImporter(cppdb::session sqliteDb);

       /**
         * @brief Import a local file's content into the current database
         *
         * @param sqlFilePath Path to the file to import
         * @return True if the import has succeed, false if it has fails
         *         it may fail if the file contains sql mistakes
         *         Note: right now there's no "rollback" mechanism included in
         *         this function if it fails at some points. i.e the previous
         *         statements may still be there
         *
         * @since 7 October 2013
         *
         */
        bool from_file(
            const std::string &sqlFilePath
        );

        /**
         * Import a string into the current database
         *
         * @param sqlString A string containing a list of SQL statements
         *                  to try to import
         *
         * @return True if the import has succeed, false if it has fails
         *         it may fail if the file contains sql mistakes
         *         Note: right now there's no "rollback" mechanism included in
         *         this function if it fails at some points. i.e the previous
         *         statements may still be there
         * @since 7 October 2013
         */
        bool from_string(
            const std::string &sqlString
        );
};

} // end namespace models
} // end namespace cppcmsskel 

#endif
