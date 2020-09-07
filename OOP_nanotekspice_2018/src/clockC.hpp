/*
** EPITECH PROJECT, 2019
** input.hpp
** File description:
** input class
*/

#ifndef clock_HPP
#define clock_HPP

#include "CompProperties.hpp"

namespace nts {
    class clockC : public CompProperties {
    public:
        explicit clockC(std::string);
        void dump() const final;
        nts::Tristate compute(std::size_t) final;
    };
}


#endif /* !clock_HPP */
