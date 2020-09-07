/*
** EPITECH PROJECT, 2019
** Pin.hpp
** File description:
** Pin class
*/

#include "Pin.hpp"

nts::Pin::Pin(std::string name, Type type) : _state(nts::UNDEFINED), _type(type), _name(name) {}

std::unordered_map<std::size_t, std::size_t> nts::Pin::getLink()
{
    return _link;
}

std::unordered_map<std::size_t, nts::IComponent &> nts::Pin::getRef()
{
    return _ref;
}

void nts::Pin::setLink(std::size_t pin, std::size_t otherPin)
{
    _link.emplace(pin, otherPin);
}

void nts::Pin::setRef(std::size_t pin, nts::IComponent &other)
{
    _ref.emplace(pin, other);
}