/**
 *  @file     src/http/Request.cpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#include "Request.hpp"

zia::http::Request::Request()
    : _headers({}), _body(), _version(), _method(), _uri()
{

}

void zia::http::Request::clear()
{
    _headers.clear();
    _body.clear();
    _version.clear();
    _method.clear();
    _uri.clear();
}