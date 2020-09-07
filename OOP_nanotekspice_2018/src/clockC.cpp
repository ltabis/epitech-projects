/*
** EPITECH PROJECT, 2019
** input.hpp
** File description:
** input class
*/

#include "clockC.hpp"

nts::clockC::clockC(std::string name) : CompProperties(name)
{
    _pins.emplace(1, nts::Pin("1", nts::OUTPUT));
    _type = "input";
}

nts::Tristate nts::clockC::compute(std::size_t pin)
{
    nts::Tristate tmp;

    if (pin != 1) {
        pin == 2 ? _pins.at(1).setState(FALSE) : _pins.at(1).setState(TRUE);
        return _pins.at(1).getStatus();
    }
    tmp = _pins.at(1).getStatus();
    _pins.at(1).setState(tmp == FALSE ? TRUE : FALSE);
    return tmp;
}

void nts::clockC::dump() const
{
    std::cout << _name << ", pin n°" << _pins.at(1).getName() << " = " << _pins.at(1).getStatus() << std::endl;
}