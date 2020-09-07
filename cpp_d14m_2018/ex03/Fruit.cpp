/*
** EPITECH PROJECT, 2019
** Fruit.cpp
** File description:
** Fruit methods
*/

#include "Fruit.hpp"

Fruit::Fruit() : _vitamins(0), _name("") {}
Fruit::Fruit(const int vitamins, const std::string &name) :
        _vitamins(vitamins), _name(name) {}


int Fruit::getVitamins() const
{
    return _vitamins;
}

std::string Fruit::getName() const
{
    return _name;
}