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


#ifndef CPPCMS_SKEL_SINGLETON_H
#define CPPCMS_SKEL_SINGLETON_H

#include <iostream>

template <typename T>
class Singleton
{
    protected:
        Singleton () {}
        ~Singleton () {}

    public:
        /**
         * @return a singleton instance, create it if it doesn't exist yet
         */
        static T *get_instance () {
            if (_singleton == NULL) {
                 _singleton = new T;
            }
            return (static_cast<T*> (_singleton));
        }
        
        static T *get_instance (std::string data_path) {
            if (_singleton == NULL) {
                 _singleton = new T(data_path);
            }
            return (static_cast<T*> (_singleton));
        }


        static void kill () {
            if (_singleton != NULL) {
                delete _singleton;
                _singleton = NULL;
            }
        }

    private:
        // Unique instance
        static T *_singleton;
};

template <typename T>
T *Singleton<T>::_singleton = NULL;
#endif
