#ifndef CPP_ZIA_2019_API_HTTP_IREQUEST_HPP
#define CPP_ZIA_2019_API_HTTP_IREQUEST_HPP

#include "../Types.hpp"
#include "IMessage.hpp"

namespace api::http {

    class IRequest : public IMessage {
    public:
        virtual ~IRequest() override = default;

        // Get the method as a std::string
        // default: empty
        virtual String getMethod() const = 0;
        // Set method as a std::string
        virtual void setMethod(const String &method) = 0;

        // Get the uri as a std::string (ex: "/home/index.html")
        // default: empty
        virtual String getUri() const = 0;
        // Set the uri as a std::string
        virtual void setUri(const String &uri) = 0;
    };

}

#endif /* CPP_ZIA_2019_API_HTTP_IREQUEST_HPP */
