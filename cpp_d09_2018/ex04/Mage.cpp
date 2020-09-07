/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** Character methods
*/

#include "Mage.hpp"

// Ctor / Dtor
Mage::Mage(const std::string &name, int level) :
Character(name, level)
{
    std::cout << this->getName() <<
    " teleported" << std::endl;
    this->_race ="Gnome";
    this->_class = "Mage";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
}
Mage::~Mage() {}

int Mage::CloseAttack()
{
    if (checkEnergy(10) == false || this->Range == RANGE)
        return (0);
    std::cout << this->getName() << " blinks" << std::endl;
    this->Range = RANGE;
    return this->RangeAttack();
}

int Mage::RangeAttack()
{
    if (checkEnergy(25) == false || this->Range == CLOSE)
        return (0);
    std::cout << this->getName() << " launches a fire ball" << std::endl;
    return 20 + this->_spirit;
}

void Mage::RestorePower()
{
    if (50 + this->getPower() + this->getIntelligence() > 100)
        this->setPower(100);
    else
        this->setPower(50 + this->getPower() + this->getIntelligence());
    std::cout << this->getName() << " takes a mana potion" << std::endl;
}
