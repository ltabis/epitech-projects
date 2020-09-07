/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** PhpCgi
*/

#include "PhpCgi.hpp"

extern "C" api::module::AHttp *entryPoint()
{
    return new zia::mod::PhpCgi;
}

zia::mod::PhpCgi::PhpCgi()
{
}

zia::mod::PhpCgi::~PhpCgi()
{
}

bool zia::mod::PhpCgi::handle(api::module::AHttp::Connection &co)
{
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        std::string m = co.req->getUri();
        std::cout << m << std::endl;
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        std::cerr << "fork failed" << std::endl;
    }

    return false;
}

void zia::mod::PhpCgi::setLogger([[maybe_unused]] api::module::ALogger *logger)
{

}

void zia::mod::PhpCgi::setConfig([[maybe_unused]] const api::JsonObject &config)
{

}
