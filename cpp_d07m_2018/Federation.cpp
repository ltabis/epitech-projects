/*
** EPITECH PROJECT, 2019
** Federation.cpp
** File description:
** fed cpp file
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp), _home(EARTH), _location(_home)
{
    std::cout << "The ship USS " << this->_name << " has been finished."
    << std::endl << "It is "
    << this->_length << " m in length and " << this->_width << " m in width."
    << std::endl << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}
Federation::Ship::Ship(int length, int width, std::string name) :
    _length(length), _width(width), _name(name), _maxWarp(1), _home(VULCAN), _location(_home)
{
    std::cout << "The independant ship " << this->_name << " just finished its construction."
    << std::endl << "It is "
    << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}
Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}
Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0) {}
Federation::Starfleet::Captain::~Captain() {}
Federation::Starfleet::Ship::~Ship() {}
Federation::Starfleet::Ensign::~Ensign() {}
Federation::Ship::~Ship() {}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    if (!captain)
        return;
    this->_captain = captain;
    std::cout << this->_captain->getName() << ": I'm glad to be the captain"
              << " of the USS " << this->_name << "." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    if (!core)
        return;
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (!this->_core)
        return;
    std::cout << "USS " << this->_name << ": The core is " <<
    (this->_core->checkReactor()->isStable() ? "stable" : "unstable")
    << " at the time."<< std::endl;
}

bool Federation::Starfleet::Ship::move()
{
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (this->_core->checkReactor()->isStable() && d != _location) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (this->_core->checkReactor()->isStable() && warp <= this->_maxWarp) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (this->_core->checkReactor()->isStable() &&
    warp <= this->_maxWarp && d != this->_location) {
        this->_location = d;
        return (true);
    }
           return (false);
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (!this->_core)
        return;
    std::cout << this->_name << ": The core is " <<
    (this->_core->checkReactor()->isStable() ? "stable" : "unstable")
    << " at the time."<< std::endl;
}

bool Federation::Ship::move()
{
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    if (this->_core->checkReactor()->isStable() && d != _location) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    if (this->_core->checkReactor()->isStable() && warp <= this->_maxWarp) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (this->_core->checkReactor()->isStable() &&
    warp <= this->_maxWarp && d != this->_location) {
        this->_location = d;
        return (true);
    }
           return (false);
}
