#include "LoggerConsole.hpp"
void loadModule();
void unloadModule();
api::module::IModule *getModule();

int main()
{
    loadModule();
    auto logger = dynamic_cast<api::module::ALogger *>(getModule());

    api::JsonObject loggerCfg = api::JsonObject{{L"debug", {false}}};

    logger->setConfig(loggerCfg);

    logger->log("this is a debug message", api::module::ALogger::LEVEL_DEBUG);
    logger->log("this is an info message");
    logger->log("this is an info message too", api::module::ALogger::LEVEL_INFO);
    logger->log("this is a warning message", api::module::ALogger::LEVEL_WARNING);
    logger->log("this is an error message", api::module::ALogger::LEVEL_ERROR);
    logger->log("this is a fatal message", api::module::ALogger::LEVEL_FATAL);
    unloadModule();
    return 0;
}