/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Generics
 *
 */

#include "Config.h"

/**
 *
 */
Config::Config(){}


/**
 *
 */
std::string Config::get_base_host() {
    return get_instance()->baseHost;
}



/**
 *
 */
void Config::set_base_host(const std::string &baseHost) {
    get_instance()->baseHost = baseHost;
}

/**
 *
 */
void Config::set_assets_folder(
    const std::string &assetsFolder
) {
    get_instance()->assetsFolder = assetsFolder;
}

/**
 *
 */
std::string Config::get_assets_folder() {
    return get_instance()->assetsFolder;
}

/**
 *
 */
void Config::set_assets_url(
    const std::string &assetsURL
) {
    get_instance()->assetsURL = assetsURL;
}

/**
 *
 */
std::string Config::get_assets_url() {
    return get_instance()->assetsURL;
}

/**
 *
 */
std::string Config::get_upload_url() {
    return get_instance()->uploadURL;
}

/**
 *
 */
void Config::set_upload_url(
    const std::string &uploadURL
) {
    get_instance()->uploadURL = uploadURL;
}

/**
 *
 */
std::string Config::get_upload_folder() {
    return get_instance()->uploadFolder;
}

/**
 *
 */
void Config::set_upload_folder(
    const std::string &uploadFolder
) {
    get_instance()->uploadFolder = uploadFolder;
}

/**
 *
 */
void Config::set_values(
    cppcms::json::value appConfig
) {


    get_instance()->sqlite3Path = appConfig.get<std::string>(
        "sqlite3.path"
    );

    set_base_host(appConfig.get<std::string>("baseHost"));

    set_assets_url(appConfig.get<std::string>("assetsURL"));
    set_upload_url(appConfig.get<std::string>("uploadURL"));
    //TODO we may check for trailing /
    set_assets_folder(appConfig.get<std::string>("assetsFolder"));
    set_upload_folder(appConfig.get<std::string>("uploadFolder"));


}


