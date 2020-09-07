/*
** EPITECH PROJECT, 2019
** Droid.cpp
** File description:
** droid methods
*/

#include "Droid.hpp"

// Ctor / Dtor
Droid::Droid() : Droid("") {}
Droid::Droid(const Droid &cpy) : _id(cpy.getId()), _energy(cpy.getEnergy()),
_attack(cpy.getAttack()), _toughness(cpy.getToughness())
{
    this->_status = new std::string("");
    *this->_status = *cpy.getStatus();
    std::cout << "Droid '" << this->_id << "' Activated, " <<
    "Memory Dumped" << std::endl;
}
Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25),
_toughness(15), _status(new std::string("Standing by"))
{
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}
Droid::~Droid()
{
    delete this->_status;
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

// Member methods
void Droid::operator=(const Droid &droid)
{
    this->_energy = droid.getEnergy();
    if (this->_status)
        delete this->_status;
    this->_status = new std::string("");
    *this->_status = *droid.getStatus();
    this->_id = droid.getId();
}

bool Droid::operator==(const Droid &droid) const
{
    if (*(droid.getStatus()) == *(this->_status) &&
    droid.getAttack() == this->_attack &&
    droid.getToughness() == this->_toughness &&
    droid.getId() == this->_id &&
    droid.getEnergy() == this->_energy)
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &droid) const
{
    if (droid.getId() != this->_id ||
    droid.getAttack() != this->_attack ||
    droid.getToughness() != this->_toughness ||
    droid.getEnergy() != this->_energy ||
    *droid.getStatus() != *this->_status)
        return (true);
    return (false);
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t energy_needed = 100 - this->_energy;

    if (energy_needed >= energy)
        this->_energy += energy;
    else
        this->_energy = 100;
    energy = this->_energy == 100 ? energy - energy_needed : 0;
    return (*this);
}

// Getters
std::string Droid::getId() const
{
    return this->_id;
}

std::string Droid::getSerial() const
{
    return this->_id;
}

size_t Droid::getEnergy() const
{
    return this->_energy;
}

size_t Droid::getAttack() const
{
    return this->_attack;
}

size_t Droid::getToughness() const
{
    return this->_toughness;
}

std::string *Droid::getStatus() const
{
    return this->_status;
}

// Setters

void Droid::setId(std::string id)
{
    this->_id = id;
}


void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        this->_energy = 100;
    else
        this->_energy = energy;
}

void Droid::setStatus(std::string *status)
{
    if (this->_status)
        delete this->_status;
    this->_status = status;
}

std::ostream &operator<<(std::ostream &stream, const Droid &droid)
{
    stream << "Droid '" << droid.getId() << "', "
    << *droid.getStatus() << ", " << droid.getEnergy();
    return stream;
}
