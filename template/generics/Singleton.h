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
