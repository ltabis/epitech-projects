/**
 *  @file     src/net/BoostTcpServer.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include <boost/bind.hpp>
#include <utility>
#include "BoostTcpServer.hpp"
#include "NetworkException.hpp"

zia::net::BoostTcpServer::BoostTcpServer()
   : _service(BoostService::get()),
   _acceptor(_service.ioService())
{

}

zia::net::BoostTcpServer::BoostTcpServer::~BoostTcpServer()
{
    stop();
}

void zia::net::BoostTcpServer::stop(void)
{
    try
    {
        _service.stop();
        _acceptor.close();
    }
    catch (const boost::system::system_error &error)
    {
        throw NetworkException(error.what());
    }
}

void zia::net::BoostTcpServer::BoostTcpServer::onNewConnection(
    const std::function<void(std::shared_ptr<api::http::ISocket>)> &registerConnection)
{
    _acceptCallback = registerConnection;
}

void zia::net::BoostTcpServer::BoostTcpServer::listen(const api::Port &port)
{
    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)
    );

    try
    {
        _acceptor.open(endpoint.protocol());
        if (!_acceptor.is_open())
        {
            throw NetworkException(
                "BoostTcpServer has failed to bind to port " + std::to_string(port)
            );
	    }
        _acceptor.set_option(
            boost::asio::ip::tcp::acceptor::reuse_address(true)
        );
        _acceptor.bind(endpoint);
        _acceptor.listen();
        accept();
        _service.run();
    }
    catch (const boost::system::system_error &e)
    {
        throw NetworkException(e.what());
    }
}

void zia::net::BoostTcpServer::accept(void)
{
    std::shared_ptr<BoostTcpSocket> tcpSocket(
        new BoostTcpSocket(_service.ioService()));

	_acceptor.async_accept(tcpSocket->socket(), boost::bind(
		&BoostTcpServer::acceptHandler,
		this, tcpSocket,
        boost::asio::placeholders::error)
    );
}

void zia::net::BoostTcpServer::acceptHandler(
	std::shared_ptr<BoostTcpSocket> tcpSocket,
	const boost::system::error_code &error)
{
  	if (!error)
  	{
        if (!_acceptCallback)
        {
            throw NetworkException("No 'OnNewConnection' callback set!");
        }
        _acceptCallback(tcpSocket);
  	}
    accept();
}