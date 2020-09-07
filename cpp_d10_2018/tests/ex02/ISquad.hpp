/*
** EPITECH PROJECT, 2019
** ISquad.hpp
** File description:
** ISquad header
*/

#ifndef ISQUAD_HPP_
#define ISQUAD_HPP_

#include "ISpaceMarine.hpp"

class ISquad
{
public:
    virtual ~ISquad() {}
    virtual int getCount() const = 0;
    virtual ISpaceMarine* getUnit(int) = 0;
    virtual int push(ISpaceMarine *) = 0;
};

#endif /* !ISQUAD_HPP_ */
