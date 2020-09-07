/*
** EPITECH PROJECT, 2019
** FruitNode.hpp
** File description:
** FruitNode class
*/

#ifndef FRUITNODE_HPP
#define FRUITNODE_HPP

#include "Fruit.hpp"

struct FruitNode
{
public:
    FruitNode() : _next(nullptr), _fruit(nullptr) {};
    ~FruitNode() {};

    FruitNode *getNext() const { return _next; };
    Fruit *getFruit() const { return _fruit; };
    void setFruit(const Fruit *fruit) { _fruit = (Fruit *)fruit; };
    void setNext(FruitNode *next) { _next = next; };

private:
    FruitNode *_next;
    Fruit *_fruit;
};

#endif /* !FRUITNODE_HPP */
