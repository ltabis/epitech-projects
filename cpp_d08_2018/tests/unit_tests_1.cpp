/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "Droid.hpp"

Test(ex00, droid_cpy)
{
    Droid d;
    Droid d1("Avenger");

    d = d1;
    cr_assert_eq(d.getId(), "Avenger");
    cr_assert_eq(d.getAttack(), 25);
    cr_assert_eq(d.getToughness(), 15);
    cr_assert_eq(d1.getId(), "Avenger");
    cr_assert_eq(d1.getAttack(), 25);
    cr_assert_eq(d1.getToughness(), 15);
}

Test(ex00, droid_const_cpy)
{
    Droid d;
    const Droid d1("Avenger");

    d = d1;
    cr_assert_eq(d.getId(), "Avenger");
    cr_assert_eq(d.getAttack(), 25);
    cr_assert_eq(d.getToughness(), 15);
    cr_assert_eq(d1.getId(), "Avenger");
    cr_assert_eq(d1.getAttack(), 25);
    cr_assert_eq(d1.getToughness(), 15);
}

Test(ex00, droid_default)
{
    Droid d;

    cr_assert_eq(d.getId(), "");
    cr_assert_eq(d.getAttack(), 25);
    cr_assert_eq(d.getToughness(), 15);
}

Test(ex00, droid_battery)
{
    Droid d("OMEGA");
    size_t Durasel = 25;

    d << Durasel;
    std::cout << "durasel = " << Durasel << std::endl;
    cr_assert_eq(d.getId(), "OMEGA");
    cr_assert_eq(d.getAttack(), 25);
    cr_assert_eq(d.getToughness(), 15);
    cr_assert_eq(d.getEnergy(), 75);
    cr_assert_eq(Durasel, 0);
}

Test(ex00, droid_battery_max)
{
    Droid d("OMEGA");
    size_t Durasel = 200;

    d << Durasel;
    cr_assert_eq(d.getId(), "OMEGA");
    cr_assert_eq(d.getAttack(), 25);
    cr_assert_eq(d.getToughness(), 15);
    cr_assert_eq(d.getEnergy(), 100);
    cr_assert_eq(Durasel, 150);
}

Test(ex00, droid_battery_chained_triple)
{
    Droid d1("OMEGA");
    Droid d2("mdr");
    size_t Durasel1 = 20;
    size_t Durasel2 = 20;

    d1 << Durasel1 << Durasel2;
    cr_assert_eq(d1.getId(), "OMEGA");
    cr_assert_eq(d1.getAttack(), 25);
    cr_assert_eq(d1.getToughness(), 15);
    cr_assert_eq(d1.getEnergy(), 90);
    cr_assert_eq(d2.getId(), "mdr");
    cr_assert_eq(d2.getAttack(), 25);
    cr_assert_eq(d2.getToughness(), 15);
    cr_assert_eq(d2.getEnergy(), 50);
    cr_assert_eq(Durasel1, 0);
    cr_assert_eq(Durasel2, 0);
}

Test(ex00, droid_comparison)
{
    Droid d1("OMEGA");
    Droid d2;

    d2 = d1;
    cr_assert_eq(d1.getId(), "OMEGA");
    cr_assert_eq(d1.getAttack(), 25);
    cr_assert_eq(d1.getToughness(), 15);
    cr_assert_eq(d1.getEnergy(), 50);
    cr_assert_eq(d2.getId(), "OMEGA");
    cr_assert_eq(d2.getAttack(), 25);
    cr_assert_eq(d2.getToughness(), 15);
    cr_assert_eq(d2.getEnergy(), 50);
    cr_assert_eq(d1 == d2, 1);
    d1.setId("new");
    cr_assert_eq(d1 != d2, 1);
    cr_assert_eq(d1 == d2, 0);
}
