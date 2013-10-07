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
#include <iostream>
#include <string>
#include <booster/log.h>
#include "SqlImporter.h"

namespace cppcmsskel {
namespace models {

/**
 *
 */
SqlImporter::SqlImporter(cppdb::session sqliteDbParam):
    currentPosition(0),
    sqliteDb(sqliteDbParam)
{

}

/**
 *
 */
bool SqlImporter::from_file(
    const std::string &sqlFilePath
) {

    std::ifstream f(sqlFilePath.c_str());
    std::string fileStr(
        (std::istreambuf_iterator<char>(f)),
        std::istreambuf_iterator<char>()
    );

    return from_string(fileStr);
}


/**
 *
 */
bool SqlImporter::from_string(
    const std::string &sqlStringParam
) {
    sqlString = sqlStringParam;

    try {
        
        // TODO we will ignore what's after the last ;  ,  or everything
        // if there's no  ;  that's a workaround because for the moment 
        // create_statement ... << exec will launch a "no error" exception
        // if you give it an empty string
        // 
        while (next_sql_block() != std::string::npos) {
            // we split the string 
            
            std::cout << "*****begin******" << std::endl;
            std::cout << currentFragment << std::endl;
            std::cout << "*******end****" << std::endl;
            sqliteDb.create_statement(currentFragment)  << cppdb::exec; 

        } 


    } catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
        BOOSTER_ERROR("cppcms") << e.what();
        return false;
    }
    return true;
}

/**
 *
 */
size_t SqlImporter::next_sql_block() {
    // we first get the position of the next ";"
    size_t next = sqlString.find( ";", currentPosition );
    // we split the string 
    currentFragment =  sqlString.substr(
        currentPosition,
        next - currentPosition
    );

    if (!contains_trigger_begin(currentFragment)) {
        currentPosition = next + 1;
        return next;
    }

    next = find_trigger_end();
    if (next != std::string::npos) {
        currentFragment = sqlString.substr(
            currentPosition,
            next - currentPosition
        );

        currentPosition = next + 1;
    }


    return next;



}

/**
 *
 */
bool SqlImporter::contains_trigger_begin(
    const std::string &sqlFragment 
) {

    // we don't handle the case in which somebody has written
    // cReATe
    // if necessary it can be easily implemented by doing a
    // "to_lower" on sqlFragment
    if (sqlFragment.find("create") == std::string::npos) {
        if (sqlFragment.find("CREATE") == std::string::npos) {
            return false;
        }
    }
    if (sqlFragment.find("trigger") == std::string::npos) {
        if (sqlFragment.find("TRIGGER") == std::string::npos) {
            return false;
        }
    }

    return true;

}

/**
 *
 */
size_t SqlImporter::find_trigger_end() {

    // we first look for end/END   
    size_t next = sqlString.find( "end", currentPosition );
    if (next == std::string::npos) {
        next = sqlString.find( "END", currentPosition );
        if (next == std::string::npos) {
            return next;
        }
    }

    // if we find it we look for the next  ';'

    return sqlString.find( ";", next);

}




} // end namespace models
} // end namespace cppcmsskel 




