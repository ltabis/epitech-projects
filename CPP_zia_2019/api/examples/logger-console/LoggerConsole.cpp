#include <iostream>
#include <ctime>
#include <iomanip>
#include "LoggerConsole.hpp"

// put extern "C" if it is in a dynamic library
//extern "C" {
    api::module::ALogger *logger = nullptr;

    void loadModule() {
        delete logger;
        logger = new LoggerConsole();
    }

    void unloadModule() {
        delete logger;
        logger = nullptr;
    }

    api::module::IModule *getModule() {
        return logger;
    }
//}

LoggerConsole::LoggerConsole()
    : _debug(true)
{}

void LoggerConsole::setConfig(const api::JsonObject &config)
{
    try {
        _debug = config.at(L"debug").as<api::JsonBool>();
    } catch (...) {
        _debug = true;
    }
}

void LoggerConsole::log(const api::String &message, api::module::ALogger::Level lvl)
{
    switch (lvl) {
        case LEVEL_FATAL:
            print(std::cerr, message, "\033[1;31m");
            //abort();
            break;
        case LEVEL_ERROR:
            print(std::cerr, message, "\033[0;31m");
            break;
        case LEVEL_WARNING:
            print(std::cout, message, "\033[0;33m");
            break;
        case LEVEL_INFO:
            print(std::cout, message, "\033[0;34m");
            break;
        case LEVEL_DEBUG:
            if (_debug)
                print(std::cout, message, "");
            break;
        default:
            print(std::cout, message, "");
    }
}

void LoggerConsole::print(std::ostream &stream, const api::String &message, const api::String &color)
{
    std::time_t result = std::time(nullptr);

    stream << color << std::put_time(std::localtime(&result), "%F %T") << " " << message << "\033[0m" << std::endl;
}