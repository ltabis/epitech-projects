/**
 *  @file     src/modules/network/BoostNetwork.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "BoostNetwork.hpp"
#include "src/http/Response.hpp"
#include "src/http/Request.hpp"
#include "src/modules/ModuleException.hpp"

zia::mod::BoostNetwork::BoostNetwork()
    : _modules({}), _logger(nullptr), _server(), 
    _lockerMutex(), _locker(_lockerMutex),
    _port(defaultPort), _isRunning(true), _modulesAreLocked(false)
{
}

void zia::mod::BoostNetwork::startServing()
{
    //  Set a callbach which allow to start a new thread at each connection.
    _server.onNewConnection([this](std::shared_ptr<api::http::ISocket> socket) {
        
        //  std::launch::async ensures that a new thread is created.
        std::async(std::launch::async, [this](std::shared_ptr<api::http::ISocket> socket) {
            handleNewConnection(socket);
        }, socket);

    });
    _server.listen(_port);
}

void zia::mod::BoostNetwork::handleNewConnection(
    std::shared_ptr<api::http::ISocket> socket)
{
    std::condition_variable var;
    std::unique_ptr<http::Response> response(new http::Response);
    std::unique_ptr<http::Request> request(new http::Request);
    api::module::AHttp::Connection connection {
        request.get(),
        response.get(),
        socket.get()
    };

    while (_isRunning && socket->isOpen())
    {
        while (_modulesAreLocked)
            var.wait(_locker);
        for (auto &module : _modules)
        {  
            if (!module->handle(connection))
            {
                socket->closeSocket();
                break;
            }
        }
        request->clear();
        response->clear();
    }
    if (socket->isOpen())
        socket->closeSocket();
}

void zia::mod::BoostNetwork::stopServing()
{
    _server.stop();
    _isRunning = false;
}

void zia::mod::BoostNetwork::setConfig(const api::JsonObject &config)
{
    throw ModuleException("Method not yet implemented.");
}