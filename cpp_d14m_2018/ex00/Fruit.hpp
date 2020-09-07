/*
** EPITECH PROJECT, 2019
** Fruit.hpp
** File description:
** Fruit class
*/


#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <string>
#include <iostream>

class Fruit
{
public:
    // Ctor / Dtor
    Fruit();
    Fruit(const int vitamins, const std::string &name);

    int getVitamins() const;
    std::string getName() const;

protected:
    const int _vitamins;
    const std::string _name;
};

#endif /* !FRUIT_HPP */
