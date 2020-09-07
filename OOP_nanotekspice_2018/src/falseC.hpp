/*
** EPITECH PROJECT, 2019
** falseC.hpp
** File description:
** falseC class
*/

#ifndef falseC_HPP
#define falseC_HPP

#include "CompProperties.hpp"

namespace nts {
    class falseC : public CompProperties {
    public:
        falseC(std::string);

        nts::Tristate compute(std::size_t) final;
        void dump() const final;
    };
}

#endif /* !falseC_HPP */
