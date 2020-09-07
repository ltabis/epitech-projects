/*
** EPITECH PROJECT, 2019
** OR.hpp
** File description:
** OR class
*/

#ifndef OR_HPP
#define OR_HPP

#include "CompProperties.hpp"

namespace nts {
    class OR : public CompProperties {
    public:
        OR(std::string);
        void dump() const final;
        nts::Tristate compute(std::size_t);
    };
}

#endif /* !OR_HPP */
