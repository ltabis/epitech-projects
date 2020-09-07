/*
** EPITECH PROJECT, 2020
** Zia
** File description:
** Core
*/

#pragma once

#include <filesystem>
#include <chrono>
#include <iostream>
#include <mutex>
#include <list>
#include <string>

#include "Logger.hpp"
#include "LibLoader.hpp"
#include "IModule.hpp"
#include "AHttp.hpp"
#include "ALogger.hpp"
#include "ANetwork.hpp"
#include "ParserJson.hpp"

constexpr auto const CONFIG_FILE_PATH = "example.json";
constexpr auto const LIB_DIRECTORY = "lib";

/// \namespace zia
/// base namespace for zia project
namespace zia
{
    /// \class Core
    /// main element of the zia server
    class Core {

        public:
            /// \brief constructor
            Core();
            /// \brief destructor
            ~Core();

            /// \brief start the server
            void start();

            /// \brief load all available librairies
            void loadLibrairies(const std::string &directory = LIB_DIRECTORY);
            /// \brief load all available librairies
            void loadLibrairy(const std::string &filepath);
            /// \brief display many informations about the core
            void dump();

        private:
            /// \brief load config file
            void loadConfig();
            /// \brief set config using _configContent
            void setConfig();
            /// \brief insert a module in correct container
            void insertModuleInMemory(api::module::IModule* module);

            /*! mutex for config file */
            std::mutex _configMutex;
            /*! config file path */
            std::filesystem::path _configPath;
            /*! last config timestamp */
            std::filesystem::file_time_type _configTimeStamp;
            /*! Parser for json */
            zia::ParserJson _parser;
            /*! content of file config */
            api::JsonType _configContent;
            /*! path for modules storing */
            std::string _modulesPath;
            /*! loader for dynamics lib */
            LibLoader _libLoader;
            /*! Logger modules */
            std::list<api::module::ALogger *> _logModules;
            /*! Http modules */
            std::list<api::module::AHttp *> _httpModules;
            /*! Network modules */
            std::list<api::module::ANetwork *> _netModules;
    };    
}