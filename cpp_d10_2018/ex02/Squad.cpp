/*
** EPITECH PROJECT, 2019
** ISquad.hpp
** File description:
** ISquad header
*/

#include "Squad.hpp"

Squad::Squad() : ISquad() {}
Squad::~Squad()
{
    for (unsigned int i = 0; i < _squad.size(); i++)
        delete _squad.at(i);
}

int Squad::getCount() const
{
    return _squad.size();
}

ISpaceMarine* Squad::getUnit(int unit)
{
    if ((int)_squad.size() <= unit)
        return (nullptr);
    return (_squad.at(unit));
}

int Squad::push(ISpaceMarine *soldier)
{
    int i =_squad.size();

    if (soldier) {
        _squad.push_back(soldier);
        i++;
    }
    return i;
}