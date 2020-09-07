#ifndef CPP_ZIA_2019_API_MODULE_AHTTP_HPP
#define CPP_ZIA_2019_API_MODULE_AHTTP_HPP

#include "IModule.hpp"
#include "ALogger.hpp"
#include "../Types.hpp"
#include "../http/IRequest.hpp"
#include "../http/IResponse.hpp"
#include "../http/ISocket.hpp"

namespace api::module {

    class AHttp : public IModule {
    public:
        struct Connection {
            http::IRequest *req;
            http::IResponse *res;
            http::ISocket *socket;
        };

        virtual ~AHttp() override = default;

        Type getType() const final { return IModule::HTTP; }

        // Handle a client connection and do stuff with the request and/or the response and/or the socket
        virtual bool handle(Connection &connection) = 0;

        // Update the logger
        virtual void setLogger(ALogger *logger) = 0;
    };

}

#endif /* CPP_ZIA_2019_API_MODULE_AHTTP_HPP */
