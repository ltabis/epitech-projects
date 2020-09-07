/*
** EPITECH PROJECT, 2019
** LittleHand.cpp
** File description:
** LittleHand methods
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted,
                  FruitBox &lemons,
                  FruitBox &bananas,
                  FruitBox &limes)
{
    while (unsorted.nbFruits() != 0) {
        Fruit *p = unsorted.pickFruit();
        if (p->getName() == "lemon")
            lemons.putFruit(p);
        else if (p->getName() == "banana")
            bananas.putFruit(p);
        else if (p->getName() == "lime")
            limes.putFruit(p);
    }
}

unsigned int LittleHand::countCoconuts(Coconut const * const *coconuts)
{
    unsigned int i = 0;

    if (!coconuts)
        return 0;
    for (; coconuts[i]; i++);
    return i;
}

FruitBox *const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
    unsigned int len = countCoconuts(coconuts);
    FruitBox **pack = nullptr;

    if (!coconuts)
        return nullptr;
    printf("size = %d\n", len / 4);
    pack = new FruitBox *[(len / 4) + 1];
    for (unsigned int i = 0, total = 0; i < len / 4; i++) {
        pack[i] = new FruitBox(6);
        for (unsigned int j = 0; j < 6 && total < len; j++, total++) {
            pack[i]->putFruit(coconuts[total]);
        }
    }
    pack[len / 4] = nullptr;
    return pack;
}