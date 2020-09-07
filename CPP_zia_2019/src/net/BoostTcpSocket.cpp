/**
 *  @file     src/net/BoostTcpSocket.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "BoostTcpSocket.hpp"
#include "NetworkException.hpp"

zia::net::BoostTcpSocket::BoostTcpSocket(boost::asio::io_service &ioService)
    : _socket(ioService)
{
}

api::IpV4 zia::net::BoostTcpSocket::getTargetIp() const
{
    try
    {
        auto endpoint = _socket.remote_endpoint();
        auto address = endpoint.address();
        auto ipv4 = address.to_v4();

        return ipv4.to_uint();
    }
    catch(const boost::system::system_error& e)
    {
        throw NetworkException(e.what());
    }
}

void zia::net::BoostTcpSocket::closeSocket()
{
    try
    {
        if (_socket.is_open())
        {
            _socket.close();
        }
    }
    catch (const boost::system::system_error &e)
    {
        throw NetworkException(e.what());
    }
}

api::Buffer zia::net::BoostTcpSocket::recvPacket()
{
    boost::system::error_code error;
    std::array<char, bufSize> buffer = {0};
    auto size = _socket.read_some(boost::asio::buffer(
                        buffer, sizeof(buffer)), error);

    return api::Buffer(buffer.begin(), buffer.end());
}


void zia::net::BoostTcpSocket::sendPacket(const api::Buffer &data)
{
    try
    {
        _socket.send(boost::asio::buffer(data));
    }
    catch (const boost::system::system_error &e)
    {
        throw NetworkException(e.what());
    }
}

zia::net::BoostTcpSocket::~BoostTcpSocket()
{
    closeSocket();
}
