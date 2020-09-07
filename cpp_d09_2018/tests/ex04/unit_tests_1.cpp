/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Character.hpp"

Test(ex04, getters)
{
        Character c("Elian", 0);

        cr_assert_eq(c.getName(), "Elian");
        cr_assert_eq(c.getLvl(), 0);
        cr_assert_eq(c.getPv(), 100);
        cr_assert_eq(c.getPower(), 100);
        cr_assert_eq(c.getStrength(), 5);
        cr_assert_eq(c.getStamina(), 5);
        cr_assert_eq(c.getIntelligence(), 5);
        cr_assert_eq(c.getSpirit(), 5);
        cr_assert_eq(c.getAgility(), 5);
}

Test(ex04, attack_plus_exhausted)
{
        Character c("Elian", 10);

        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 15);
        cr_assert_eq(c.CloseAttack(), 0);
}

Test(ex04, restore_power)
{
        Character c("Elian", 10);

        cr_assert_eq(c.CloseAttack(), 15);
        c.RestorePower();
        cr_assert_eq(c.getPower(), 100);
}

Test(ex04, take_damage_plus_death)
{
        Character c("Elian", 10);

        c.TakeDamage(15);
        cr_assert_eq(c.getPv(), 85);
        c.TakeDamage(200);
        cr_assert_eq(c.getPv(), -115);
}
