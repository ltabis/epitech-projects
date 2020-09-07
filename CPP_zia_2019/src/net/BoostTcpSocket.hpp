/**
 *  @file     src/net/BoostTcpSocket.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include <boost/asio.hpp>
#include <functional>
#include "api/sources/http/ISocket.hpp"

namespace zia::net {

    constexpr unsigned int bufSize = 4096;

    /** 
     * @brief A class which implements the ISocket interface.
     * This class design a synchronous TCP socket.
     * This is a custom implementation made with the Boost library, version 1.71.
     */
    class BoostTcpSocket : public api::http::ISocket {
    public:
        /** 
         * @brief BoostTcpSocket default deleted constructor.
         */
        BoostTcpSocket() = delete;
        
        /** 
         * @brief BoostTcpSocket constructor sued by default.
         * @param ioService : The service used to create a new TCP socket.
         */
        explicit BoostTcpSocket(boost::asio::io_service &ioService);
        
        /** 
         * @brief BoostTcpSocket destructor, which closes the socket.
         */
        ~BoostTcpSocket() final;

        /** 
         * @brief Send a TCP packet through the network.
         * @param data : 
         */
        void sendPacket(const api::Buffer &data) final;

        /** 
         * @brief Receive a TCP packet from another connection.
         * @return api::Buffer
         */
        api::Buffer recvPacket() final;

        /** 
         * @brief Close properly the socket.
         */
        void closeSocket() final;


        /*  <-------------------- Getters -------------------->  */

        /** 
         * @brief socket
         * @return boost::asio::ip::tcp::socket &
         */
        inline boost::asio::ip::tcp::socket &socket()
        {
            return _socket;
        }

        /** 
         * @brief isOpen
         * @return bool
         */
        inline bool isOpen() const final
        {
            return _socket.is_open();
        }

        /** 
         * @brief getTargetIp
         * @return api::IpV4
         */
        api::IpV4 getTargetIp() const final;


    private:
        boost::asio::ip::tcp::socket _socket;
    };

}
