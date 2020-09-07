/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** Character methods
*/

#include "Priest.hpp"

// Ctor / Dtor
Priest::Priest(const std::string &name, int level) :
Mage(name, level)
{
    std::cout << this->getName() <<
    " enters in the order" << std::endl;
    this->_race = "Orc";
    this->_class = "Priest";
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
}
Priest::~Priest() {}

int Priest::RangeAttack()
{
    if (checkEnergy(25) == false || this->Range == CLOSE)
        return (0);
    std::cout << this->getName() << " launches a fire ball" << std::endl;
    return 20 + this->_spirit;
}

void Priest::Heal()
{
    if (checkEnergy(10) == false)
        return;
    std::cout << this->getName() << " casts a little heal spell" << std::endl;
    this->setPv(this->getPv() + 70);
    if (this->getPv() > 100)
        this->setPv(100);
}
