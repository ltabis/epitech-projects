/*
** EPITECH PROJECT, 2019
** AEnemy.cpp
** File description:
** 
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) :
_hp(hp), _type(type) {}

AEnemy::~AEnemy() {}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    this->_hp -= damage;
}

const std::string &AEnemy::getType() const
{
    return this->_type;
}

int AEnemy::getHP() const
{
    return this->_hp;
}

void AEnemy::setHp(const int _hp)
{
    this->_hp = _hp;
}
