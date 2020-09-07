/*
** EPITECH PROJECT, 2020
** CPP_zia_2019
** File description:
** PhpCgi
*/

#ifndef PHPCGI_HPP_
#define PHPCGI_HPP_

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "AHttp.hpp"
#include "ALogger.hpp"

namespace zia::mod
{
    class PhpCgi : public api::module::AHttp
    {
    public:
        PhpCgi();
        ~PhpCgi();

        bool handle(api::module::AHttp::Connection &);
        void setLogger(api::module::ALogger *);
        void setConfig(const api::JsonObject &);

    private:
    };
}

#endif /* !PHPCGI_HPP_ */
