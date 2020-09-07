/*
** EPITECH PROJECT, 2019
** NOR.hpp
** File description:
** NOR class
*/

#ifndef NOR_HPP
#define NOR_HPP

#include "CompProperties.hpp"

namespace nts {
    class NOR : public CompProperties {
    public:
        explicit NOR(std::string);
        nts::Tristate compute(std::size_t) final;
        void dump() const final;
    private:
    };
}

#endif /* !NOR_HPP */
