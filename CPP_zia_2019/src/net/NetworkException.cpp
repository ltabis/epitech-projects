/**
 *  @file     src/net/NetworkException.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "NetworkException.hpp"

zia::net::NetworkException::NetworkException(const char *what, const char *where) noexcept
        : Exception(what, where)
{
}

zia::net::NetworkException::NetworkException(std::string what, std::string where) noexcept
        : Exception(std::move(what), std::move(where))
{
}