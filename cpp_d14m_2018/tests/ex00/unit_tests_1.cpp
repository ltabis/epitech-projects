/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "FruitBox.hpp"
#include "Banana.hpp"
#include "Lemon.hpp"

Test(ex00, fruits)
{
    Fruit f1;
    Lemon f2;
    Banana f3;

    cr_assert_eq(f1.getVitamins(), 0);
    cr_assert_eq(f1.getName(), "");
    cr_assert_eq(f2.getVitamins(), 3);
    cr_assert_eq(f2.getName(), "lemon");
    cr_assert_eq(f3.getVitamins(), 5);
    cr_assert_eq(f3.getName(), "banana");
}

Test(ex00, fruitBox)
{
    Lemon f2;
    Banana f3;
    FruitBox box(2);

    cr_assert_eq(box.nbFruits(), 0);
    cr_assert_eq(box.putFruit(&f2), true);
    cr_assert_eq(box.nbFruits(), 1);
    Fruit *f1 = box.pickFruit();
    cr_assert_eq(box.nbFruits(), 0);
    cr_assert_eq(f1->getVitamins(), 3);
}