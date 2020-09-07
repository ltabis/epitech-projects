/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Paladin.hpp"

Test(ex04, Paladin)
{
        Paladin c("palachiasse", 15);

        cr_assert_eq(c.getName(), "palachiasse");
        cr_assert_eq(c.getLvl(), 15);
        cr_assert_eq(c.getPv(), 100);
        cr_assert_eq(c.getPower(), 100);
        cr_assert_eq(c.getStrength(), 9);
        cr_assert_eq(c.getStamina(), 10);
        cr_assert_eq(c.getIntelligence(), 10);
        cr_assert_eq(c.getSpirit(), 10);
        cr_assert_eq(c.getAgility(), 2);
        cr_assert_eq(c.RangeAttack(), 0);
        cr_assert_eq(c.getPower(), 75);
        c.RestorePower();
        cr_assert_eq(c.getPower(), 100);
        cr_assert_eq(c.CloseAttack(), 29);
        cr_assert_eq(c.getPower(), 70);
}
