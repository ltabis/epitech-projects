/*
** EPITECH PROJECT, 2019
** TacticalMarine.hpp
** File description:
** TacticalMarine header
*/

#ifndef ASSAULTTERMINATOR_HPP_
#define ASSAULTTERMINATOR_HPP_

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator();
    ~AssaultTerminator();

    ISpaceMarine* clone() const override;
    void battleCry() const override;
    void rangedAttack() const override;
    void meleeAttack() const override;
};

#endif /* !ASSAULTTERMINATOR_HPP_ */
