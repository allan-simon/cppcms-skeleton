/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall
 * be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Singletons
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
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
void Config::set_inner_css_folder(
    const std::string &cssFolder
) {
    get_instance()->innerCssFolder = cssFolder;
}

/**
 *
 */
std::string Config::get_inner_css_folder() {
    return get_instance()->innerCssFolder;
}


/**
 *
 */
void Config::set_inner_img_folder(
    const std::string &imgFolder
) {
    get_instance()->innerImgFolder = imgFolder;
}

/**
 *
 */
std::string Config::get_inner_img_folder() {
    return get_instance()->innerImgFolder;
}

/**
 *
 */
void Config::set_inner_js_folder(
    const std::string &jsFolder
) {
    get_instance()->innerJsFolder = jsFolder;
}

/**
 *
 */
std::string Config::get_inner_js_folder() {
    return get_instance()->innerJsFolder;
}





/**
 *
 */
void Config::set_css_path(
    const std::string &cssPath
) {
    get_instance()->cssPath = cssPath;
}

/**
 *
 */
std::string Config::get_css_path() {
    return get_instance()->cssPath;
}

/**
 *
 */
void Config::set_img_path(
    const std::string &imgPath
) {
    get_instance()->imgPath = imgPath;
}

/**
 *
 */
std::string Config::get_img_path() {
    return get_instance()->imgPath;
}


/**
 *
 */
void Config::set_js_path(
    const std::string &jsPath
) {
    get_instance()->jsPath = jsPath;
}

/**
 *
 */
std::string Config::get_js_path() {
    return get_instance()->jsPath;
}

/**
 *
 */
std::string Config::get_upload_url() {
    return get_instance()->uploadUrl;
}

/**
 *
 */
void Config::set_upload_url(
    const std::string &uploadUrl
) {
    get_instance()->uploadUrl = uploadUrl;
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

    set_css_path(appConfig.get<std::string>("cssPath"));
    set_img_path(appConfig.get<std::string>("imgPath"));
    set_js_path(appConfig.get<std::string>("jsPath"));
    set_upload_url(appConfig.get<std::string>("uploadUrl"));

    //TODO we may check for trailing /
    set_inner_css_folder(appConfig.get<std::string>("innerCssFolder"));
    set_inner_img_folder(appConfig.get<std::string>("innerImgFolder"));
    set_inner_js_folder(appConfig.get<std::string>("innerJsFolder"));
    set_upload_folder(appConfig.get<std::string>("uploadFolder"));


}


