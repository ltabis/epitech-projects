/**
 *  @file     src/Exception.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "Exception.hpp"

zia::Exception::Exception(const char *what, const char *where) noexcept
        : _what(what), _where(where)
{
}

zia::Exception::Exception(std::string what, std::string where) noexcept
        : _what(std::move(what)), _where(std::move(where))
{
}