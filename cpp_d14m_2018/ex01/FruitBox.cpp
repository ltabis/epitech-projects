/*
** EPITECH PROJECT, 2019
** FruitBox.cpp
** File description:
** FruitBox methods
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size), _fruitList(nullptr) {}
FruitBox::~FruitBox()
{
    FruitNode *tmp = _fruitList && _fruitList->getNext() ? _fruitList->getNext() : _fruitList;
    FruitNode *prev = _fruitList;

    if (this->nbFruits() == 1) {
        delete tmp;
        return;
    }
    for (; tmp && tmp->getNext(); tmp = tmp->getNext()) {
        delete prev;
        prev = tmp;
    }
    delete tmp;
}


int FruitBox::nbFruits()
{
    int fruits = _fruitList ? 1 : 0;
    FruitNode *tmp = _fruitList;

    for (; tmp && tmp->getNext(); fruits++, tmp = tmp->getNext());
    return fruits;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *tmp = _fruitList;
    FruitNode *elem = nullptr;
    int size = 0;

    for (; tmp && tmp->getNext(); tmp = tmp->getNext(), size++)
        if (tmp->getFruit() == f)
            return false;
    if (!tmp && size < _size) {
        _fruitList = new FruitNode;
        _fruitList->setFruit(f);
        return true;
    } else if (tmp->getFruit() != f && size < _size) {
        elem = new FruitNode;
        elem->setFruit(f);
        tmp->setNext(elem);
    }
    return tmp->getFruit() != f && size < _size;
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *head = _fruitList;
    Fruit *fruit = nullptr;

    if (this->nbFruits() == 0)
        return nullptr;
    if (head->getNext()) {
        _fruitList = _fruitList->getNext();
        fruit = head->getFruit();
        delete head;
        return fruit;
    }
    fruit = head->getFruit();
    //delete head;
    _fruitList = nullptr;
    return fruit;
}

FruitNode *FruitBox::head()
{
    return _fruitList;
}