/*
** EPITECH PROJECT, 2019
** unit_tests_1.cpp
** File description:
** battery
*/

#include <criterion/criterion.h>
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

Test(ex02, Squad)
{
    std::unique_ptr<ISquad> vlc(new Squad);

    cr_assert_eq(vlc->getCount(), 0);
}

Test(ex02, marines)
{
    std::unique_ptr<ISquad> vlc(new Squad);

    cr_assert_eq(vlc->getCount(), 0);
    vlc->push(new TacticalMarine);
    vlc->push(new AssaultTerminator);
    cr_assert_eq(vlc->getCount(), 2);
}


Test(ex02, marines_clone)
{
    std::unique_ptr<ISquad> vlc(new Squad);

    cr_assert_eq(vlc->getCount(), 0);
    vlc->push(new TacticalMarine);
    vlc->push(new AssaultTerminator);
    cr_assert_eq(vlc->getCount(), 2);

    ISpaceMarine *tac1 = vlc->getUnit(0)->clone();
    ISpaceMarine *tac2 = vlc->getUnit(1)->clone();

    cr_assert_neq(tac1, nullptr);
    cr_assert_neq(tac2, nullptr);
}
