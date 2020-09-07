/*
** EPITECH PROJECT, 2019
** Federation.cpp
** File description:
** fed cpp file
*/

#include "Borg.hpp"

Borg::Ship::Ship() : _side(300), _maxWarp(9), _home(UNICOMPLEX), _location(_home)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves"
              << " unconditionally." << std::endl
              << "Your biological characteristics and technologies will be "
              << "assimilated." << std::endl
              << "Resistance is futile." << std::endl;
}
Borg::Ship::~Ship() {}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    if (!this->_core)
        return;
    if (this->_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move()
{
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (this->_core->checkReactor()->isStable() && d != _location) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    if (this->_core->checkReactor()->isStable() && warp <= this->_maxWarp) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (this->_core->checkReactor()->isStable() &&
    warp <= this->_maxWarp && d != this->_location) {
        this->_location = d;
        return (true);
    }
    return (false);
}
