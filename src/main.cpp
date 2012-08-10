/**
 * @PROJECT_NAME_HUMAN@  @DESCRIPTION@
 * Copyright (C) @YEARS@ @AUTHOR@ <@EMAIL@> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * @category @PROJECT_NAME_HUMAN@
 * @package  Main
 * @author   @AUTHOR@ <@EMAIL@> 
 * @license  Affero General Public License
 * @link     @PROJECT_WEBSITE@
 */


#include <iostream>


#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <cppdb/frontend.h>
#include <cppcms/json.h>

#include "@PROJECT_NAME_CODE@.h"

#include "generics/Config.h"

using namespace std;
using namespace cppcms;

int main(int argc,char ** argv)
{
    //TODO send notice message to logs instead of cout

    service app(argc, argv);
    /*load some conf defined variables*/
    Config *conf = Config::get_instance();

    conf->sqlite3Path = app.settings().get<string>(
        "@PROJECT_NAME_CODE@.sqlite3.path"
    );
        
    /*start the graph database*/

    //singletons::ActionId::get_instance();
    /*instantiate the website application*/
    cout << "[NOTICE] website to be launched" << endl;

    //booster::intrusive_ptr<apps::Tatoeba> tatoApp = new apps::Tatoeba(app);

    app.applications_pool().mount(
        cppcms::applications_factory<apps::@MAIN_CLASS@>()
    );
    /*launch it */
    cout << "[NOTICE] website launched" << endl;
    app.run();
    cout << "[NOTICE] website stopped" << endl;

    /*time to destroy all the singletons*/
    //SearchEngine::kill();
    Config::kill();
}

