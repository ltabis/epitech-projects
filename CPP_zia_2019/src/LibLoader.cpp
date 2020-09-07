//
// EPITECH PROJECT, 2020
// Zia
// File description:
// class for lib loader
//

#include <iostream>
#include "LibLoader.hpp"

zia::LibLoader::~LibLoader()
{
    clear();
}

#if WIN32

void zia::LibLoader::clear()
{
    // Terminating all handlers.
    for (auto& it : _loadedLib)
        FreeLibrary((HMODULE)it.second);

    // Clearing the container.
    _loadedLib.clear();
}

#else

void zia::LibLoader::clear()
{
    for (auto &it : _loadedLib)
        dlclose(it.second);
    _loadedLib.clear();    
}

void *zia::LibLoader::loadLibrarie(const std::string &file)
{
    void *lib_ptr = nullptr;

    // Opening the dynamic library
    lib_ptr = dlopen(file.c_str(), RTLD_LAZY);

    // Checking if it has been loaded correctly.
    if (lib_ptr == nullptr)
        Debug::Logger::printDebug(Debug::e_type::ERROR, dlerror(), "zia::Libloader");

    return (lib_ptr);
}

#endif
