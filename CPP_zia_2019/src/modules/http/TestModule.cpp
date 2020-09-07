/*
** EPITECH PROJECT, 2020
** Zia
** File description:
** A fake module use for testing
*/

#include "TestModule.hpp"

extern "C" api::module::AHttp *entryPoint()
{
    return new zia::mod::TestModule;
}

zia::mod::TestModule::TestModule()
{ }

zia::mod::TestModule::~TestModule()
{ }

bool zia::mod::TestModule::handle(Connection &connection)
{
    (void)connection;

    return false;
}

void zia::mod::TestModule::setLogger(api::module::ALogger *logger)
{
    if (logger == nullptr) {
        Debug::Logger::printDebug(Debug::e_type::ERROR, "No logger are specified", "zia::TestModule::setLogger");
    } else {
        //set logger
    }
}

void zia::mod::TestModule::setConfig(const api::JsonObject &config)
{
    (void)config;
}