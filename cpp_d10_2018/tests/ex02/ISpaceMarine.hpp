/*
** EPITECH PROJECT, 2019
** ISquad.hpp
** File description:
** ISquad header
*/

#ifndef ISPACEMARINE_HPP_
#define ISPACEMARINE_HPP_

#include <string>
#include <iostream>

class ISpaceMarine
{
public:
    virtual ~ISpaceMarine() { }
    virtual ISpaceMarine* clone() const = 0;
    virtual void battleCry() const = 0;
    virtual void rangedAttack() const = 0;
    virtual void meleeAttack() const = 0;
};

#endif /* !ISPACEMARINE_HPP_ */
