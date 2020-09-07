/*
** EPITECH PROJECT, 2019
** falseC.hpp
** File description:
** falseC class
*/

#include "falseC.hpp"

nts::falseC::falseC(std::string name) : CompProperties(name)
{
    _pins.emplace(1, nts::Pin("1", nts::OUTPUT));
    _pins.at(1).setState(nts::Tristate::FALSE);
    _type = "false";
}

nts::Tristate nts::falseC::compute(std::size_t pin)
{
    return pin != 1 ? nts::Tristate::UNDEFINED : nts::Tristate::FALSE;
}

void nts::falseC::dump() const
{
    std::cout << _name << ", pin n°" << _pins.at(1).getName() << " = " << _pins.at(1).getStatus() << std::endl;
}