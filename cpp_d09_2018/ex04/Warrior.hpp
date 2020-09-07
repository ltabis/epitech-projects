/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** Character header
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : public virtual Character
{
public:
    Warrior(const std::string &, int);
    ~Warrior();

    const std::string &getWeaponName() const;

    int CloseAttack();
    virtual int RangeAttack();
protected:
    const std::string _weaponName;
    bool _asRanged;
};
#endif /* !WARRIOR_HPP_ */
