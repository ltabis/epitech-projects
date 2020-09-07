/*
** EPITECH PROJECT, 2019
** ComplexComProperties.hpp
** File description:
** ComplexComProperties class
*/

#ifndef ComplexComProperties_HPP
#define ComplexComProperties_HPP

#include "IComponent.hpp"

namespace nts {
    class ComplexComProperties : public nts::IComponent {
    public:
        explicit ComplexComProperties(const std::string &);

//        nts::Tristate compute(std::size_t pin = 1);
//        void setLink(std::size_t, nts::IComponent &, std::size_t);
//        void dump() const;

    protected:
        std::unordered_map<int, nts::IComponent *> _elements;
        std::string _name;
    };
}

#endif /* !ComplexComProperties_HPP */
