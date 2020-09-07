#ifndef CPP_ZIA_2019_API_HTTP_IRESPONSE_HPP
#define CPP_ZIA_2019_API_HTTP_IRESPONSE_HPP

#include "../Types.hpp"
#include "IMessage.hpp"

namespace api::http {

    class IResponse : public IMessage {
    public:
        virtual ~IResponse() override = default;

        // Get HTTP status
        // default: 200
        virtual int getStatus() const = 0;
        // Set HTTP status
        virtual void setStatus(int status) = 0;
    };

}

#endif /* CPP_ZIA_2019_API_HTTP_IRESPONSE_HPP */
