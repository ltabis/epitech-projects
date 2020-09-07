/*
** EPITECH PROJECT, 2019
** TacticalMarine.hpp
** File description:
** TacticalMarine header
*/

#ifndef TACTICALMARINE_HPP_
#define TACTICALMARINE_HPP_

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
    TacticalMarine();
    ~TacticalMarine();

    ISpaceMarine* clone() const override;
    void battleCry() const override;
    void rangedAttack() const override;
    void meleeAttack() const override;
};

#endif /* !TACTICALMARINE_HPP_ */
