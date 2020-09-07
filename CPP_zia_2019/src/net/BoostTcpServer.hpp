/**
 *  @file     src/net/BoostTcpServer.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include <boost/asio.hpp>
#include "BoostTcpSocket.hpp"
#include "BoostService.hpp"

namespace zia::net {

    /** 
     * @brief A custom TCP server. The accept is asynchronous.
     * This is made with the Boost library, version 1.71.
     */
    class BoostTcpServer {
    public:
        /** 
         * @brief BoostTcpServer default constructor.
         */
        BoostTcpServer();
        /** 
         * @brief BoostTcpServer destructor, which stops the server.
         */
        ~BoostTcpServer();

        /** 
         * @brief Stop the server.
         */
        void stop();
        
        /** 
         * @brief Listen for any connection.
         * @param port : 
         */
        void listen(const api::Port &port);

        /** 
         * @brief Set a which will be called when a new connection is accepted.
         * This method must absolutely be called before the listen one.
         * @param callback : The callback to use, which is stocked inside the class.
         */
        void onNewConnection(
            const std::function<void(std::shared_ptr<api::http::ISocket>)> &callback);

    private:
        /** 
         * @brief Accept asynchronously TCP connections.
         */
        void accept();
        
        /** 
         * @brief A callback of the accept method, called at each new connection.
         * If no error is detected, the appropriated callback previously set is called.
         * If no callback was set, a NetworkException is throw.
         * @param tcpSocket : The socket accepted.
         * @param error : The potential error if accept has failed.
         */
        void acceptHandler(std::shared_ptr<BoostTcpSocket> tcpSocket,
            const boost::system::error_code &error);

    private:
        std::function<void(std::shared_ptr<api::http::ISocket>)> _acceptCallback;
        BoostService &_service;
        boost::asio::ip::tcp::acceptor _acceptor;
    };

}
