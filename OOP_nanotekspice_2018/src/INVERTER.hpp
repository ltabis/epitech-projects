/*
** EPITECH PROJECT, 2019
** INVERTER.hpp
** File description:
** INVERTER class
*/

#ifndef INVERTER_HPP
#define INVERTER_HPP

#include "CompProperties.hpp"
namespace nts {
    class INVERTER : public CompProperties {
    public:
        INVERTER(std::string);
        nts::Tristate compute(std::size_t);
        void dump() const;
    };
}

#endif /* !INVERTER_HPP */
