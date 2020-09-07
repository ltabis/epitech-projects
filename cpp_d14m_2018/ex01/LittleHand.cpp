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