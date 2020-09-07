/*
** EPITECH PROJECT, 2019
** IComponent.hpp
** File description:
** IComponent class
*/

#ifndef IComponent_HPP
#define IComponent_HPP

#include <map>
#include <string>
#include <iostream>
#include <unordered_map>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
    public:
        virtual ~IComponent() = default;
    public:
        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::
        size_t otherPin) = 0;
        virtual std::string getType() const = 0;
        virtual std::string getName() const = 0;
        virtual void dump() const = 0; // dump tous les états
    };
}

#endif /* !IComponent_HPP */