/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "Character.hpp"

Character::Character(const std::string &name) :
        _name(name), _ap(40), _curWeapon(NULL)
{

}
Character::~Character() {}

void Character::recoverAP()
{
    this->_ap += this->_ap > 40 ? 0 : 10;
}

void Character::equip(AWeapon *weapon)
{
    if (!weapon)
        return;
    this->_curWeapon = weapon;
}

bool Character::checkAp()
{
    this->_ap -= this->_curWeapon->getAPCost();
    if (this->_ap < 0) {
        this->_ap = 0;
        return (false);
    }
    return (true);
}

void Character::attack(AEnemy *enemy)
{
    if (!enemy || !this->_curWeapon || !this->checkAp())
        return;
    std::cout << this->getName() << " attacks " << enemy->getType()
            << " with a " << this->_curWeapon->getName() << std::endl;
    enemy->setHp(enemy->getHP() - this->_curWeapon->getDamage());
    this->_curWeapon->attack();
    if (enemy->getHP() <= 0)
        delete enemy;
}

const std::string &Character::getName() const
{
    return this->_name;
}

std::string Character::getWeaponName() const
{
    if (!this->_curWeapon)
        return ("");
    return this->_curWeapon->getName();
}

std::ostream &operator<<(std::ostream &os, const Character &character)
{
    if (character._curWeapon)
        os << character._name << " has " << character._ap << " AP and wields a " << character.getWeaponName() << std::endl;
    else
        os << character._name << " has " << character._ap << " and is  unarmed" << std::endl;
    return os;
}
