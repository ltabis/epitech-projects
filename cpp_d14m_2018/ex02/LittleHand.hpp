/*
** EPITECH PROJECT, 2019
** LittleHand.hpp
** File description:
** LittleHand class
*/

#ifndef LITTLEHAND_HPP
#define LITTLEHAND_HPP

#include "FruitBox.hpp"
#include "Coconut.hpp"

class LittleHand
{
public:
    static void sortFruitBox(
            FruitBox &,
            FruitBox &,
            FruitBox &,
            FruitBox &);
    static FruitBox *const *organizeCoconut(Coconut const * const *);
    static unsigned int countCoconuts(Coconut const * const *);
};

#endif /* !LITTLEHAND_HPP */
