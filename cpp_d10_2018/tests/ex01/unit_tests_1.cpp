/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

Test(ex01, Mutant)
{
    SuperMutant c;

    cr_assert_eq(c.getType(), "Super Mutant");
    cr_assert_eq(c.getHP(), 170);
}

Test(ex01, RadScorpion)
{
    RadScorpion c;

    cr_assert_eq(c.getType(), "RadScorpion");
    cr_assert_eq(c.getHP(), 80);
}

Test(ex01, Character)
{
    Character c("Aventurier");

    cr_assert_eq(c.getName(), "Aventurier");
    cr_assert_eq(c.getWeaponName(), "");
}

Test(ex01, maintest)
{
    const auto preda = new Character("Predator");
    const auto prey = new RadScorpion();
    std::cout<< *preda;
    AWeapon *pr(new PlasmaRifle());
    AWeapon *pf(new PowerFist());
    preda->equip(pr);
    cr_assert_eq(preda->getWeaponName(), "Plasma Rifle");
    std::cout << *preda;
    preda->equip(pf);
    cr_assert_eq(preda->getWeaponName(), "Power Fist");
    preda->attack(prey);
    std::cout << *preda;
    preda->equip(pr);
    std::cout << *preda;
    preda->attack(prey);
    cr_assert_eq(prey->getHP(), 9);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
}