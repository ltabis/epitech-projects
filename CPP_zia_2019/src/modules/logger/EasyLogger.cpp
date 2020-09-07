/**
 *  @file     src/modules/logger/EasyLogger.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "src/Color.hpp"
#include "EasyLogger.hpp"
#include "src/modules/ModuleException.hpp"

zia::mod::EasyLogger::EasyLogger()
{
    _logCallbacks[LEVEL_FATAL] = [this](const api::String &message) {
        displayWithColors("[FatalError]: ", message, RED, std::cerr);
    };
    _logCallbacks[LEVEL_ERROR] = [this](const api::String &message) {
        displayWithColors("[Error]: ", message, YELLOW, std::cerr);
    };
    _logCallbacks[LEVEL_WARNING] = [this](const api::String &message) {
        displayWithColors("[Warning]: ", message, MAGENTA, std::cerr);
    };
    _logCallbacks[LEVEL_INFO] = [this](const api::String &message) {
        displayWithColors("[Info]: ", message, CYAN, std::cout);
    };
    _logCallbacks[LEVEL_DEBUG] = [this](const api::String &message) {
        displayWithColors("[Debug]: ", message, GREEN, std::cout);
    };
}

void zia::mod::EasyLogger::log(const api::String &message, Level level)
{
    _logCallbacks[level](message);
}

void zia::mod::EasyLogger::displayWithColors(const api::String &header,
    const api::String &message, const api::String &color, std::ostream &s)
{
    s << color << header << BLUE << message << RESET << std::endl;
}

void zia::mod::EasyLogger::setConfig(const api::JsonObject &config)
{
    throw ModuleException("Method not yet implemented.");
}