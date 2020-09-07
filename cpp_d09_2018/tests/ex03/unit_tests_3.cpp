/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Mage.hpp"

Test(ex03, Mage)
{
        Mage c("Elian", 0);

        cr_assert_eq(c.getName(), "Elian");
        cr_assert_eq(c.getLvl(), 0);
        cr_assert_eq(c.getPv(), 100);
        cr_assert_eq(c.getPower(), 100);
        cr_assert_eq(c.getStrength(), 6);
        cr_assert_eq(c.getStamina(), 6);
        cr_assert_eq(c.getIntelligence(), 12);
        cr_assert_eq(c.getSpirit(), 11);
        cr_assert_eq(c.getAgility(), 7);
}

Test(ex03, Mage_2)
{
        Mage c("Lance-merde", 15);

        cr_assert_eq(c.getName(), "Lance-merde");
        cr_assert_eq(c.getLvl(), 15);
        cr_assert_eq(c.getPv(), 100);
        cr_assert_eq(c.getPower(), 100);
        cr_assert_eq(c.getStrength(), 6);
        cr_assert_eq(c.getStamina(), 6);
        cr_assert_eq(c.getIntelligence(), 12);
        cr_assert_eq(c.getSpirit(), 11);
        cr_assert_eq(c.getAgility(), 7);
        cr_assert_eq(c.RangeAttack(), 0);
        cr_assert_eq(c.getPower(), 75);
        c.RestorePower();
        cr_assert_eq(c.getPower(), 100);
        cr_assert_eq(c.CloseAttack(), 31);
        cr_assert_eq(c.getPower(), 65);
}
