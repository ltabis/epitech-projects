/**
 *  @file     src/http/Response.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "Response.hpp"

zia::http::Response::Response()
    : _headers({}), _body(), _version(), _status(0)
{

}

void zia::http::Response::clear()
{
    _headers.clear();
    _body.clear();
    _version.clear();
}