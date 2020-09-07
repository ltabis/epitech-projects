/*
** EPITECH PROJECT, 2019
** Droid.cpp
** File description:
** droid methods
*/

#include "DroidMemory.hpp"

// Ctor / Dtor
DroidMemory::DroidMemory() : _fingerPrint(random()), _exp(0){}
DroidMemory::~DroidMemory() {}

// Member methods

DroidMemory &DroidMemory::operator<<(const DroidMemory &mem)
{
    this->_exp += mem.getExp();
    this->_fingerPrint = mem.getFingerPrint() ^ this->_fingerPrint;
    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &mem)
{
    mem.setExp(mem.getExp() + this->_exp);
    mem.setFingerPrint(this->_fingerPrint ^ mem.getFingerPrint());
    return (*this);
}

DroidMemory &DroidMemory::operator+=(DroidMemory &mem)
{
    return (operator<<(mem));
}

DroidMemory &DroidMemory::operator+=(const size_t exp)
{
    this->_exp += exp;
    this->_fingerPrint ^= exp;
    return (*this);
}

DroidMemory DroidMemory::operator+(const DroidMemory &mem) const
{
    DroidMemory new_mem;

    new_mem.setExp(this->_exp + mem.getExp());
    new_mem.setFingerPrint(this->_fingerPrint ^ mem.getExp());
    return (new_mem);
}

DroidMemory DroidMemory::operator+(const size_t exp) const
{
    DroidMemory mem;

    mem.setExp(this->_exp + exp);
    mem.setFingerPrint(this->_fingerPrint ^ exp);
    return (mem);
}

// Getters
size_t DroidMemory::getFingerPrint() const
{
    return (this->_fingerPrint);
}
size_t DroidMemory::getExp() const
{
    return (this->_exp);
}

// Setters
void DroidMemory::setFingerPrint(const size_t fp)
{
    this->_fingerPrint = fp;
}

void DroidMemory::setExp(const size_t exp)
{
    this->_exp = exp;
}
