/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** Character methods
*/

#include "Paladin.hpp"

// Ctor / Dtor
Paladin::Paladin(const std::string &name, int level) :
Character(name, level), Warrior(name, level), Priest(name, level)
{
    std::cout << "the light falls on "<< this->getName() << std::endl;
    this->_race = "Human";
    this->_class = "Paladin";
    this->_strength = 9;
    this->_stamina = 10;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;
}
Paladin::~Paladin() {}
