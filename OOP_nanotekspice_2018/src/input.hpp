/*
** EPITECH PROJECT, 2019
** input.hpp
** File description:
** input class
*/

#ifndef input_HPP
#define input_HPP

#include "CompProperties.hpp"

namespace nts {
    class input : public CompProperties {
    public:
        explicit input(std::string);
        void dump() const final;
        nts::Tristate compute(std::size_t);
    };
}


#endif /* !input_HPP */
