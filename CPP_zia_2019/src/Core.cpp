/*
** EPITECH PROJECT, 2020
** Zia
** File description:
** Core
*/

#include "Core.hpp"

zia::Core::Core()
{
    std::filesystem::path path = std::filesystem::current_path();
    if (std::filesystem::exists(CONFIG_FILE_PATH))
    {
        path /= std::filesystem::path(CONFIG_FILE_PATH);
    }
    _configPath = path;
    loadConfig();
}

zia::Core::~Core()
{
}

void zia::Core::start()
{
    loadLibrairies();
}

void zia::Core::setConfig()
{
}

void zia::Core::loadConfig()
{
    // check timestamp of the last config load
    auto currentTimeStamp = std::filesystem::last_write_time(_configPath);
    if (_configTimeStamp != currentTimeStamp) {
        _configTimeStamp = currentTimeStamp;
        // read the config file
        Debug::Logger::printDebug(Debug::e_type::DEBUG, "Load config file", "zia::Core::loadConfig");
        // _configContent = _parser.getData(CONFIG_FILE_PATH);
    }
}

void zia::Core::loadLibrairies(const std::string &directory)
{
    // Clearing all modules.
    _libLoader.clear();
    _httpModules.clear();

    // Getting all modules from a directory
    std::vector<api::module::IModule *> mod = _libLoader.getDirectory<api::module::IModule>(directory);

    for (auto module : mod)
    {
        // Checking if the entry point as been found.
        if (module)
        {
            // module->setConfig(_configContent);
            // Inserting the module in memory.
            insertModuleInMemory(module);
        }
    }
}

void zia::Core::loadLibrairy(const std::string &filepath)
{
    auto module = _libLoader.getInstance<api::module::IModule>(filepath);

    // Inserting the module in memory.
    insertModuleInMemory(module);
}

void zia::Core::insertModuleInMemory(api::module::IModule *module)
{
    if (!module)
        return;

    // Getting the type of the module.
    api::module::IModule::Type type = module->getType();

    // Inserting the module in memory.
    if (type == api::module::IModule::Type::HTTP)
        _httpModules.push_back(static_cast<api::module::AHttp*>(module));
    else if (type == api::module::IModule::Type::LOGGER)
        _logModules.push_back(static_cast<api::module::ALogger*>(module));
    else if (type == api::module::IModule::Type::NETWORK)
        _netModules.push_back(static_cast<api::module::ANetwork*>(module));
}

void zia::Core::dump()
{
    std::cout << "Number of Http modules : " << _httpModules.size() << std::endl;
    std::cout << "Number of Networks modules : " << _netModules.size() << std::endl;
    std::cout << "Number of Loggers modules : " << _logModules.size() << std::endl;
}