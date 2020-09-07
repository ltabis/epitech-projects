/*
** EPITECH PROJECT, 2019
** Skat.cpp
** File description:
** skat
*/

#include "Skat.hpp"

Skat::Skat() : Skat("bob", 15) {}
Skat::Skat(const std::string &name, int stimPaks) :
_name(name), _stimPaks(stimPaks) {}
Skat::~Skat() {}

int &Skat::stimPaks()
{
    return (_stimPaks);
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > this->_stimPaks)
        std::cout << "Don't be greedy" << std::endl;
    else {
        stock += number;
        this->_stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks == 0)
        std::cout << "Mediiiiiic" << std::endl;
    else {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        this->_stimPaks--;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " <<
    this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}
