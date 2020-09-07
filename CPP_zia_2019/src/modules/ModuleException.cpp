/**
 *  @file     src/modules/ModuleException.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */


#include "ModuleException.hpp"

zia::mod::ModuleException::ModuleException(const char *what, const char *where) noexcept
        : Exception(what, where)
{
}

zia::mod::ModuleException::ModuleException(std::string what, std::string where) noexcept
        : Exception(std::move(what), std::move(where))
{
}