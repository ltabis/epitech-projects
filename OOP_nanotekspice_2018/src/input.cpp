/*
** EPITECH PROJECT, 2019
** input.hpp
** File description:
** input class
*/

#include "input.hpp"

nts::input::input(std::string name) : CompProperties(name)
{
    _pins.emplace(1, nts::Pin("1", nts::OUTPUT));
    _type = "input";
}

nts::Tristate nts::input::compute(std::size_t pin)
{
    if (pin != 1)
        pin == 2 ? _pins.at(1).setState(FALSE) : _pins.at(1).setState(TRUE);
    return _pins.at(1).getStatus();
}

void nts::input::dump() const
{
    std::cout << _name << ", pin n°" << _pins.at(1).getName() << " = " << _pins.at(1).getStatus() << std::endl;
}