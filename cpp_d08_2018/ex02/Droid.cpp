/*
** EPITECH PROJECT, 2019
** Droid.cpp
** File description:
** droid methods
*/

#include "Droid.hpp"

// Ctor / Dtor
Droid::Droid(const Droid &cpy) : _id(cpy.getId()), _energy(50),
_attack(cpy.getAttack()), _toughness(cpy.getToughness())
{
    this->_status = new std::string("");
    *this->_status = *cpy.getStatus();
    this->_battleData = new DroidMemory;
    this->_battleData->setFingerPrint(cpy.getBattleData()->getFingerPrint());
    this->_battleData->setExp(cpy.getBattleData()->getExp());
    std::cout << "Droid '" << this->_id << "' Activated, " <<
    "Memory Dumped" << std::endl;
}
Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25),
_toughness(15), _status(new std::string("Standing by")),
_battleData(new DroidMemory)
{
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}
Droid::~Droid()
{
    delete this->_status;
    delete this->_battleData;
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

// Member methods
void Droid::operator=(const Droid &droid)
{
    if (this->_status)
        delete this->_status;
    this->_status = new std::string("");
    *this->_status = *droid.getStatus();
    this->_id = droid.getId();
}

bool Droid::operator==(const Droid &droid) const
{
    if (*(droid.getStatus()) == *(this->_status))
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &droid) const
{
    if (*droid.getStatus() != *this->_status)
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

bool Droid::operator()(std::string *task, size_t expReq)
{
    if (this->_energy <= 10) {
        this->_energy = 0;
        delete this->_status;
        this->_status = new std::string("Battery Low");
        delete task;
        return (false);
    } else if (this->_battleData->getExp() >= expReq) {
        this->_energy -= 10;
        delete this->_status;
        this->_status = new std::string(task->c_str());
        *this->_status += " - Completed!";
        this->_battleData->setExp(this->_battleData->getExp() + (expReq / 2));
        delete task;
        return (true);
    }
    delete this->_status;
    this->_energy -= 10;
    this->_battleData->setExp(this->_battleData->getExp() + expReq);
    this->_status = new std::string(task->c_str());
    *this->_status += " - Failed!";
    delete task;
    return (false);
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

DroidMemory *Droid::getBattleData() const
{
    return this->_battleData;
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

void Droid::setBattleData(DroidMemory *battleData)
{
    this->_battleData = battleData;
}

std::ostream &operator<<(std::ostream &stream, const Droid &droid)
{
    stream << "Droid '" << droid.getId() << "', "
    << *droid.getStatus() << ", " << droid.getEnergy();
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const DroidMemory &mem)
{
    stream << "DroidMemory '" << mem.getFingerPrint() << "', "
    << mem.getExp();
    return stream;
}
