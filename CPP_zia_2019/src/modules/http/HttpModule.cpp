/**
 *  @file     src/modules/http/HttpModule.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "HttpModule.hpp"
#include "ModuleException.hpp"

zia::mod::HttpModule::HttpModule()
    : _logger(nullptr)
{

}

bool zia::mod::HttpModule::handle(api::module::AHttp::Connection &connection)
{
    (void)connection;

    throw ModuleException("Method not yet implemented.");
}

void zia::mod::HttpModule::setConfig(const api::JsonObject &config)
{
    (void)config;

    throw ModuleException("Method not yet implemented.");
}