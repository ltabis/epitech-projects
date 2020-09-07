/**
 *  @file     src/modules/network/BoostNetwork.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include <thread>
#include <future>
#include <mutex>
#include <boost/asio.hpp>
#include "api/sources/module/ANetwork.hpp"
#include "src/net/BoostTcpServer.hpp"

namespace zia::mod {

    constexpr unsigned short defaultPort = 4000;

    /** 
     * @brief A class which implements the ANetwork abstract class.
     * This class is a custom implementation of the network module made with boost 1.71.
     */
    class BoostNetwork : public api::module::ANetwork {
    public:
        /** 
         * @brief BoostNetwork default constructor.
         */
        BoostNetwork();
        /** 
         * @brief BoostNetwork destructor, set by default.
         */
        ~BoostNetwork() final = default;

        /** 
         * @brief Start the server and listen for any connection.
         * Every new connection is handled in a new thread.
         */
        void startServing() final;
        /** 
         * @brief Stop the server and its threads.
         */
        void stopServing() final;


        /*  <-------------------- Setters -------------------->  */

        /** 
         * @brief setModules
         * @return void
         * @param modules : The new modules that the network will use.
         * Existing connections will use these modules from now on.
         */
        inline void setModules(std::vector<api::module::AHttp *> &modules) final
        {
            _modulesAreLocked = true;
            _locker.lock();
            if (!_modules.empty())
            {
                _modules.clear();
            }
            _modules = modules;
            _locker.unlock();
            _modulesAreLocked = false;
        }


        /** 
         * @brief setLogger
         * @return void
         * @param logger : The new logger for each module currently working.
         */
        inline void setLogger(api::module::ALogger *logger) final
        {
            _logger.reset(logger);
            for (auto &module : _modules)
            {
                module->setLogger(logger);
            }
        }


        /** 
         * @brief setConfig
         * @param config : The new config of the network.
         */
        void setConfig(const api::JsonObject &config) final;

    private:
        /** 
         * @brief handleNewConnection
         * @param socket : The socket of the new connection to handle.
         */
        void handleNewConnection(std::shared_ptr<api::http::ISocket> socket);

    private:
        std::vector<api::module::AHttp *> _modules;
        std::shared_ptr<api::module::ALogger> _logger;
        zia::net::BoostTcpServer _server;
        std::mutex _lockerMutex;
        std::unique_lock<std::mutex> _locker;
        api::Port _port;
        bool _isRunning;
        bool _modulesAreLocked;
    };

}