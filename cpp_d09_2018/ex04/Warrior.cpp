/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** Character methods
*/

#include "Warrior.hpp"

// Ctor / Dtor
Warrior::Warrior(const std::string &name, int level) :
Character(name, level), _weaponName("hammer"), _asRanged(false)
{
    std::cout << "I'm "<< this->getName() <<
    " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
    this->_race ="Dwarf";
    this->_class = "Warrior";
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
}
Warrior::~Warrior() {}

const std::string &Warrior::getWeaponName() const
{
    return (this->_weaponName);
}

int Warrior::CloseAttack()
{
    if (checkEnergy(30) == false || this->Range == RANGE)
        return (0);
    std::cout << this->getName() << " strikes with his " << this->_weaponName
    << std::endl;
    return 20 + this->_strength;
}

int Warrior::RangeAttack()
{
    if (_asRanged == false) {
        if (checkEnergy(10) == false || this->Range == CLOSE)
            return (0);
        std::cout << this->getName() << " intercepts" << std::endl;
        this->_asRanged = true;
    }
    this->Range = Character::CLOSE;
    return 0;
}
