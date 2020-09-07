/*
** EPITECH PROJECT, 2019
** output.hpp
** File description:
** output class
*/

#ifndef output_HPP
#define output_HPP

#include "CompProperties.hpp"

namespace nts {
    class output : public CompProperties {
    public:
        explicit output(std::string);

        nts::Tristate compute(std::size_t) final;
        void dump() const final;
    };
}

#endif /* !output_HPP */
