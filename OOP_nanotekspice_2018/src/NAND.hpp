/*
** EPITECH PROJECT, 2019
** NAND.hpp
** File description:
** NAND class
*/

#ifndef NAND_HPP
#define NAND_HPP

#include "CompProperties.hpp"
namespace nts {
    class NAND : public CompProperties {
    public:
        explicit NAND(std::string);
        void dump() const final;
        nts::Tristate compute(std::size_t) final;
    };
}

#endif /* !NAND_HPP */
