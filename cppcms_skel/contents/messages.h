/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
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
 * @package  Contents
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
 *
 */


#ifndef CPPCMS_SKEL_CONTENTS_MESSAGES_H
#define CPPCMS_SKEL_CONTENTS_MESSAGES_H

#include <string>
#include <vector>

#include <cppcms/serialization.h>
#include <cppcms/serialization_classes.h>

#define CPPCMS_SKEL_MESSAGE_ERROR "error"
#define CPPCMS_SKEL_MESSAGE_INFO "info"
#define CPPCMS_SKEL_MESSAGE_SUCCESS "success"
#define CPPCMS_SKEL_MESSAGE_WARNING "warning"

namespace contents {

/**
 * @strut Message Represent a message to send to the user
 *
 * @since 3 June 2013
 */
struct Message : public cppcms::serializable {
    /**
     * @brief text The text of the message itsell 
     *
     * @since 3 June 2013
     */
    std::string text;

    /**
     * @brief type Which kind of message it is (warning, success message etc.)
     *
     * @since 3 June 2013
     */
    std::string type;
 
    /**
     * @brief Permits to serialize this structure
     *
     * @param archive The archive in which the Messsage will be serialize
     *
     * @since 3 June 2013
     */
    void serialize(cppcms::archive &archive) {  
        archive & text & type;
    }  

   
    /**
     * @brief Constructor
     *
     * @since 3 June 2013
     */
    Message(
        const std::string &textParam = "",
        const std::string &typeParam = ""
    ) :
        text(textParam),
        type(typeParam)
    {
    }
};

struct Messages : public std::vector<Message> , public cppcms::serializable {

    public: 
    void serialize(cppcms::archive &archive) {  
        std::cout << "in serialize" << std::endl;
        if (archive.mode() == cppcms::archive::save_to_archive) {
            cppcms::archive_traits<std::vector<Message>>::save(*this,archive);
        } else {
            cppcms::archive_traits<std::vector<Message>>::load(*this,archive);
        }
    }  



};


//typedef std::vector<Message> Messages;

}

//namespace cppcms {
//    template<>
//    struct serialization_traits<::contents::Message> {
//  
//      void load(std::string const &serialized_object,point &real_object)
//      {
//           std::stringstream ss(serialized_object);
//           ss >> real_object.text >> real_object.type;
//         }
//         void save(point const &real_object,std::string &serialized_object)
//         {
//           std::stringstream ss;
//           ss << real_object.x << ' ' << real_object.;
//           serialized_object = ss.str();
//         }
//    };
//} // cppcms
//

#endif


