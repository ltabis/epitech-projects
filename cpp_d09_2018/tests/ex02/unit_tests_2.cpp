/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Warrior.hpp"

Test(ex02, warrior)
{
        Warrior c("Elian", 0);

        cr_assert_eq(c.getName(), "Elian");
        cr_assert_eq(c.getLvl(), 0);
        cr_assert_eq(c.getPv(), 100);
        cr_assert_eq(c.getPower(), 100);
        cr_assert_eq(c.getStrength(), 12);
        cr_assert_eq(c.getStamina(), 12);
        cr_assert_eq(c.getIntelligence(), 6);
        cr_assert_eq(c.getSpirit(), 5);
        cr_assert_eq(c.getAgility(), 7);
}
