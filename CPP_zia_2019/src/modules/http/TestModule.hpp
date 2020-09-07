/*
** EPITECH PROJECT, 2020
** Zia
** File description:
** A fake module use for testing
*/

#pragma once

#include <iostream>

#include "AHttp.hpp"
#include "ALogger.hpp"
#include "Logger.hpp"

namespace zia::mod
{
    class TestModule : public api::module::AHttp {
        public:
            TestModule();
            ~TestModule();

            bool handle(Connection &connection);

            void setLogger(api::module::ALogger *logger);
            void setConfig(const api::JsonObject &config);
    };

}