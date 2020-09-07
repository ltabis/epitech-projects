#ifndef CPP_ZIA_2019_API_HTTP_IMESSAGE_HPP
#define CPP_ZIA_2019_API_HTTP_IMESSAGE_HPP

#include "../Types.hpp"

namespace api::http {

    class IMessage {
    public:

        virtual ~IMessage() = default;

        // Get Headers as std::unordered_map<std::string, std::string>
        // default: empty
        virtual Headers &getHeaders() = 0;
        virtual const Headers &getHeaders() const = 0;

        // return the body as a vector of byte (char)
        // default: empty
        virtual Buffer &getBody() = 0;
        virtual const Buffer &getBody() const = 0;
        // Set the body as a vector of byte (char)
        virtual void setBody(const Buffer &) = 0;

        // Get HTTP version in format string "HTTP/1.1" (replacing the '1's by version major and minor)
        // default: 1 and 1
        virtual std::string getVersion() const = 0;
        // Set HTTP version
        virtual void setVersion(unsigned char major, unsigned char minor) = 0;

        // Reset the content to default values
        virtual void clear() = 0;
    };

}

#endif /* CPP_ZIA_2019_API_HTTP_IMESSAGE_HPP */
