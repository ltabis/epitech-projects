/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Parser.hpp"

Test(ex00, simple_calc)
{
    Parser p;
    p.feed("((12 * 2) + 14)");
    cr_assert_eq(p.result(), 38);
    p.feed("((17 % 9) / 4)");
    cr_assert_eq(p.result(), 40);
    p.reset();
    p.feed("(17 - 4) * 13");
    cr_assert_eq(p.result(), 169);
}

Test(ex00, advanced_calc)
{
    Parser p;
    p.feed("((15 + (12 * 2)) + 14)");
    cr_assert_eq(p.result(), 53);
}

Test(ex00, advanced_calc_add)
{
    Parser p;
    p.feed("((2 - (12 * 2)) + 14)");
    cr_assert_eq(p.result(), -8);
    p.feed("8 / 2");
    cr_assert_eq(p.result(), -4);
}