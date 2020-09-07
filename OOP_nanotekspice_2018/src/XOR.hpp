/*
** EPITECH PROJECT, 2019
** XOR.hpp
** File description:
** XOR class
*/

#ifndef XOR_HPP
#define XOR_HPP

#include "CompProperties.hpp"
namespace nts {
    class XOR : public CompProperties {
    public:
        explicit XOR(std::string);
        nts::Tristate compute(std::size_t);
        void dump() const;
    };
}


#endif /* !XOR_HPP */
