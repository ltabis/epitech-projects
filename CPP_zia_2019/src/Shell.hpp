/**
 *  @file     src/Shell.hpp
 *  @author   taboutchou on the 2020-02-12
 *  @date     2020-02-12
 * 
 *  project: zia
 * 
 */

#pragma once

#include <unordered_map>
#include <functional>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "IModule.hpp"
#include "Logger.hpp"
#include "Core.hpp"

constexpr auto const DEFAULT_SHELL_PROMPT = "$> ";

namespace zia
{
	class Shell
	{
	public:

        /** 
         * @brief Shell constructor.
         */
        Shell();

        /** 
         * @brief runs the shell.
         */
        void run();

        /** 
         * @brief Add a module to the core.
         * @return true if the operation succeeded, false otherwise.
         * @param filepath : the file path to the desired module. (it must be a dynamic library)
         */
        bool addModule(const std::string &filepath);

        /** 
         * @brief Load a module inside the core. The module must have been loaded beforehand.
         * reload from cach (_handlers).
         * @return true if the operation succeeded, false otherwise.
         * @param name : the name of the module to load.
         */
        bool loadModule(const std::string &name);

        /** 
         * @brief Unload a module from the core but keeping it stored.
         * @return true if the operation succeeded, false otherwise.
         * @param name : the name of the module to unload.
         */
        bool unloadModule(const std::string &name);

        /** 
         * @brief Remove a module from the core.
         * @return true if the operation succeeded, false otherwise.
         * @param name : the name of the module to remove.
         */
        bool removeModule(const std::string &name);

        /** 
         * @brief Display data of all modules inside the module chain.
         */
        void displayModuleChain();

        /** 
         * @brief Re-compile all modules and reloading the ones needed.
         * Is this realy useful.
         */
        void refreshModuleFolder();
    
        /** 
         * @brief Set the debug active.
         * @param state : the state of the debug mode.
         */
        void setDebug(bool state);

    private:


        /** 
         * @brief Parse the command given by the user.
         * @return a vector of string, the command without useless characters.
         * @param command : the input of the user.
         */
        std::vector<std::string> parseCommand(const std::string &command);

        /** 
         * @brief Quit the terminal.
         * @param command : the input of the user.
         */
        void exit(const std::vector<std::string> &command);

        /** 
         * @brief Display a message with all commands.
         * @param command : the input of the user.
         */
        void help(const std::vector<std::string>& command);
        /**
         * @brief Set the debug state.
         * @param command : the input of the user.
         */
        void debug(const std::vector<std::string>& command);
        /**
         * @brief Loads all dynamic libraries from a directory.
         * @param command : the input of the user.
         */
        void loadDirectory(const std::vector<std::string>& command);
        /**
         * @brief Loads a dynamic library.
         * @param command : the input of the user.
         */
        void load(const std::vector<std::string>& command);

        /*! All commands from the shell are stored inside this map */
        std::unordered_map<std::string, void (Shell::*)(const std::vector<std::string> &)> _commands;

        /*! Is the shell still running ? */
        bool _isRunning;

        /*! Core of the server. */
        Core _core;
	};
}