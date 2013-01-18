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
