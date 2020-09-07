/*
** EPITECH PROJECT, 2019
** FruitBox.hpp
** File description:
** FruitBox class
*/

#ifndef FRUITBOX_HPP
#define FRUITBOX_HPP

#include "FruitNode.hpp"

class FruitBox
{
public:
    FruitBox(int);
    ~FruitBox();

    int nbFruits();
    bool putFruit(Fruit *f);
    Fruit *pickFruit();
    FruitNode *head();

private:
    int _size;
    FruitNode *_fruitList;
};

#endif /* !FRUITBOX_HPP */
