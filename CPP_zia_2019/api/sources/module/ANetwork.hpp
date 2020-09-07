#ifndef CPP_ZIA_2019_API_MODULE_ANETWORK_HPP
#define CPP_ZIA_2019_API_MODULE_ANETWORK_HPP

#include <functional>
#include "IModule.hpp"
#include "ALogger.hpp"
#include "AHttp.hpp"
#include "../Types.hpp"
#include "../http/ISocket.hpp"

namespace api::module {

    class ANetwork : public IModule {
    public:
        virtual ~ANetwork() override = default;

        Type getType() const final {return IModule::NETWORK;}

        // Start the server into a thread
        // Return true if it succeed, return false if an error occurred (ex: port already in use, server already started, port not authorized)
        virtual bool startServing() = 0;
        // Order to server to stop, wait for total stop to return
        virtual void stopServing() = 0;

        // Return status of the server
        virtual bool isRunning() const = 0;

        // Stop the server if it is running, update list of modules and run the server again if it was running
        virtual void setModules(const std::vector<AHttp *> &modules) = 0;
        // Update the logger
        virtual void setLogger(ALogger *logger) = 0;
    };

}

#endif /* CPP_ZIA_2019_API_MODULE_ANETWORK_HPP */
