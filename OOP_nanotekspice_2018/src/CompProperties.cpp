/*
** EPITECH PROJECT, 2019
** CompProperties.hpp
** File description:
** CompProperties class
*/

#include "CompProperties.hpp"

CompProperties::CompProperties(const std::string &name) : _name(name) {}

nts::Tristate CompProperties::compute(std::size_t pin)
{
    (void)pin;
//    if (_pins.at(pin).getRef(pin) == std::out_of_range)
//        return nts::Tristate::FALSE;
    return nts::Tristate::TRUE;
}

void CompProperties::setLink(
        std::size_t pin,
        nts::IComponent &other,
        std::size_t otherPin)
{
    if (_pins.find(pin) == _pins.end()) {
        std::cerr << "Error:" << _name << " doesn't have a pin numbered " << pin << std::endl;
        exit(84);
    }
    _pins.at(pin).setLink(pin, otherPin);
    _pins.at(pin).setRef(pin, other);
}

/*
 * Get all pins status
 */

void CompProperties::dump() const
{
    std::cout << "Dumping memory ..." << std::endl;
}