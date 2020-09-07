/*
** EPITECH PROJECT, 2019
** NAND.hpp
** File description:
** NAND class
*/

#include "NAND.hpp"

nts::NAND::NAND(std::string name) : CompProperties(name)
{
    _pins.emplace(1, nts::Pin("1", nts::INPUT));
    _pins.emplace(2, nts::Pin("2", nts::INPUT));
    _pins.emplace(3, nts::Pin("3", nts::OUTPUT));
    _pins.emplace(4, nts::Pin("4", nts::OUTPUT));
    _pins.emplace(5, nts::Pin("5", nts::INPUT));
    _pins.emplace(6, nts::Pin("6", nts::INPUT));
    _pins.emplace(8, nts::Pin("8", nts::INPUT));
    _pins.emplace(9, nts::Pin("9", nts::INPUT));
    _pins.emplace(10, nts::Pin("10", nts::OUTPUT));
    _pins.emplace(11, nts::Pin("11", nts::OUTPUT));
    _pins.emplace(12, nts::Pin("12", nts::INPUT));
    _pins.emplace(13, nts::Pin("13", nts::INPUT));
}

nts::Tristate nts::NAND::compute(std::size_t pin)
{
    if (pin == 3) {
        if (_pins.at(1).getRef().find(1) == _pins.at(1).getRef().end() ||
            _pins.at(2).getRef().find(2) == _pins.at(2).getRef().end()) {
            std::cerr << "Error: " << _name << "'s pin " << pin << " isn't linked with anything." << std::endl;
            exit(84);
        }
        nts::Tristate a = _pins.at(1).getRef().at(1).compute();
        nts::Tristate b = _pins.at(2).getRef().at(2).compute();
        return a == UNDEFINED || b == UNDEFINED ? UNDEFINED : (a == 1 && b == 1 ? FALSE : TRUE);
    }
    if (pin == 4) {
        if (_pins.at(5).getRef().find(5) == _pins.at(5).getRef().end() ||
            _pins.at(6).getRef().find(6) == _pins.at(6).getRef().end()) {
            std::cerr << "Error: " << _name << "'s pin " << pin << " isn't linked with anything." << std::endl;
            exit(84);
        }
        nts::Tristate a = _pins.at(5).getRef().at(5).compute();
        nts::Tristate b = _pins.at(6).getRef().at(6).compute();
        return a == UNDEFINED || b == UNDEFINED ? UNDEFINED : (a == 1 && b == 1 ? FALSE : TRUE);
    }
    if (pin == 10) {
        if (_pins.at(8).getRef().find(8) == _pins.at(8).getRef().end() ||
            _pins.at(9).getRef().find(9) == _pins.at(9).getRef().end()) {
            std::cerr << "Error: " << _name << "'s pin " << pin << " isn't linked with anything." << std::endl;
            exit(84);
        }
        nts::Tristate a = _pins.at(8).getRef().at(8).compute();
        nts::Tristate b = _pins.at(9).getRef().at(9).compute();
        return a == UNDEFINED || b == UNDEFINED ? UNDEFINED : (a == 1 && b == 1 ? FALSE : TRUE);
    }
    if (pin == 11) {
        if (_pins.at(12).getRef().find(12) == _pins.at(12).getRef().end() ||
            _pins.at(13).getRef().find(13) == _pins.at(13).getRef().end()) {
            std::cerr << "Error: " << _name << "'s pin " << pin << " isn't linked with anything." << std::endl;
            exit(84);
        }
        nts::Tristate a = _pins.at(12).getRef().at(12).compute();
        nts::Tristate b = _pins.at(13).getRef().at(13).compute();
        return a == UNDEFINED || b == UNDEFINED ? UNDEFINED : (a == 1 && b == 1 ? FALSE : TRUE);
    }
    return nts::Tristate::UNDEFINED;
}

void nts::NAND::dump() const
{
    std::cout << _pins.at(2).getStatus() << std::endl;
    std::cout << _pins.at(3).getStatus() << std::endl;
    std::cout << _pins.at(10).getStatus() << std::endl;
    std::cout << _pins.at(11).getStatus() << std::endl;
}