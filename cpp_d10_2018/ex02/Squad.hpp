/*
** EPITECH PROJECT, 2019
** ISquad.hpp
** File description:
** ISquad header
*/

#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include "ISquad.hpp"
#include <vector>

class Squad : public ISquad
{
public:
    Squad();
    ~Squad();

    int getCount() const;
    ISpaceMarine* getUnit(int);
    int push(ISpaceMarine *);

private:
    std::vector <ISpaceMarine *> _squad;
};

#endif /* !SQUAD_HPP_ */
