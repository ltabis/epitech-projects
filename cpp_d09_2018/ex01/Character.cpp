/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** Character methods
*/

#include "Character.hpp"

// Ctor / Dtor
Character::Character(const std::string &name, int level) :
Range(Character::CLOSE), _name(name), _level(level), _pv(100), _pe(100),
_race("Koala"), _class("Character"), _strength(5), _stamina(5),
_intelligence(5), _spirit(5), _agility(5)
{
    std::cout << this->_name << " Created" << std::endl;
}
Character::~Character() {}

// Getters
const std::string &Character::getName() const
{
    return this->_name;
}
int Character::getLvl() const
{
    return this->_level;
}
int Character::getPv() const
{
    return this->_pv;
}
int Character::getPower() const
{
    return this->_pe;
}

int Character::getStrength() const
{
    return this->_strength;
}

int Character::getStamina() const
{
    return this->_stamina;
}

int Character::getIntelligence() const
{
    return this->_intelligence;
}

int Character::getSpirit() const
{
    return this->_spirit;
}

int Character::getAgility() const
{
    return this->_agility;
}

std::string Character::getRace() const
{
    return this->_race;
}

std::string Character::getClass() const
{
    return this->_class;
}

void Character::setRace(std::string &race)
{
    this->_race = race;
}

int Character::CloseAttack()
{
    if (checkEnergy(10) == false || this->Range == RANGE)
        return (0);
    std::cout << this->_name << " strikes with a wooden stick"
    << std::endl;
    return 10 + this->_strength;
}

void Character::Heal()
{
    std::cout << this->_name << " takes a potion" << std::endl;
    this->_pv += 50;
    if (this->_pv > 100)
        this->_pv = 100;
}

int Character::RangeAttack()
{
    if (checkEnergy(10) == false || this->Range == CLOSE)
        return (0);
    std::cout << this->_name << " tosses a stone" << std::endl;
    return 5 + this->_strength;
}

void Character::RestorePower()
{
    std::cout << this->_name << " eats" << std::endl;
    this->_pe = 100;
}

bool Character::checkEnergy(const int energy)
{
    if (this->_pe < energy)
        std::cout << this->_name << " out of power" << std::endl;
    else
        this->_pe -= energy;
    return (this->_pe >= energy ? true : false);
}

void Character::TakeDamage(int damage)
{
    if (damage < 0)
        return;
    this->_pv -= damage;
    if (this->_pv > 0) {
        std::cout << this->_name << " takes " <<
        damage << " damage" << std::endl;
    } else
        std::cout << this->_name << " out of combat" << std::endl;
}
