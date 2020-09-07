/*
** EPITECH PROJECT, 2019
** FruitNode.hpp
** File description:
** FruitNode class
*/

#ifndef FRUITNODE_HPP
#define FRUITNODE_HPP

#include "Fruit.hpp"

class FruitNode
{
public:
    FruitNode();
    ~FruitNode();
    FruitNode *getNext();
    Fruit *getFruit();
    void setFruit(Fruit *);
    void setNext(FruitNode *);

private:
    FruitNode *_next;
    Fruit *_fruit;
};

#endif /* !FRUITNODE_HPP */
