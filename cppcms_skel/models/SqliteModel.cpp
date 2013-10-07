/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
 */

#include <fstream>

#include <booster/log.h>
#include "cppcms_skel/generics/Config.h"

#include "SqliteModel.h"
#include "SqlImporter.h"


namespace cppcmsskel {
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
SqliteModel::SqliteModel(cppdb::session sqliteDbParam) : sqliteDb(sqliteDbParam) {

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
bool SqliteModel::import_sql_file(
    const std::string &sqlFilePath
) {

    SqlImporter importer(sqliteDb);
    return importer.from_file(sqlFilePath);

}

/**
 *
 */
bool SqliteModel::execute_simple(
    cppdb::statement &statement
) {
    try {
        statement.exec();
    } catch (cppdb::cppdb_error const& e) {
        BOOSTER_ERROR("cppcms") << e.what();
        statement.reset();
        return false;
    }
    statement.reset();
    return true;
}


/**
 *
 */
bool SqliteModel::check_existence(
    cppdb::statement &statement
) {
    cppdb::result res = statement.row();
    int checkresult = 0;
    res.fetch(0,checkresult);

    // Don't forget to reset statement
    statement.reset();

    if (checkresult == 1 ) {
        return true;
    }
    return false;
}

} // end of namespace models
} // end namespace cppcmsskel
