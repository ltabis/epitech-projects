#include "Shell.hpp"

zia::Shell::Shell() : _isRunning(true)
{
    // Adding commands for the shell module.                                                         
    _commands.emplace("exit", &Shell::exit);
    _commands.emplace("quit", &Shell::exit);
    _commands.emplace("help", &Shell::help);
    _commands.emplace("debug", &Shell::debug);
    _commands.emplace("loadDir", &Shell::loadDirectory);
    _commands.emplace("load", &Shell::load);
}

void zia::Shell::run()
{
    std::string input;

    while (_isRunning)
    {
        // Displaying the prompt and getting the input from the user.                                
        std::cout << DEFAULT_SHELL_PROMPT;
        std::getline(std::cin, input);

        // Getting commands                                                                          
        auto command_parameters = parseCommand(input);

        // Checking if the command exists.
        if (!command_parameters.empty() && _commands.find(command_parameters.front()) != _commands.end())
            (this->*_commands[command_parameters.front()])(command_parameters);
        else
        {
            Debug::Logger::printDebug(Debug::WARNING, "Error: command `" + (!command_parameters.empty() ? command_parameters.front() : "") + "` not found.", "zia::Shell::run");
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

std::vector<std::string> zia::Shell::parseCommand(const std::string &command)
{
    std::vector<std::string> split;
    std::size_t idx = 0;

    // Skipping first non-command characters.                                                        
    for (; !command.empty() && command[idx] <= ' '; ++idx);

    // Getting command arguments.                                                                    
    for (std::size_t start = idx; command[idx]; ++idx)
    {
        for (; command[idx] > ' '; ++idx);

        // Getting the command.                                                                      
        auto tmp = command.substr(start, idx - start);

        // Pushing it back to our vector.                                                            
        split.push_back(tmp);

        // Skipping non-command characters.
        for (; command[idx] && command[idx] <= ' '; ++idx);
        start = idx--;
    }

    return split;
}

void zia::Shell::exit(const std::vector<std::string> &command)
{
    (void) command;

    // Stopping the server.                                                                          
    _isRunning = false;
}

void zia::Shell::help(const std::vector<std::string> &command)
{
    (void) command;

    // Displaying help.
    std::cout << "Available commands:" << std::endl << std::endl;
    std::cout << "-> help                    Display this help." << std::endl;
    std::cout << "-> exit | quit             Shutdown the server." << std::endl;
    std::cout << "-> debug on | off          Set the debug on & off." << std::endl << std::endl;
    std::cout << "-> loadDir <dir>           Open and load all modules in the given directory. (.so/.dll)" << std::endl;
    std::cout << "-> load    <module>        Open and load a module. (.so/.dll)" << std::endl;
    //std::cout << "-> unload  <module>        unload a module. (.so/.dll)" << std::endl;
    //std::cout << "-> remove  <module>        Open and load all modules in the given directory. (.so/.dll)" << std::endl;
}

void zia::Shell::debug(const std::vector<std::string>& command)
{
    if (command.size() == 2)
    {
        if (command.at(1) == "true" || command.at(1) == "on")
        {
            // Turning on the Logger.
            Debug::Logger::switchMode(Debug::STANDARD);
            Debug::Logger::printDebug(Debug::INFO, "The debug mode is on.", "zia::Shell::debug");
        }
        else if (command.at(1) == "false" || command.at(1) == "off")
        {
            // Bad practice. There shouldn't need a sleep needed.
            Debug::Logger::printDebug(Debug::INFO, "Turning off the debug mode.", "zia::Shell::debug");
            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            // Turning off the Logger.
            Debug::Logger::switchMode(Debug::OFF);
        }
    }
}

void zia::Shell::loadDirectory(const std::vector<std::string>& command)
{
    if (command.size() == 2)
    {
        _core.loadLibrairies(command.at(1));
    }
}

void zia::Shell::load(const std::vector<std::string> &command)
{
    if (command.size() == 2)
    {
        _core.loadLibrairy(command.at(1));
    }
}
