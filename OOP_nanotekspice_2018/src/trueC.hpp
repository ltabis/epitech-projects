/*
** EPITECH PROJECT, 2019
** trueC.hpp
** File description:
** trueC class
*/

#ifndef trueC_HPP
#define trueC_HPP

#include "CompProperties.hpp"

namespace nts {
    class trueC : public CompProperties {
    public:
        explicit trueC(std::string);

        nts::Tristate compute(std::size_t) final;
        void dump() const final;
    };
}

#endif /* !trueC_HPP */
