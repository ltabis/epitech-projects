/*
** EPITECH PROJECT, 2019
** Sorcerer.cpp
** File description:
** Sorcerer
*/

#include "Victim.hpp"

Victim::Victim(const std::string &name) : _name(name)
{
    std::cout << "Some random victim called " << this->_name
              << " just popped!" << std::endl;
}
Victim::~Victim()
{
    std::cout << "Victim " << this->_name
              << " just died for no apparent reason!" << std::endl;
}

// Getters
const std::string Victim::getName() const
{
    return this->_name;
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep!" << std ::endl;
}

std::ostream &operator<<(std::ostream &stream, const Victim &obj)
{
    stream << "I'm " << obj.getName() << " and i like otters!" << std::endl;
    return stream;
}