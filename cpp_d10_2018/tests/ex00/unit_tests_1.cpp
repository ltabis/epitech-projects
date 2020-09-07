/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Peon.hpp"
#include "Sorcerer.hpp"

Test(ex00, Instant)
{
        Sorcerer c("Elian", "CHARO");

        cr_assert_eq(c.getName(), "Elian");
        cr_assert_eq(c.getTitle(), "CHARO");
        std::cout << c << std::endl;
}

Test(ex00, Victim)
{
        Victim c("Popo");

        cr_assert_eq(c.getName(), "Popo");
        std::cout << c << std::endl;
}

Test(ex00, poly)
{
    const Victim v("Popo");
    const Sorcerer s("Elian", "CHARO");

    cr_assert_eq(v.getName(), "Popo");
    cr_assert_eq(s.getName(), "Elian");
    cr_assert_eq(s.getTitle(), "CHARO");
    s.polymorph(v);
}

Test(ex00, peon)
{
    const Peon v("Kyky");

    cr_assert_eq(v.getName(), "Kyky");
    v.getPolymorphed();
}

Test(ex00, maintest)
{
    Sorcerer  robert("Robert", "the  Magnificent");
    Victim  jim("Jimmy");
    Peon  joe("Joe");
    std::cout  << robert  << jim  << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);
}