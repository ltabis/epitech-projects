/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Picture.hpp"
#include "Toy.hpp"

Test(ex00, Picturetest)
{
    Picture p1;
    Picture p2("alien.txt");
    Picture p3("nope");

    cr_assert_eq(p1.getPicture(), "");
    cr_assert_neq(p2.getPicture(), "ERROR");
    cr_assert_eq(p3.getPicture(), "ERROR");
}

Test(ex00, Toytest)
{
    Toy t1;
    Toy t2(Toy::ALIEN, "Alien dude", "alien.txd");

    cr_assert_eq(t1.getType(), Toy::BASIC_TOY);
    cr_assert_eq(t1.getName(), "toy");
    cr_assert_eq(t1.getAscii(), "");
    cr_assert_eq(t2.getType(), Toy::ALIEN);
    cr_assert_eq(t2.getName(), "Alien dude");
    cr_assert_eq(t2.getAscii(), "ERROR");
}