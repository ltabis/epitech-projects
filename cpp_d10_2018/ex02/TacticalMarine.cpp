/*
** EPITECH PROJECT, 2019
** ISquad.hpp
** File description:
** ISquad header
*/

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() : ISpaceMarine()
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
    std::cout << "Aaargh..." << std::endl;
}

ISpaceMarine* TacticalMarine::clone() const
{
    return new TacticalMarine(*this);
}
void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}
void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
}
void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}