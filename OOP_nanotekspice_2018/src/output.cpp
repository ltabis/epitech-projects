/*
** EPITECH PROJECT, 2019
** output.hpp
** File description:
** output class
*/

#include "output.hpp"

nts::output::output(std::string name) : CompProperties(name)
{
    _pins.emplace(1, nts::Pin("1", nts::INPUT));
    _type = "output";
}

nts::Tristate nts::output::compute(std::size_t pin)
{
    nts::Tristate state;
    std::string toDisplay;

    if (pin == 3) {
        toDisplay = _pins.at(1).getStatus() == UNDEFINED ? "U" : (_pins.at(1).getStatus() ? "1" : "0");
        std::cout << _name << "=" << toDisplay << std::endl;
        return _pins.at(1).getStatus();
    }
    if (_pins.at(1).getRef().find(1) == _pins.at(1).getRef().end()) {
        std::cerr << "Error: " << _name << " isn't linked to anything." << std::endl;
        exit(84);
    }
    state = _pins.at(1).getRef().at(1).compute(_pins.at(1).getLink().at(1));
    toDisplay = state == UNDEFINED ? "U" : (state == TRUE ? "1" : "0");
    if (pin == 1)
        std::cout << _name << "=" << toDisplay << std::endl;
    _pins.at(1).setState(state);
    return state;
}

void nts::output::dump() const
{
    std::cout << _name << ", pin n°" << _pins.at(1).getName() << " = " << _pins.at(1).getStatus() << std::endl;
}