/*
** EPITECH PROJECT, 2019
** Sorcerer.cpp
** File description:
** Sorcerer
*/

#include "Peon.hpp"

Peon::Peon(const std::string &name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}
Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a pink pony!" << std ::endl;
}
