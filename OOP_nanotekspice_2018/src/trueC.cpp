/*
** EPITECH PROJECT, 2019
** trueC.hpp
** File description:
** trueC class
*/

#include "trueC.hpp"

nts::trueC::trueC(std::string name) : CompProperties(name)
{
    _pins.emplace(1, nts::Pin("1", nts::OUTPUT));
    _pins.at(1).setState(nts::Tristate::TRUE);
    _type = "true";
}

nts::Tristate nts::trueC::compute(std::size_t pin)
{
    return pin != 1 ? nts::Tristate::UNDEFINED : nts::Tristate::TRUE;
}

void nts::trueC::dump() const
{
    std::cout << _name << ", pin n°" << _pins.at(1).getName() << " = " << _pins.at(1).getStatus() << std::endl;
}