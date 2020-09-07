/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** Character header
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest
{
public:
    Paladin(const std::string &, int);
    ~Paladin();

    using Warrior::CloseAttack;
    using Priest::RangeAttack;
    using Priest::Heal;
private:
};
#endif /* !PALADIN_HPP_ */
