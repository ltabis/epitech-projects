/*
** EPITECH PROJECT, 2019
** AWeapon.cpp
** File description:
** 
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
: _name(name), _ap(apcost), _dmg(damage) {}

AWeapon::~AWeapon() {}

const std::string &AWeapon::getName() const
{
    return this->_name;
}

int AWeapon::getAPCost() const
{
    return this->_ap;
}

int AWeapon::getDamage() const
{
    return this->_dmg;
}
