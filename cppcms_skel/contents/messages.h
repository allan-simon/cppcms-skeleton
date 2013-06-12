/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Contents
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
            cppcms::archive_traits<std::vector<Message> >::save(*this,archive);
        } else {
            cppcms::archive_traits<std::vector<Message> >::load(*this,archive);
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


