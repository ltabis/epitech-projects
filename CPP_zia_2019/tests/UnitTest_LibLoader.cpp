/*
** EPITECH PROJECT, 2020
** Zia
** File description:
** Test for loadLib object
*/

#include <gtest/gtest.h>

#include "LibLoader.hpp"
#include "AHttp.hpp"

TEST(LibLoader, getInstance)
{
    zia::LibLoader l;

    auto unknowMod = l.getInstance<api::module::AHttp>("toto.so");
    auto falseExtension = l.getInstance<api::module::AHttp>("libtestModule.sa");
    auto mod = l.getInstance<api::module::AHttp>("libtestModule.so");

    ASSERT_EQ(unknowMod, nullptr);
    ASSERT_EQ(falseExtension, nullptr);
    ASSERT_NE(mod, nullptr);
}

TEST(LibLoader, getDirectory)
{
    zia::LibLoader l;

    auto unknowDirectory = l.getDirectory<api::module::AHttp>("badDirectory");
    auto mod = l.getDirectory<api::module::AHttp>("lib");

    ASSERT_EQ(unknowDirectory.size(), 0);
    ASSERT_NE(mod.size(), 0);
}
