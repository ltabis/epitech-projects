/*
** EPITECH PROJECT, 2019
** Sorcerer.cpp
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title) :
_name(name), _title(title)
{
    std::cout << this->_name << ", " << this->_title
              << ", is born!" << std::endl;
}
Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title
              << ", is dead. Consequences will never be the same!" << std::endl;
}

// Getters
const std::string Sorcerer::getName() const
{
    return this->_name;
}

const std::string Sorcerer::getTitle() const
{
    return this->_title;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &stream, const Sorcerer &obj)
{
    stream << "I am " << obj.getName() << ", " << obj.getTitle() << ", and I like ponies!" << std::endl;
    return stream;
}